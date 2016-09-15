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

const gl = window.createCanvasRenderingContextHolographic();

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
        if (!gl.getShaderParameter(shader, gl.compile_STATUS)) {
            throw new Error('Could not compile shader.');
        }

        return shader;
    }

    function compileProgram(vertexShaderSource, fragmentShaderSource) {
        const program = gl.createProgram();
        if (program === 0) {
            throw new Error('Failed to create program');
        }

        console.log(`Vertex shader type: ${gl.vertex_SHADER}`);
        console.log(`Fragment shader type: ${gl.fragment_SHADER}`);

        const vertexShader = compileShader(gl.vertex_SHADER, vertexShaderSource);
        const fragmentShader = compileShader(gl.fragment_SHADER, fragmentShaderSource);

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

        if (!gl.getProgramParameter(program, gl.link_STATUS)) {
            throw new Error('Could not link the shader program: ' + gl.getProgramLogInfo(program));
        }

        return program;
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
    const vertexPositions = [
        -halfWidth, -halfWidth, -halfWidth,
        -halfWidth, -halfWidth,  halfWidth,
        -halfWidth,  halfWidth, -halfWidth,
        -halfWidth,  halfWidth,  halfWidth,
         halfWidth, -halfWidth, -halfWidth,
         halfWidth, -halfWidth,  halfWidth,
         halfWidth,  halfWidth, -halfWidth,
         halfWidth,  halfWidth,  halfWidth,
    ];

    const vertexPositionBuffer = gl.createBuffer();
    gl.bindBuffer(gl.array_BUFFER, vertexPositionBuffer);
    gl.bufferData(gl.array_BUFFER, vertexPositions, gl.static_DRAW);

    const vertexColors = [
        0., 0., 0.,
        0., 0., 1.,
        0., 1., 0.,
        0., 1., 1.,
        1., 0., 0.,
        1., 0., 1.,
        1., 1., 1.,
        1., 1., 1.
    ];

    const vertexColorBuffer = gl.createBuffer();
    gl.bindBuffer(gl.array_BUFFER, vertexColorBuffer);
    gl.bufferData(gl.array_BUFFER, vertexColors, gl.static_DRAW);

    const indices = [
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
    ];

    const indexBuffer = gl.createBuffer();
    gl.bindBuffer(gl.element_ARRAY_BUFFER, indexBuffer);
    gl.bufferData(gl.element_ARRAY_BUFFER, indices, gl.static_DRAW);

    const renderTargetArrayIndices = [0., 1.];

    const renderTargetArrayBuffer = gl.createBuffer();
    gl.bindBuffer(gl.element_ARRAY_BUFFER, renderTargetArrayBuffer);
    gl.bufferData(gl.element_ARRAY_BUFFER, renderTargetArrayIndices, gl.static_DRAW);

    let drawCount = 0;

    function draw() {
        gl.enable(gl.depth_TEST);
        gl.clearColor(0., 0., 0., 0.);
        gl.clear(gl.color_BUFFER_BIT | gl.depth_BUFFER_BIT);

        if (program === 0) return

        console.log(`Program: ${program}`);
        gl.useProgram(program);

        gl.bindBuffer(gl.array_BUFFER, vertexPositionBuffer);
        gl.enableVertexAttribArray(positionAttribLocation);
        gl.vertexAttribPointer(positionAttribLocation, 3, gl.float, gl.false, 0, 0);

        gl.bindBuffer(gl.array_BUFFER, vertexColorBuffer);
        gl.enableVertexAttribArray(colorAttribLocation);
        gl.vertexAttribPointer(colorAttribLocation, 3, gl.float, gl.false, 0, 0);

        const position = [0., 0., -2.];
        const modelMatrix = simpleModelMatrix(drawCount / 50, position);
        gl.uniformMatrix4fv(modelUniformLocation, gl.false, [[modelMatrix[0][0]]]);

        gl.bindBuffer(gl.array_BUFFER, renderTargetArrayIndices);
        gl.vertexAttribPointer(rtvAttribLocation, 1, gl.float, gl.false, 0, 0);
        gl.enableVertexAttribArray(rtvAttribLocation);

        gl.vertexAttribDivisorANGLE(rtvAttribLocation, 1);

        gl.bindBuffer(gl.element_ARRAY_BUFFER, indexBuffer);
        gl.drawElementsInstancedANGLE(gl.triangles, (6 * 2) * 3, gl.unsigned_SHORT, 0, 2);

        drawCount += 1;
    }

    function animate() {
        draw();
        window.requestAnimationFrame(animate);
    }

    animate();
} catch (e) {
    console.log(e.message);
}

//console.log('Attempting to create holographic rendering context...');
//try {
//    function shaderProgram(gl, vs, fs) {
//        var prog = gl.createProgram();
//        var addshader = function (type, source) {
//            var s = gl.createShader((type == 'vertex') ?
//                gl.VERTEX_SHADER : gl.FRAGMENT_SHADER);
//            gl.shaderSource(s, source);
//            gl.compileShader(s);
//            if (!gl.getShaderParameter(s, gl.COMPILE_STATUS)) {
//                throw "Could not compile " + type +
//                    " shader:\n\n" + gl.getShaderInfoLog(s);
//            }
//            gl.attachShader(prog, s);
//        };
//        addshader(`vertex ${vs}`);
//        addshader('fragment', fs);
//        gl.linkProgram(prog);
//        if (!gl.getProgramParameter(prog, gl.LINK_STATUS)) {
//            throw "Could not link the shader program!";
//        }
//        return prog;
//    }

//    function attributeSetFloats(gl, prog, attr_name, rsize, arr) {
//        console.log('Attemping to bind buffer');
//        gl.bindBuffer(gl.ARRAY_BUFFER, gl.createBuffer());
//        console.log('Buffer bound');
//        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(arr),
//            gl.STATIC_DRAW);
//        var attr = gl.getAttribLocation(prog, attr_name);
//        gl.enableVertexAttribArray(attr);
//        gl.vertexAttribPointer(attr, rsize, gl.FLOAT, false, 0, 0);
//    }

//    function draw() {
//        try {
//            var gl = window.createCanvasRenderingContextHolographic();
//            if (!gl) { throw "x"; }
//        } catch (err) {
//            throw "Your web browser does not support WebGL!";
//        }

//        gl.clearColor(0.8, 0.8, 0.8, 1);
//        gl.clear(gl.COLOR_BUFFER_BIT);

//        var prog = shaderProgram(gl,
//            "attribute vec3 pos;" +
//            "void main() {" +
//            "	gl_Position = vec4(pos, 2.0);" +
//            "}",
//            "void main() {" +
//            "	gl_FragColor = vec4(0.5, 0.5, 1.0, 1.0);" +
//            "}"
//        );
//        gl.useProgram(prog);

//        console.log(`Using program ${prog}`);

//        attributeSetFloats(gl, prog, "pos", 3, [
//            -1, 0, 0,
//            0, 1, 0,
//            0, -1, 0,
//            1, 0, 0
//        ]);

//        console.log('Drawing arrays');
//        gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
//        console.log('Arrays drawn');
//    }

//    function init() {
//        try {
//            draw();
//        } catch (e) {
//            console.log("Error: " + e);
//        }
//    }
//    init();
//} catch (e) {
//    console.log(e.message);
//}