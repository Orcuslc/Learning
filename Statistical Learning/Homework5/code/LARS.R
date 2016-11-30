LARS = function(X, Y) {
	# Least Angle Regression
	Y = Y - mean(Y); # Standardize Y;
	X = apply(X, 2, normalize); # Standardize each col of X, formula (1.1);
	n = nrow(X); # Number of datapoints in X;
	p = ncol(X); # Number of parameters in X;
	mu = as.matrix(rep(0, n), ncol = 1); # The weight of each parameter;
	s = as.matrix(rep(0, p), nrow = 1); # The sign of each parameter;
	ord = c(); # The order of each parameter;

	for (index in 1:p) {
		C = t(X) %*% (Y - mu);	# formula (2.8)
		C[ord] = 0;	# Here, we let all parameters in ORD to be 0;(Or it would do harm to the judgement.) As a result, we can only add a parameter each time instead of the possibility to add many parameters each time, when the angle is exact the same.

		C_hat = max(abs(C));
		ord[index] = which(abs(C) == C_hat);	# formula (2.9), add a parameter;
		s[ord[index]] = sign(C[ord[index]]);	# formula (2.10)
		s_nonzero = which(s != 0);
		X_A = matrix(rep(s[s_nonzero], n), nrow = n, byrow = TRUE)*X[, s_nonzero];	# formula (2.4)
		G_A = t(X_A) %*% X_A;	# formula (2.5)
		I_A = as.matrix(rep(1, length(s_nonzero)), ncol = 1);
		G_A_inv = as.matrix(solve(G_A));
		A_A = as.numeric((t(I_A) %*% G_A_inv %*% I_A) ^ (-0.5));	# formula (2.5)
		u_A = A_A * X_A %*% G_A_inv %*% I_A;	# formula (2.6)
		a = t(X) %*% u_A;	# formula (2.11)
		A_C = setdiff(1:p, ord);
		gamma_list = rep(0, 2*length(A_C));

		if(length(A_C) > 0) {
			for(i in 1:length(A_C)) {
				gamma_list[2*i-1] = (C_hat-C[i])/(A_A-a[i]);
				gamma_list[2*i] = (C_hat+C[i])/(A_A+a[i]);
			}
			flag = Inf;
			key = 0;
			for(i in 1:length(A_C)) {
				if(gamma_list[2*i-1] > 0 & gamma_list[2*i] < flag) {
					flag = gamma_list[2*i-1];
					key = i;
				}
				if(gamma_list[2*i] > 0 & gamma_list[2*i] < flag) {
					flag = gamma_list[2*i];
					key = i;
				}	
			}		# formula (2.13)
			mu = mu + flag * u_A;	# formula (2.12)
		}	
	}
	return(list(mu = mu, beta = solve(t(X) %*% X) %*% t(X) %*% mu, ord = ord));
}

normalize = function(X) {
	X = X - mean(X);
	X = X / norm(X, type = '2');
	return(X);
}