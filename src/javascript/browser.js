function changeIcon(iconSrc) {
	var newlink = document.createElement('link');
	var oldlink = document.querySelector('#dynamic-favicon');
	newlink.id = 'dynamic-favicon';
	newlink.rel = 'shortcut icon';
	newlink.href = iconSrc;
	if (oldlink) {
		document.head.removeChild(oldlink);
	}
	document.head.appendChild(newlink);
}

function changeUrl(state, urlSuffix) {
	window.history.replaceState(state, state, "#" + urlSuffix);
}

function changeTitle(title) {
	document.title = title;
}