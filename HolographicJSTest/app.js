console.log('Attempting to create holographic rendering context...');
try {
    function shaderProgram(gl, vs, fs) {
        var prog = gl.createProgram();
        var addshader = function (type, source) {
            var s = gl.createShader((type == 'vertex') ?
                gl.VERTEX_SHADER : gl.FRAGMENT_SHADER);
            gl.shaderSource(s, source);
            gl.compileShader(s);
            if (!gl.getShaderParameter(s, gl.COMPILE_STATUS)) {
                throw "Could not compile " + type +
                    " shader:\n\n" + gl.getShaderInfoLog(s);
            }
            gl.attachShader(prog, s);
        };
        addshader('vertex', vs);
        addshader('fragment', fs);
        gl.linkProgram(prog);
        if (!gl.getProgramParameter(prog, gl.LINK_STATUS)) {
            throw "Could not link the shader program!";
        }
        return prog;
    }

    function attributeSetFloats(gl, prog, attr_name, rsize, arr) {
        console.log('Attemping to bind buffer');
        gl.bindBuffer(gl.ARRAY_BUFFER, gl.createBuffer());
        console.log('Buffer bound');
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(arr),
            gl.STATIC_DRAW);
        var attr = gl.getAttribLocation(prog, attr_name);
        gl.enableVertexAttribArray(attr);
        gl.vertexAttribPointer(attr, rsize, gl.FLOAT, false, 0, 0);
    }

    function draw() {
        try {
            var gl = window.createCanvasRenderingContextHolographic();
            console.log(gl.test);
            if (!gl) { throw "x"; }
        } catch (err) {
            throw "Your web browser does not support WebGL!";
        }

        gl.clearColor(0.8, 0.8, 0.8, 1);
        gl.clear(gl.COLOR_BUFFER_BIT);

        var prog = shaderProgram(gl,
            "attribute vec3 pos;" +
            "void main() {" +
            "	gl_Position = vec4(pos, 2.0);" +
            "}",
            "void main() {" +
            "	gl_FragColor = vec4(0.5, 0.5, 1.0, 1.0);" +
            "}"
        );
        gl.useProgram(prog);

        console.log(`Using program ${prog}`);

        attributeSetFloats(gl, prog, "pos", 3, [
            -1, 0, 0,
            0, 1, 0,
            0, -1, 0,
            1, 0, 0
        ]);

        console.log('Drawing arrays');
        gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
        console.log('Arrays drawn');
    }

    function init() {
        try {
            draw();
        } catch (e) {
            console.log("Error: " + e);
        }
    }
    init();
} catch (e) {
    console.log(e.message);
}