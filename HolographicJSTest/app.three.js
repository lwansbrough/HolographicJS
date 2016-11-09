const gl = new CanvasRenderingContextHolographic();

const canvasShim = {
	addEventListener: () => { }
};

var camera, scene, renderer;
var mesh;
init();
animate();
function init() {
    camera = new THREE.PerspectiveCamera(70, 1, 1, 1000);
    scene = new THREE.Scene();
    var geometry = new THREE.CubeGeometry(1, 1, 1);
    var material = new THREE.MeshNormalMaterial();
    mesh = new THREE.Mesh(geometry, material);
    scene.add(mesh);
    mesh.position.z = -2;
    renderer = new THREE.WebGLRenderer({
        holographic: true,
		canvas: canvasShim,
		context: gl
	});
}

function animate() {
	requestAnimationFrame(animate);
	mesh.rotation.x += 0.005;
	mesh.rotation.y += 0.01;
	renderer.render(scene, camera);
}