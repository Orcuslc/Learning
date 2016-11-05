NMF = function(X, r, max_iter = 1e5) {
	# Nonnegative Matrix Factorization
	# X = W*H;
	# X is a n*p matrix, W is a n*r matrix, and H is a r*p matrix.
	n = nrow(X);
	p = ncol(X);
	W = abs(matrix(rnorm(n*r), ncol = r)); # Init W and H.
	H = abs(matrix(rnorm(r*p), ncol = p));
	for(t in 1:max_iter) {
		WH = W %*% H;
		for(i in 1:n) {
			for(k in 1:r) {
				W[i, k] = W[i, k]*(sum(H[k, ]*X[i, ]/(WH[i, ]+1e-9)))/(sum(H[k, ]));
			}
		}
		for(k in 1:r) {
			for(j in 1:p) {
				H[k, j] = H[k, j]*(sum(W[, k]*X[, j]/(WH[, j]+1e-9)))/(sum(W[, k]));
			}
		}
	}
	r$W = W;
	r$H = H;
	WH = W %*% H;
	n1 = norm(X, "F");
	n2 = norm((X-WH), "F");
	print(X-WH)
	r$rate = n2/n1;
	return(r);
}