read = function(data_path) {
    data = read.csv(data_path, header = FALSE);
    data = as.matrix(data)[, 2:ncol(data)];
    colnames(data) = NULL;
    X = data[, 1:ncol(data)-1];
    colnames(X) = NULL;
    Y = as.matrix(data[, ncol(data)]);
    return(list(X = X, Y = Y));
}