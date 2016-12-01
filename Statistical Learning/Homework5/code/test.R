source('LARS.R')
source('LR.R')
source('Lasso.R')
source('Ridge.R')
source('Best_Subset.R')
source('Read.R')
source('PCR.R')
source('PLS.R')

# data = read('../data/test1.csv');
data = read('../data/test2.csv');
X = data$X;
Y = data$Y;

### Test LARS ###
# r = LARS(X, Y);
# print(r$beta)
# print(r$ord)

### Test LASSO ###
# r = Lasso(X, Y, 0.3)$beta;
# print(r);
# r = Lasso_shrinkage(X, Y, start = 0.9, end = 1.1, step = 0.01)$beta;
# print(r)

### Test Ridge ###
# beta = Ridge(X, Y);
# print(beta)

### Test Best Subset ###
# beta = Best_Subset(X, Y, 1)
# print(beta);

### Test PCR ###
# beta = PCR(X, Y, k = 1);

### Test PLS ###
# beta = PLS1(X, Y, k = 1)$beta;
# print(beta)