CV = function(X, Y, index, k, i) {
	# Return the train set and test set;
	# index: The Partition;
	# k: the number of folds;
	# i: the i_th fold;
	n = nrow(X);
	test = which(index == i);
	train = setdiff(1:n, test);
	train_X = X[train, ];
	train_Y = Y[train, ];
	test_X = X[test, ];
	test_Y = Y[test, ];
	return(list(X1 = train_X, X2 = test_X, Y1 = train_Y, Y2 = train_Y))
}

Partition = function(X, Y, k) {
	n = nrow(X);
	index = rep(1:k, ceiling(n/k))[1:n];
	return(index);
}