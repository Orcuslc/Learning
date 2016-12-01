source('std.R')

PCR = function(X, Y, k) {
	# Principle Component Regression
	Y = Y - mean(Y);
	X = apply(X, 2, std);
	n = nrow(X);
	p = ncol(X);

	Z = svd(X, nu = n);
	P = Z$v[, 1:k];
	T = as.matrix(Z$u[, 1:k], nrow = n) %*% as.matrix(diag(Z$d[1:k], nrow = k, ncol = k));
	C = solve(t(T) %*% T) %*% t(T) %*% Y;
	return(list(C = C, P = P, beta = P %*% C));
}

PCR_predict = function(X, P, C) {
	# Use trained model to predict
	return(X %*% P %*% C);
}