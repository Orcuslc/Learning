LR = function(X, Y) {
	# Linear Regression
	# X: The parameters
	# Y: The results
	beta = solve(t(X) %*% X) %*% t(X) %*% Y;
	return(beta);
}

inference_t = function(X, Y, beta, i = 1, beta_0 = 0, alpha = 0.05) {
    # Inference: t-statistics;
    # H0: beta[i] = beta_0;
    # Return: If accept H0, return True; else return False;
	N = nrow(X);
	p = ncol(X);
	M = solve(t(X) %*% X);
	Y_hat = X %*% beta;
	sigma = (sum((Y - Y_hat) ^ 2))/(N-p);
	v = diag(M);
	# z = (beta[i] - beta_0)/(sqrt(sigma*(1/N+(mean(X[, 2])^2)/(sum(X[, 2]^2)-N*mean(X[, 2])^2))))
	z = (beta[i] - beta_0)/(sqrt(sigma*v[i]));
	# print(z)
	return(abs(z) <= qt(1-alpha/2, N-p));
}

inference_F = function(X, Y, beta, i = c(1), alpha = 0.05) {
	# Inference: F-statistics;
	# H0: beta[i] = 0;
	# Return: If accept H0, return True; else return False;
	beta_r = beta;
	beta_r[i] = 0;
	N = nrow(X);
	p1 = ncol(X);
	p0 = length(i);
	F = ((-norm(Y-X%*%beta)^2+norm(Y-X%*%beta_r)^2)/p0)/(norm(Y - X %*% beta)^2/(N-p1));
	# print(F)
	return(F <= qf(1-alpha, p0, N-p1));
}


read = function(data_path) {
    data = read.csv(data_path);
    data = as.matrix(data)[, 2:ncol(data)];
    colnames(data) = NULL;
    X = data[, 1:ncol(data)-1];
    X = cbind(1, X);
    colnames(X) = NULL;
    Y = as.matrix(data[, ncol(data)]);
    return(list(X = X, Y = Y));
}

sub = function(X) {
	# Normalize(Centerlize) the matrix;
	ssub = function(X) {
		return(X - mean(X));
	}
	X = apply(X, 2, ssub);
}