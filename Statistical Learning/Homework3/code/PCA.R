PCA = function(X, k) {
	# PCA
	# X: The data matrix, each row is a data point;
	# k: The number of principle components;
	sub = function(X) {
		# Normalize(Centerlize) the matrix;
		return(X - mean(X));
	}
	n = nrow(X);
	p = ncol(X);
	X = apply(X, 2, sub);	#Normalized X;
	C = 1/(n-1) * (t(X) %*% X);	# Cov Matrix;
	eigC = eigen(C);  # Eigen Pairs;
	P = as.matrix(eigC$vectors[, 1:k]);	# The largest k eigenvectors of C;
	eigC_val = eigC$values;
	total_sum = sum(eigC_val);
	energy = sum(eigC_val[1:k]);
	NX = X %*% P;
	r$X = NX;
	r$rate = energy/total_sum;
	return(r);
}

read = function(data_path) {
    data = read.csv(data_path);
    data = as.matrix(data)[, 2:ncol(data)];
    colnames(data) = NULL;
    return(data);
}

draw = function(X) {
    p = ncol(X);
    if(p == 1) {
        plot(X, rep(0, nrow(X)), type = 'p');
    }
    else if(p == 2) {
        plot(X[, 1], X[, 2]);
    }
}

# # data = read("../data/assign32.csv");
# data = read.csv("../data/test2.csv");
# # ndata = matrix(rep(0, nrow(data)*ncol(data)*3), ncol = 3);
# # for(i in 1:nrow(data)) {
# #     for(j in 1:ncol(data)) {
# #         ndata[(i-1)*ncol(data)+j, ] = c(i, j, data[i, j]);
# #     }
# # }
# # r = PCA(ndata, 3);
# # write.csv(r, '../data/test2_pca_2.csv', row.names = FALSE);
# r = PCA(data, 2)$X;
# draw(r);