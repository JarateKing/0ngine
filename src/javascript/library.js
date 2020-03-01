mergeInto(LibraryManager.library, {
	changeIcon: function(iconSrc) {
		let iconSrcStr = UTF8ToString(iconSrc);
		let newlink = document.createElement('link');
		let oldlink = document.querySelector('#dynamic-favicon');
		newlink.id = 'dynamic-favicon';
		newlink.rel = 'shortcut icon';
		newlink.href = iconSrcStr;
		
		if (oldlink)
			document.head.removeChild(oldlink);
		
		document.head.appendChild(newlink);
	},

	changeUrl: function(state, urlSuffix) {
		let stateStr = UTF8ToString(state);
		let suffixStr = UTF8ToString(urlSuffix);
		window.history.replaceState(stateStr, stateStr, "#" + suffixStr);
	},

	changeTitle: function(title) {
		let titleStr = UTF8ToString(title);
		document.title = titleStr;
	},
	
	openUrl: function(url, isNewTab) {
		let urlStr = UTF8ToString(url);
		
		if (isNewTab)
			window.open(urlStr, '_blank');
		else
			window.location.href = urlStr;
	},
	
	displayString: function(text, font, fontSize, color, xpos, ypos) {
		let textStr = UTF8ToString(text);
		let fontStr = UTF8ToString(font);
		let colorStr = UTF8ToString(color);
		
		context.fillStyle = colorStr;
		context.font = fontSize + "px " + fontStr;
		context.fillText(textStr, xpos, fontSize + ypos);
	},
	
	clearDisplay: function() {
		context.clearRect(0, 0, canvas.width, canvas.height);
		
		canvas.width = canvas.offsetWidth;
		canvas.height = canvas.offsetHeight;
	},
	
	getScreenX: function() {
		return canvas.width;
	},
	
	getScreenY: function() {
		return canvas.height;
	},
	
	getAspectRatio: function() {
		return (canvas.width / canvas.height);
	}
});