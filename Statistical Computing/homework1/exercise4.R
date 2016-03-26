# Exercise 4
source('EM.R')
data = read.csv('Data1.csv')
x1 = data['V1']
x2 = data['V2']
x = data.frame(x1, x2)
x = data.matrix(x)
dim = 3
n = 2
mu = list(t(matrix(runif(n))), t(matrix(runif(n))), t(matrix(runif(n))))
sigma = list(matrix(runif(n*n), ncol = n), matrix(runif(n*n), ncol = n), matrix(runif(n*n), ncol = n))
t = c(0.1, 0.7, 0.2)
rlist = em(x, dim, mu, sigma, t)
print(rlist[[1]])
print(rlist[[2]])
print(rlist[[3]])


