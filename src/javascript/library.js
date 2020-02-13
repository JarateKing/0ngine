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
	
	displayCopywrite: function() {
		let canvas = document.getElementById("canvas");
		let context = canvas.getContext("2d");
		
		canvas.width = canvas.offsetWidth;
		canvas.height = canvas.offsetHeight;
		
		context.fillStyle = 'grey';
		context.font = "12px Arial";
		context.fillText("Made with 0ngine", 5, 17);
	}
});