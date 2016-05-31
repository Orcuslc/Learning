######### Gibbs Sampling for problem 3 ###########
sample3 = function(param1, param2) {
  lambda = 1/(param1 + param2 + 1);
  ##### Using inverse transform algorithm to generate the distribution:
  ##### f(x|lambda) = lambda*exp(-lambda*x);
  u = runif(1);
  x = -lambda*log(lambda*u);
  return(x);
}

gibbs_sampling3 = function(n, init_param) {
  ##### Initialize parameters;
  x = rep(0, n);
  y = rep(0, n);
  z = rep(0, n);
  x[1] = init_param[1];
  y[1] = init_param[2];
  z[1] = init_param[3];
  
  ##### Iterative Sampling;
  for(i in 2:n) {
    x[i] = sample3(y[i-1], z[i-1]);
    y[i] = sample3(x[i], z[i-1]);
    z[i] = sample3(x[i], y[i]);
  }
  rlist = list(x, y, z);
  return(rlist);
}

estimate3 = function(n) {
  res = gibbs_sampling3(2*n, c(1, 1, 1));
  X = res[[1]];
  Y = res[[2]];
  Z = res[[3]];
  X_sample = X[(n+1):(2*n)];
  Y_sample = Y[(n+1):(2*n)];
  Z_sample = Z[(n+1):(2*n)];

  sum = sum(X_sample)*sum(Y_sample)*sum(Z_sample);
  return(sum/(n^3));
}

estimate3(100000)