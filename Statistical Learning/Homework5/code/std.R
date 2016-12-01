std = function(X) {
	X = X - mean(X);
	X = X / sd(X);
	# X = X / norm(X, '2');
	return(X);
}