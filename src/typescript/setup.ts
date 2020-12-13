let statusElement: HTMLDivElement = <HTMLDivElement>document.getElementById('status');
let progressElement: HTMLProgressElement = <HTMLProgressElement>document.getElementById('progress');
let spinnerElement = document.getElementById('spinner');
let canvasElement: HTMLCanvasElement = <HTMLCanvasElement>document.getElementById('canvas');

let Module = {
    preRun: [],
    postRun: [],
	
    print: function(text: string) {
        if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');
        console.log(text);
    },
	
    printErr: function(text: string) {
        if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');
        console.error(text);
    },
	
    canvas: function() {
        var canvas = document.getElementById('canvas');

        // As a default initial behavior, pop up an alert when webgl context is lost. To make your
        // application robust, you may want to override this behavior before shipping!
        // See http://www.khronos.org/registry/webgl/specs/latest/1.0/#5.15.2
        canvas.addEventListener("webglcontextlost", function(e) {
            alert('WebGL context lost. You will need to reload the page.');
            e.preventDefault();
        }, false);

        return canvas;
    },
	
    setStatus: function(text) {
		let bypass: any = Module.setStatus;
        if (!bypass.last) bypass.last = {
            time: Date.now(),
            text: ''
        };
        if (text === bypass.last.text) return;
        var m = text.match(/([^(]+)\((\d+(\.\d+)?)\/(\d+)\)/);
        var now = Date.now();
        if (m && now - bypass.last.time < 30) return; // if this is a progress update, skip it if too soon
        bypass.last.time = now;
        bypass.last.text = text;
        if (m) {
            text = m[1];
            progressElement.value = parseInt(m[2]) * 100;
            progressElement.max = parseInt(m[4]) * 100;
            progressElement.hidden = false;
            spinnerElement.hidden = false;
        } else {
            progressElement.value = null;
            progressElement.max = null;
            progressElement.hidden = true;
            if (!text) spinnerElement.hidden = true;
        }
        statusElement.innerHTML = text;
    },
	
    totalDependencies: 0,
    monitorRunDependencies: function(left) {
        this.totalDependencies = Math.max(this.totalDependencies, left);
        Module.setStatus(left ? 'Preparing... (' + (this.totalDependencies - left) + '/' + this.totalDependencies + ')' : 'All downloads complete.');
        if (!left) {
            canvasElement.style.display = 'block';
			canvasElement.style.width = '100vw';
			canvasElement.style.height = '100vh';
        }
    }
};

Module.setStatus('Downloading...');
window.onerror = function() {
    Module.setStatus('Exception thrown, see JavaScript console');
    spinnerElement.style.display = 'none';
    Module.setStatus = function(text) {
        if (text) Module.printErr('[post-exception status] ' + text);
    };
};

let keysHeld = '';

window.addEventListener("keydown",
    function(e){
		if (keysHeld.indexOf(e.key.toLowerCase() + ',') < 0) {
			keysHeld = keysHeld.concat(e.key.toLowerCase() + ',');
		}
		console.log(keysHeld);
    },
false);

window.addEventListener('keyup',
    function(e){
		keysHeld = keysHeld.replace(e.key.toLowerCase() + ',', '');
		console.log(keysHeld);
    },
false);