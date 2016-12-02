source('Best_Subset.R')
source('Lasso.R')
source('LARS.R')
source('PCR.R')
source('PLS.R')
source('Ridge.R')
source('Cross_Validation.R')
source('Read.R')
source('std.R')

data = read('../data/test3.csv');
X = data$X;
Y = data$Y;
k = 10; # 10-fold Cross Validation

### Best Subset ###
index = Partition(X, Y, k);
error = 0;
for(i in 1:k) {
	sets = CV(X, Y, index, k, i);
	beta = Best_Subset(sets$X1, sets$Y1, k = (nrow(sets$X1)-1))$beta;
	print(beta)
	error = error + calc_err(sets$X2, sets$Y2, beta);
}
error = error/k;
print(error);