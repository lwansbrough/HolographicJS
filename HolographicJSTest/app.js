console.log('Attempting to create holographic rendering context...');
const holographicContext = window.createCanvasRenderingContextHolographic();
holographicContext.deleteBuffer(123);
console.log('It worked!');