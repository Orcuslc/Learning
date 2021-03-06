source("LR.R")

## Problem 1 ##
# data = read('../data/simplelr1.csv')
# X = data$X;
# Y = data$Y;
# plot(X[, 2], Y);
# beta = LR(X, Y);
# lines(X, beta[1, 1]+beta[2, 1]*X);
# inference_t(X, Y, beta, i = 1, beta_0 = 0);
# inference_F(X, Y, beta, c(1));

## Problem 2 ##
data = read('../data/lr2.csv');
X = data$X;
Y = data$Y;
beta = LR(X, Y);
# print(beta);
# # inference_t(X, Y, beta, i = 5, beta_0 = -10)
inference_F(X, Y, beta, i = c(1, 4, 5))