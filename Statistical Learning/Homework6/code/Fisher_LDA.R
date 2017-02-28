FLDA = function(X, types, k) {
	# Fisher LDA(MDA)
	# X: data matrix, each row is a data point
	# types: type vector
	# k: number of types
	n = nrow(X);
	mu = rowMeans(X);
	ni = rep(0, k);
	mui = matrix(rep(0, k*ncol(X)), nrow = k);
	for(i in 1:k) {
		index = which(types == i);
		ni[i] = length(index);
		mui[i, ] = rowMeans(X[index, ]);
	}
	SB = 0;
	SW = 0;
	for(i in 1:k) {
		SB = SB + ni[i] * (mui[i, ]-mu) %*% t(mui[i, ]-mu);
		for(j in which(types == i)) {
			SW = SW + (X[j, ]-mui[i, ]) %*% t(X[j, ]-mui[i, ]);
		}
	}
	eig = eigen(solve(SW) %*% SB);
	return(eig$vectors[, 1:(k-1)]);
}

FLDA_project = function(X, v) {
	return(t(v) %*% X);
}