source('spectral_clustering.R')
source('kmeans.R')

# data1 = read('Data1.csv')
# spectral_clustering(data1, k = 3)
# spectral_clustering(data1, k = 3, graph = 'epsilon', parameter = 0.1)
# spectral_clustering(data1, k = 3, graph = 'undirected', parameter = 3)
# spectral_clustering(data1, k = 3, graph = 'directed', parameter = 5)

# k = 3
# data2 = read('Data3.csv')
# type = kmeans(data2, k)[[1]]
# plot_points(data2, type, k)

# spectral_clustering(data2, k)
# spectral_clustering(data2, k, graph = 'epsilon', parameter = 5)
# spectral_clustering(data2, k, graph = 'undirected', parameter = 3)
spectral_clustering(data2, k, graph = 'directed', parameter = 5)
