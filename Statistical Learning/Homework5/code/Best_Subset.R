source('std.R')

Best_Subset = function(X, Y, k) {
	Y = Y - mean(Y); # Standardize Y;
	X = apply(X, 2, std); # Standardize each col of X, formula (1.1);
	n = nrow(X);
	p = ncol(X);
	num = 2 ^ p - 2;
	subset = matrix(rep(0, p*num), nrow = p); # Each column saves a conbination of subset;
	beta_0 = solve(t(X) %*% X) %*% t(X) %*% Y; # Beta of Whole LR.
	error = rep(0, num);
	index = 0;
	for(i in 1:k) {
		subset_i = combn(1:p, i);
		index = index + choose(p, i-1);
		for(j in 1:choose(p, i)) {
			beta_j = matrix(rep(0, p), ncol = 1);
			index_j = index+j-1;
			subset_ij = subset_i[, j];
			subset[1:i, index_j] = subset_ij;
			X_subset = X[, subset_ij];
			beta = solve(t(X_subset) %*% X_subset) %*% t(X_subset) %*% Y;
			beta_j[subset_ij, ] = beta;
			error[index_j] = norm(beta_j - beta_0);
		}
	}
	print(which(error == min(error)))
	best_subset = subset[, which(error == min(error))];
	bs = best_subset[which(best_subset != 0)];
	X_bs = X[, bs];
	beta = solve(t(X_bs) %*% X_bs) %*% t(X_bs) %*% Y;
	return(list(bs = bs, beta = beta));
}


