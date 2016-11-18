LARS = function(X, Y) {
	# Least Angle Regression
	Y = Y - mean(Y); # Standardize Y;
	X = apply(X, 2, sub); # Standardize each col of X;
	n = nrow(X); # Number of datapoints in X;
	p = ncol(X); # Number of parameters in X;
	mu = as.matrix(rep(0, p), ncol = 1); # The weight of each parameter;
	s = as.matrix(rep(0, p), nrow = 1); # The sign of each parameter;
	ord = rep(0, p) # The order of each parameter;

	for (index in 1:p) {
		C = t(X) %*% (Y - mu);	# formula (2.8)
		C_hat = max(abs(C));
		A_hat = which(abs(C) == C_hat);	# formula (2.9)
		s[A_hat] = sign(C[A_hat]);	# formula (2.10)
		X_A = s*X[which(s != 0)];	# formula (2.4)
		G_A = t(X_A) %*% X_A;	# formula (2.5)
		1_A = as.matrix(rep(1, length(A_hat)), ncol = 1);
		G_A_inv = solve(G_A);
		A_A = (t(1_A) %*% G_A_inv %*% 1_A) ^ (-0.5);	# formula (2.5)
		u_A = A_A * X_A %*% G_A_inv %*% 1_A;	# formula (2.6)
		a = t(X) %*% u_A;	# formula (2.11)
		A_C = setdiff(1:p, A_hat);
		gamma_list = rep(0, 2*length(A_C));
		for(i in 1:length(A_C)) {
			gamma_list[2*i-1] = (C_hat-C[i])/(A_A-a[i]);
			gamma_list[2*i] = (C_hat+C[i])/(A_A+a[i]);
		}
		flag = Inf;
		key = 0;
		for(i in 1:length(A_C)) {
			if(gamma_list[2*i] > 0 & gamma_list[2*i] < flag) {
				flag = gamma_list[2*i];
				key = i;
			}
			if(gamma_list[2*i+1] > 0 & gamma_list[2*i+1] < flag) {
				flag = gamma_list[2*i+1];
				key = i;
			}
		}	# formula (2.13)
		mu = mu + gamma * u_A;	# formula (2.12)
		ord[index] = i;	# record the index_th component;
	}
	return(list(mu = mu, ord = ord));
}

sub = function(X) {
	return(X - mean(X));
}