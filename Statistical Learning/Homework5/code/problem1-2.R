source('read.R')
source('Ridge.R')
source('std.R')
source('PCR.R')
source('std.R')
source('Best_Subset.R')
source('PLS.R')
source('Lasso.R')

## Problem 1 ###
data = read('../data/test1.csv')
X = data$X;
Y = data$Y;

### Plot The axis ###
plot(0, 0, xlim = c(-0.5, 6.5), ylim = c(-1.5, 3.5), xlab = 'beta1', ylab = 'beta2', main = 'rho = 0.5')
arrows(0, -1.5, 0, 3.5, length = 0, lty = 2)
arrows(-0.5, 0, 6.5, 0, length = 0, lty = 2)

### Least Square Regression ###
X1 = apply(X, 2, std);
Y1 = Y - mean(Y);
beta0 = solve(t(X1) %*% X1) %*% t(X1) %*% Y1;
points(beta0[1], beta0[2], pch = 20)

### Ridge Regression ###
beta11 = c();
beta12 = c();
count = 0;
for(lambda in seq(1e-6, 1000, 1)) {
	beta = Ridge(X, Y, end = lambda, step = 1);
	count = count + 1;
	beta11[count] = beta[1];
	beta12[count] = beta[2];
}
lines(beta11, beta12);


### Principle Components Regression ###
beta1 = PCR(X, Y, k = 1)$beta;
lines(c(0, beta1[1]), c(0, beta1[2]));
points(beta1[1], beta1[2], pch = 20);
lines(c(beta1[1], beta0[1]), c(beta1[2], beta0[2]));

### Best Subset ###
beta1 = Best_Subset(X, Y, k = 1)$beta;
lines(c(0, beta1[1]), c(0, 0));
lines(c(beta1[1], beta0[1]), c(0, beta0[2]))
points(beta1[1], 0, pch = 20);

### Partial Least Squares ###
beta1 = PLS1(X, Y, k = 1)$beta;
lines(c(0, beta1[1]), c(0, beta1[2]));
points(beta1[1], beta1[2], pch = 20);
lines(c(beta1[1], beta0[1]), c(beta1[2], beta0[2]));

### Lasso ###
beta1 = Lasso(X, Y, gamma = 3.1)$beta;
lines(c(0, beta1[1]), c(0, beta1[2]));
points(beta1[1], beta1[2], pch = 20);
lines(c(beta1[1], beta0[1]), c(beta1[2], beta0[2]));

### Legend ###
text(1.65, 2, 'PCR')
text(3, 2.3, 'PLS')
text(2.3, 1.5, 'Ridge')
text(2.45, 1, 'Lasso')
text(4.8, 2, 'Least Square')
text(4, 0.15, 'Best Subset')


### Problem 2 ###
# data = read('../data/test2.csv')
# X = data$X;
# Y = data$Y;

# ### Plot The axis ###
# plot(0, 0, xlim = c(-0.5, 6.5), ylim = c(-1.5, 3.5), xlab = 'beta1', ylab = 'beta2', main = 'rho = -0.5')
# arrows(0, -1.5, 0, 3.5, length = 0, lty = 2)
# arrows(-0.5, 0, 6.5, 0, length = 0, lty = 2)

# ### Least Square Regression ###
# X1 = apply(X, 2, std);
# Y1 = Y - mean(Y);
# beta0 = solve(t(X1) %*% X1) %*% t(X1) %*% Y1;
# points(beta0[1], beta0[2], pch = 20)

# ## Ridge Regression ###
# beta11 = c();
# beta12 = c();
# count = 0;
# for(lambda in seq(1e-6, 1000, 1)) {
# 	beta = Ridge(X, Y, end = lambda, step = 1);
# 	count = count + 1;
# 	beta11[count] = beta[1];
# 	beta12[count] = beta[2];
# }
# lines(beta11, beta12);


# ### Principle Components Regression ###
# beta1 = PCR(X, Y, k = 1)$beta;
# lines(c(0, beta1[1]), c(0, beta1[2]));
# points(beta1[1], beta1[2], pch = 20);
# lines(c(beta1[1], beta0[1]), c(beta1[2], beta0[2]));

# ### Best Subset ###
# beta1 = Best_Subset(X, Y, k = 1)$beta;
# lines(c(0, beta1[1]), c(0, 0));
# lines(c(beta1[1], beta0[1]), c(0, beta0[2]))
# points(beta1[1], 0, pch = 20);

# ### Partial Least Squares ###
# beta1 = PLS1(X, Y, k = 1)$beta;
# lines(c(0, beta1[1]), c(0, beta1[2]));
# points(beta1[1], beta1[2], pch = 20);
# lines(c(beta1[1], beta0[1]), c(beta1[2], beta0[2]));

# ### Lasso ###
# beta1 = Lasso(X, Y, gamma = 1.01)$beta;
# print(beta)
# lines(c(0, beta1[1]), c(0, beta1[2]));
# points(beta1[1], beta1[2], pch = 20);
# lines(c(beta1[1], beta0[1]), c(beta1[2], beta0[2]));

# ### Legend ###
# text(1, -1.2, 'PCR')
# text(3, -0.25, 'PLS')
# text(2.3, 1, 'Ridge')
# text(2.5, 0.5, 'Lasso')
# text(5, 2.2, 'Least Square')
# text(4, 0.5, 'Best Subset')