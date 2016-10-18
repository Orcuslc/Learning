# Homework 2.3
source('spectral_clustering.R')
source('kmeans.R')
##########
# test
##########

# a = matrix(runif(10), ncol = 2);
# data = read('circles.csv');
data = read('curves.csv');
# spectral_clustering(data, k = 3);

# spectral_clustering(data, k = 3, graph = 'epsilon', parameter = 10)

### using directed graph would lead to complex eigenvalues;
# spectral_clustering(data, k = 3, graph = 'directed', parameter = 30)

# spectral_clustering(data, k = 3, graph = 'undirected', parameter = 10)

type = kmeans(data, k = 3)[[1]];
plot_points(data, type, k = 3)


