source('PCA.R')
source('NMF.R')
library("rgl")

## Test ##
# x = sort(runif(100))
# y = 2*x+runif(100)*0.5
# plot(x, y)
# r = PCA(t(rbind(x, y)), 2)
# plot(r$X[, 1], r$X[, 2])


## Problem 1 ##
# data = read("../data/assign31.csv");
# data[is.na(data)] = 0;
# r1 = PCA(data, 1);
# r1_X = r1$X;
# plot(r1_X, rep(0, length(r1_X)));
# print(r1$rate);

# r2 = PCA(data, 2);
# r2_X = r2$X;
# plot(r2_X[, 1], r2_X[, 2]);
# print(r2$rate);
# 
# r3 = PCA(data, 3);
# r3_X = r3$X;
# plot3d(r3_X[,1], r3_X[,2], r3_X[,3]);
# print(r3$rate)

# r6 = PCA(data, 14);
# print(r6$rate);

## Problem 2 ##
# data = read('../data/assign32.csv');
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
# # 
# r3 = PCA(data, 3);
# r3_X = r3$X;
# plot3d(r3_X[,1], r3_X[,2], r3_X[,3]);
# print(r3$rate)
# 
# r6 = PCA(data, 20);
# print(r6$rate);

## Problem 2.2 ##
# n = 4;
# m = 5;
# rates = rep(0, n*m);
# par(mfrow = c(n, m))
# for(i in 1:(n*m)) {
#     r = NMF(data, i, 'M');
#     rates[i] = r$rate;
#     plot_basis(r$W);
}
# window()
# plot(1:(n*m), rates, type = 'l');
# print(r1$W)
# print(r1$rate);

## Problem 3.2 ##
im = read.csv('../data/test2.csv');
colnames(im) = NULL;
im = as.matrix(im);
n = 3;
m = 3;
rn = c(1, 2, 3, 4, 5, 10, 20, 50);
par(mfrow = c(n, m))
for(i in 1:(n*m)) {
    r = NMF(im, rn[i], 'D');
    image(r$W%*%r$H, col = gray.colors(256), xlab = paste('NMF, D, k = ', as.character(rn[i])));
}
# image(im, col = gray.colors(256));