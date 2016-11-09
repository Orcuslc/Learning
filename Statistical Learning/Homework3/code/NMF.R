NMF = function(X, r, op = 'D', max_iter = 1e3) {
	# Nonnegative Matrix Factorization
	# X = W*H;
	# X is a n*p matrix, W is a n*r matrix, and H is a r*p matrix.
    # op: c('M', 'D'); 
    # op = 'M': Mean squared error objective; 'D': Divergence objective;
	n = nrow(X);
	p = ncol(X);
	W = abs(matrix(rnorm(n*r), ncol = r)); # Init W and H.
	H = abs(matrix(rnorm(r*p), ncol = p));
	if(op == 'D'){
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
	}
	else if(op == 'M') {
	    for(i in 1:max_iter) {
	        H = H*(t(W)%*%X)/((t(W)%*%W%*%H)+1e-9);
	        W = W*(X%*%t(H))/((W%*%H%*%t(H))+1e-9);
	    } 
	}
	WH = W %*% H;
	n1 = norm(X, "F");
	n2 = norm((X-WH), "F");
	r = list(W = W, H = H, rate = n2/n1);
	return(r);
}

plot_basis = function(W) {
    # Plot the basis of W;
    k = ncol(W);
    n = nrow(W);
    X = rep(0, k*n);
    for(i in 1:k) {
        X[(n*(i-1)):(n*i)] = i;
    }
    Y = as.vector(W);
    plot(X, Y);
}