source('kmeans.R')

spectral_clustering = function(A, k, graph = 'full', parameter = 0, similarity = 'gaussian', sigma = 1, max_iter = 1000, min_error = 1e-6) {
	# Spectral Clustering
	# A: data matrix
	# k: number of types
	# graph: the type of graph, in c('full', 'epsilon', 'directed', 'undirected')
	# parameter: the parameter, only used in 'epsilon', 'directed', 'undirected'
	# similarity: 'gaussian' or 'distance'
	# sigma: used as the sigma in gaussian kernel
  	n = nrow(A);
	W = construct_graph(A, graph, parameter, similarity, sigma);
	D = diag(rowSums(W));
	L = D - W;
	ev = Re(as.matrix(eigen(L)$vec[, (n-k+1):(n-1)]));
	# print(ev$vec[, (n-k+1):n]);
	# print(sort(ev$values, index.return = TRUE)$ix);
	type = kmeans(ev, k = k, max_iter = max_iter, min_error = min_error)[[1]];
	plot_points(A, type, k);
}


construct_graph = function(A, graph, parameter, similarity, sigma) {
	n = nrow(A);
	W = matrix(rep(0, n*n), ncol = n);
	if(graph == 'full') {
		for(i in 1:n) {
			for(j in 1:n) {
				W[i, j] = calc_dist(A[i, ], A[j, ]);
			}
		}
	}
	else if(graph == 'epsilon') {
		for(i in 1:n) {
			for(j in 1:n) {
				W[i, j] = calc_dist(A[i, ], A[j, ]);
				if(W[i, j] > parameter) {
					W[i, j] = 0;
				}
			}
		}
	}
	else if(graph == 'directed') {
		for(i in 1:n) {
			for(j in 1:n) {
				W[i, j] = calc_dist(A[i, ], A[j, ]);
			}
			index = sort(W[i, ], index.return = TRUE)$ix;
			W[i, index[(parameter+1):n]] = 0;
		}
	}
	else if(graph == 'undirected') {
		for(i in 1:n) {
			for(j in 1:n) {
				W[i, j] = calc_dist(A[i, ], A[j, ]);
			}
			index = sort(W[i, ], index.return = TRUE)$ix;
			W[i, index[(parameter+1):n]] = 0;	
		}
		for(i in 1:n) {
			for(j in 1:n) {
				if(W[i, j] == 0 && W[j, i] != 0) {
					W[i, j] = W[j, i];
				}
			}
		}
	}
	else {
	    stop("Wrong graph type")
	}
	if(similarity == 'gaussian') {
		for(i in 1:n) {
			for(j in 1:n) {
				if(W[i, j] != 0) {
					W[i, j] = exp(-calc_dist(A[i, ], A[j, ])^2/(2*sigma^2));
				}
			}
		}
	}
	# if similarity == 'distance' then there is no necessary to change the W;
	return(W);
}
