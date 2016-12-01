source('std.R')

Ridge = function(X, Y, begin = 1e-8, end = 1, step = 1e-2, epsilon = 1e-6) {
	beta_0 = solve(t(X) %*% X) %*% t(X) %*% Y;
	Y = Y - mean(Y);
	X = apply(X, 2, std);
	for(lambda in seq(begin, end, step)) {
		beta = Ridge_regression(X, Y, lambda);
		# beta = solve(t(X)%*%X+lambda*diag(rep(1, ncol(X)))) %*% t(X) %*% Y;
		if(norm(beta - beta_0) < epsilon) {
			break
		}
		beta_0 = beta;
	}
	# print(lambda)
	return(beta);
}

Ridge_regression = function(X, Y, lambda) {
	# Use SVD to compute Ridge regression
	return(solve(t(X)%*%X+lambda*diag(rep(1, ncol(X)))) %*% t(X) %*% Y);
}