mergeInto(LibraryManager.library, {
	changeIcon: function(iconSrc) {
		var newlink = document.createElement('link');
		var oldlink = document.querySelector('#dynamic-favicon');
		newlink.id = 'dynamic-favicon';
		newlink.rel = 'shortcut icon';
		newlink.href = iconSrc;
		if (oldlink) {
				document.head.removeChild(oldlink);
		}
		document.head.appendChild(newlink);
	},

	changeUrl: function(state, urlSuffix) {
		window.history.replaceState(state, state, "#" + urlSuffix);
	},

	changeTitle: function(title) {
		document.title = title;
	},
});