logit_pred = function(x, k, beta) {
	# Use the `beta` by logistic regression to do prediction
	x = cbind(1, x);
	p = exp(t(beta) %*% x);
	p[k] = 1;
	return(which(p == max(p)));
}

logit = function(x, g, k, error = 1e-6) {
	# Logistic Regression
	# x: training data
	# g: training type
	# k: the number of training types
	n = nrow(x);
	x = cbind(1, x);
	beta = matrix(rep(0, (n+1)*(k-1)), ncol = (k-1));
	y = matrix(rep(0, (k-1)*n), ncol = (k-1));
	for(i in 1:(k-1)) {
		y[which(y[, i]) == i, i] = 1;
	} # Construct the y matrix
	while(1) {
		c = construct(x, beta, k, n);
		W = c$W;
		X = c$X;
		p = c$p;
		beta_new = beta + solve(t(X) %*% W %*% X) %*% t(X) %*% (y-p);
		if(norm(beta_new - beta, "2") < error) {
			break;
		}
		beta = beta_new;
	}
	return(beta);
}

construct = function(x, beta, k, n) {
	# Construct the matrices for computation
	p = matrix(rep(0, (k-1)*n), ncol = (k-1));
	for(i in 1:(k-1)) {
		for(j in 1:n) {
			p[j, i] = pfunc(x, beta, j, i);
		}
	} # Construct the p matrix
	q = ncol(x);
	X = matrix(rep(0, n*(k-1)*(k-1)*q), nrow = n*(k-1));
	for(i in 1:(k-1)) {
		X[(n*(i-1)+1):(n*i), (q*(i-1)+1):(q*i)] = x;
	} # Construct the X matrix
	W = matrix(rep(0, n*(k-1)*n*(k-1)), nrow = n*(k-1));
	for(i in 1:(k-1)) {
		for(j in 1:(k-1)) {
			if(i == j) {
				W[(n*(i-1)+1):(n*i), (n*(i-1)+1):(n*i)] = diag(p[, i]*(1-p[, i]));
			}
			else {
				W[(n*(i-1)+1):(n*i), (n*(j-1)+1):(n*j)] = diag(-p[, i]*p[, j]);
			}
		}
	} # Construct the W matrix
	return(list(W = W, X = X, p = p));
}

pfunc = function(x, beta, i, k) {
	# Compute the probability
	total = 1 + sum(exp(t(beta) %*% x[i]));
	g = as.numeric(exp(t(as.matrix(beta[, k])) %*% x[i]));
	return(g/total);
}