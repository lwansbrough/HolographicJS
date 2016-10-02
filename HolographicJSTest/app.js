function matrix4(
    m00, m01, m02, m03,
    m10, m11, m12, m13,
    m20, m21, m22, m23,
    m30, m31, m32, m33
) {
    return [
        [m00, m01, m02, m03],
        [m10, m11, m12, m13],
        [m20, m21, m22, m23],
        [m30, m31, m32, m33]
    ]
}


const vertexShaderSource = `
    uniform mat4 uModelMatrix;
    uniform mat4 uHolographicViewProjectionMatrix[2];
    attribute vec4 aPosition;
    attribute vec4 aColor;
    attribute float aRenderTargetArrayIndex;
    varying vec4 vColor;
    varying float vRenderTargetArrayIndex;
    void main() {
        int arrayIndex = int(aRenderTargetArrayIndex); // % 2; // TODO: integer modulus operation supported on ES 3.00 only
        gl_Position = uHolographicViewProjectionMatrix[arrayIndex]* uModelMatrix * aPosition;
        vColor = aColor;
        vRenderTargetArrayIndex = aRenderTargetArrayIndex;
    }
`;

const fragmentShaderSource = `
    precision mediump float;
    varying vec4 vColor;
    varying float vRenderTargetArrayIndex;
    void main() {
        gl_FragColor = vColor;
        float index = vRenderTargetArrayIndex;
    }
`;

const gl = new CanvasRenderingContextHolographic(holographicSpace, stationaryReferenceFrame);

try {
    function simpleModelMatrix(radians, position) {
        const cosine = Math.cos(radians);
        const sine = Math.sin(radians);

        return matrix4(
            cosine, 0., -sine, 0.,
            0., 1., 0., 0.,
            sine, 0., cosine, 0.,
            position[0], position[1], position[2], 1.
        );
    }

    function compileShader(type, source) {
        const shader = gl.createShader(type);
        gl.shaderSource(shader, source);
        gl.compileShader(shader);
        if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
            throw new Error('Could not compile shader.');
        }

        return shader;
    }

    function compileProgram(vertexShaderSource, fragmentShaderSource) {
        const program = gl.createProgram();
        if (program === 0) {
            throw new Error('Failed to create program');
        }

        console.log(`Vertex shader type: ${gl.VERTEX_SHADER}`);
        console.log(`Fragment shader type: ${gl.FRAGMENT_SHADER}`);

        const vertexShader = compileShader(gl.VERTEX_SHADER, vertexShaderSource);
        const fragmentShader = compileShader(gl.FRAGMENT_SHADER, fragmentShaderSource);

        console.log(`Vertex shader: ${vertexShader}`);
        console.log(`Fragment shader: ${fragmentShader}`);
        
        if (vertexShader === 0 || fragmentShader === 0) {
            gl.deleteShader(vertexShader);
            gl.deleteShader(fragmentShader);
            gl.deleteProgram(program);
            throw new Error('Failed to create either vertex shader or fragment shader or both');
        }

        gl.attachShader(program, vertexShader);
        gl.deleteShader(vertexShader);

        gl.attachShader(program, fragmentShader);
        gl.deleteShader(fragmentShader);

        console.log(`Linking program: ${program}`);
        gl.linkProgram(program);
        console.log(`Linked program ${program}`);

        if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
            throw new Error('Could not link the shader program: ' + gl.getProgramInfoLog(program));
        }

        return program;
    }

    const program = compileProgram(vertexShaderSource, fragmentShaderSource);

    console.log(`Program 1: ${program}`);

    const positionAttribLocation = gl.getAttribLocation(program, 'aPosition');
    const colorAttribLocation = gl.getAttribLocation(program, 'aColor');
    const rtvAttribLocation = gl.getAttribLocation(program, 'aRenderTargetArrayIndex');
    const modelUniformLocation = gl.getUniformLocation(program, 'uModelMatrix');
    const viewUniformLocation = gl.getUniformLocation(program, 'uViewMatrix');
    const projUniformLocation = gl.getUniformLocation(program, 'uProjMatrix');

    console.log(`aPosition ${positionAttribLocation}`);
    console.log(`aColor ${colorAttribLocation}`);
    console.log(`aRenderTargetArrayIndex ${rtvAttribLocation}`);
    console.log(`uModelMatrix ${modelUniformLocation}`);
    console.log(`uViewMatrix ${viewUniformLocation}`);
    console.log(`uProjMatrix ${projUniformLocation}`);

    const halfWidth = 0.1;
    const vertexPositions = Float32Array.from([
        -halfWidth, -halfWidth, -halfWidth,
        -halfWidth, -halfWidth,  halfWidth,
        -halfWidth,  halfWidth, -halfWidth,
        -halfWidth,  halfWidth,  halfWidth,
         halfWidth, -halfWidth, -halfWidth,
         halfWidth, -halfWidth,  halfWidth,
         halfWidth,  halfWidth, -halfWidth,
         halfWidth,  halfWidth,  halfWidth,
    ]);

    const vertexPositionBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, vertexPositionBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertexPositions, gl.STATIC_DRAW);

    const vertexColors = Float32Array.from([
        0., 0., 0.,
        0., 0., 1.,
        0., 1., 0.,
        0., 1., 1.,
        1., 0., 0.,
        1., 0., 1.,
        1., 1., 1.,
        1., 1., 1.
    ]);

    const vertexColorBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, vertexColorBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertexColors, gl.STATIC_DRAW);

    const indices = Int16Array.from([
        0, 1, 2,
        1, 3, 2,

        4, 6, 5,
        5, 6, 7,

        0, 5, 1,
        0, 4, 5,

        2, 7, 6,
        2, 3, 7,

        0, 6, 4,
        0, 2, 6,

        1, 7, 3,
        1, 5, 7
    ]);

    const indexBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, indices, gl.STATIC_DRAW);

    const renderTargetArrayIndices = Float32Array.from([0., 1.]);

    const renderTargetArrayIndexBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, renderTargetArrayIndexBuffer);
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, renderTargetArrayIndices, gl.STATIC_DRAW);

    let drawCount = 0;

    function draw() {
        gl.enable(gl.DEPTH_TEST);
        gl.clearColor(0., 0., 0., 0.);
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

        if (program === 0) return;

        console.log(`Program: ${program}`);
        gl.useProgram(program);

        gl.bindBuffer(gl.ARRAY_BUFFER, vertexPositionBuffer);
        gl.enableVertexAttribArray(positionAttribLocation);
        gl.vertexAttribPointer(positionAttribLocation, 3, gl.FLOAT, gl.FALSE, 0, 0);

        gl.bindBuffer(gl.ARRAY_BUFFER, vertexColorBuffer);
        gl.enableVertexAttribArray(colorAttribLocation);
        gl.vertexAttribPointer(colorAttribLocation, 3, gl.FLOAT, gl.FALSE, 0, 0);

        const position = [0., 0., -2.];
        const modelMatrix = simpleModelMatrix(drawCount / 50, position);
        gl.uniformMatrix4fv(modelUniformLocation, gl.FALSE, [modelMatrix[0][0]]);

        gl.bindBuffer(gl.ARRAY_BUFFER, renderTargetArrayIndexBuffer);
        gl.vertexAttribPointer(rtvAttribLocation, 1, gl.FLOAT, gl.FALSE, 0, 0);
        gl.enableVertexAttribArray(rtvAttribLocation);

        gl.vertexAttribDivisorANGLE(rtvAttribLocation, 1);

        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
        gl.drawElementsInstancedANGLE(gl.TRIANGLES, (6 * 2) * 3, gl.UNSIGNED_SHORT, 0, 2);

        drawCount += 1;
    }

    function animate() {
        draw();
        gl.render(animate);
    }

    animate();
} catch (e) {
    console.log(e.message);
}




//const renderingContext = new CanvasRenderingContextHolographic(holographicSpace, stationaryReferenceFrame);

//console.log('Rendering context created.');