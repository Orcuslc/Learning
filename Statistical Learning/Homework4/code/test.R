source("LR.R")

## Problem 1 ##
data = read('../data/simplelr1.csv')
X = data$X;
Y = data$Y;
plot(X[, 2], Y);
beta = LR(X, Y);
print(beta);
lines(X, beta[1, 1]+beta[2, 1]*X);
inference_t(X, Y, beta, 1);
inference_F(X, Y, beta, c(1));