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
	camera.position.z = 400;
	scene = new THREE.Scene();
	var geometry = new THREE.BoxBufferGeometry(200, 200, 200);
	var material = new THREE.MeshPhongMaterial();
	mesh = new THREE.Mesh(geometry, material);
	scene.add(mesh);
	renderer = new THREE.WebGLRenderer({
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