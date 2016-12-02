std = function(X) {
	X = X - mean(X);
	X = X / sd(X);
	# X = X / norm(X, '2');
	return(X);
}

calc_err = function(X, Y, beta) {
	return(norm(Y - X %*% beta) ^ 2);
}