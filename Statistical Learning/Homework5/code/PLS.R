source('std.R')

PLS1 = function(X, Y, k) {
	Y = Y - mean(Y);
	X = apply(X, 2, std);
	n = nrow(X);
	p = ncol(X);
	P = matrix(rep(0, k*p), nrow = p);
	C = matrix(rep(0, k), nrow = k);
	T = matrix(rep(0, n*k), nrow = n);
	W = matrix(rep(0, k*p), nrow = p);
	for(index in 1:k) {
		w = t(X) %*% Y;
		w = w/norm(w, type = '2');
		W[, index] = w;
		tj = X %*% w;
		T[, index] = tj;
		c = (t(tj) %*% Y)/(norm(tj, type = '2')^2);
		C[index, ] = c;
		p = t(X) %*% tj/(norm(tj, type = '2')^2);
		P[, index] = p;
		X = X - tj %*% t(p);
		Y = Y - tj %*% c;
	}
	return(list(W = W, T = T, P = P, C = C, beta = W %*% C));
}

PLS2 = function(X, Y, k) {

}