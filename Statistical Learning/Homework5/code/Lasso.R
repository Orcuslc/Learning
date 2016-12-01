source('std.R')

Lasso_shrinkage = function(X, Y, start = 0, end = 10, step = 1e-2, epsilon1 = 1e-2, epsilon2 = 1e-2) {
	beta_0 = solve(t(X) %*% X) %*% t(X) %*% Y;
	beta2 = c();
	count = 0;
	for(gamma in seq(start, end, step)) {
		beta = Lasso(X, Y, gamma, epsilon2)$beta;
		count = count + 1;
		beta2[count] = beta[2]
		# beta = solve(t(X)%*%X+lambda*diag(rep(1, ncol(X)))) %*% t(X) %*% Y;
	}
	plot(seq(start, end, step), beta2)
	return(list(beta = beta));
}	

Lasso = function(X, Y, gamma, epsilon = 1e-2) {
	# The Lasso Regression;
	# Using Pathwise Coordinate Optimization;
	Y = Y - mean(Y); # Standardize Y;
	X = apply(X, 2, std); # Standardize each col of X, formula (1.1);
	p = ncol(X);
	beta_0 = solve(t(X) %*% X) %*% t(X) %*% Y;	# The overall least square estimation;
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
	return(list(beta = beta));
}

lasso_solution = function(X, Y, beta, gamma, j) {
	# The function to get lasso solution from the least square estimation, 
	# with a single predictor;
	# formula (8, 9)

	# In order to get THE PICTURE WE HAVE TO CHANGE THE FORMULA.
	tmp = (beta[j] + sum(X[, j]*(Y - X %*% beta))/sum(X[, j]^2));
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