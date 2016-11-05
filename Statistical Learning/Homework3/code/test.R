source('PCA.R')
source('NMF.R')
library(rgl)
# library("rgl")
# x = sort(runif(100))
# y = 2*x+runif(100)*0.5
# plot(x, y)
# Y = PCA(t(rbind(x, y)), 2)
# plot(Y[, 1], Y[, 2])


## Problem 1 ##
# data = read("../data/assign31.csv");
# data[is.na(data)] = 0;
# r1 = PCA(data, 1);
# r1_X = r1$X;
# plot(r1_X, rep(0, length(r1_X)));
# print(r1$rate);
# 
# r2 = PCA(data, 2);
# r2_X = r2$X;
# plot(r2_X[, 1], r2_X[, 2]);
# print(r2$rate);
# 
# r3 = PCA(data, 3);
# r3_X = r3$X;
# plot3d(r3_X[,1], r3_X[,2], r3_X[,3]);
# print(r3$rate)
# 
# r6 = PCA(data, 10);
# print(r6$rate);

## Problem 2 ##
data = read('../data/assign32.csv');
data[is.na(data)] = 0;
# r1 = PCA(data, 1);
# r1_X = r1$X;
# plot(r1_X, rep(0, length(r1_X)));
# print(r1$rate);
# 
# r2 = PCA(data, 2);
# r2_X = r2$X;
# plot(r2_X[, 1], r2_X[, 2]);
# print(r2$rate);
# 
# r3 = PCA(data, 3);
# r3_X = r3$X;
# plot3d(r3_X[,1], r3_X[,2], r3_X[,3]);
# print(r3$rate)
# 
# r6 = PCA(data, 20);
# print(r6$rate);

## Problem 2.2 ##
r1 = NMF(data, 2);
# print(r1$W)
print(r1$rate);
