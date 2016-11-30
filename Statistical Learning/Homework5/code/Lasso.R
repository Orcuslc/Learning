Lasso = function(X, Y, gamma, epsilon = 1e-2) {
	# The Lasso Regression;
	# Using Pathwise Coordinate Optimization;
	Y = Y - mean(Y); # Standardize Y;
	X = apply(X, 2, sub); # Standardize each col of X, formula (1.1);
	p = ncol(X);
	beta_0 = solve(t(X) %*% X) %*% t(X) %*% Y;	# The overall least square estimation;
	print(beta_0)
	beta = beta_0;
	while(1) {
		for(j in 1:p) {
			beta[j] = lasso_solution(X, Y, beta, gamma, j);
		}
		if(norm(beta_0 - beta) <= epsilon) {
			break;
		}
		beta_0 = beta;
	}
	return(beta);
}

lasso_solution = function(X, Y, beta, gamma, j) {
	# The function to get lasso solution from the least square estimation, 
	# with a single predictor;
	# formula (8, 9)
	tmp = beta[j] + sum(X[, j]*(Y - X %*% beta));
	if(gamma >= abs(tmp)) {
		return(0);
	}
	else{
		if(tmp > 0) {
			return(tmp - gamma);
		}		
		else{
			return(tmp + gamma);
		}
	}
}

sub = function(X) {
	X = X - mean(X);
	X = X / norm(X, type = '2');
	return(X);
}