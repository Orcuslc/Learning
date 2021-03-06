# Exercise5
source('EM.R')
x = matrix(c(171, 174, 159, 176, 164, 169, 170, 173, 159,
             172, 166, 175, 161, 186, 160, 168, 166, 174,
             159, 178, 165, 189, 164, 168, 165, 185, 160,
             175, 172, 168, 167, 171, 160, 174, 168, 174,
             167, 175, 162, 177))
dim = 2
mu = list(matrix(c(163)), matrix(c(176)))
sigma = list(matrix(runif(1)), matrix(runif(1)))
t = c(0.2, 0.8)
rlist = em(x, dim, mu, sigma, t)
print(rlist[[1]])
print(rlist[[2]])
print(rlist[[3]])

