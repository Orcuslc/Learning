##### Gibbs Sampling for Problem 5 ###
sample5 = function(mu, sigma, x) {
  mean = mu[2]+sigma[2,1]*(1/sigma[1,1])*(x-mu[1]);
  sd = sigma[2,2]-sigma[2,1]*(1/sigma[1,1])*sigma[1,2];
  return(rnorm(1, mean, sd));
}

gibbs_sampling5 = function(n, mu, sigma, init_param) {
  x1 = rep(0, n);
  x2 = rep(0, n);
  x1[1] = init_param[1];
  x2[1] = init_param[2];
  
  mu2 = c(mu[2], mu[1]);
  sigma2 = matrix(c(sigma[2,2], sigma[2,1], sigma[1,2], sigma[1,1]), ncol = 2);
  
  for(i in 2:n) {
    x2[i] = sample5(mu, sigma, x1[i-1]);
    x1[i] = sample5(mu2, sigma2, x2[i]);
  }
  rlist = list(x1, x2);
  return(rlist);
}

simulate5 = function(n) {
  mu1 = c(1, 4);
  mu2 = c(-2, -1);
  sigma1 = matrix(c(1, 0.3, 0.3, 2), ncol = 2);
  sigma2 = matrix(c(3, 0.4, 0.4, 1), ncol = 2);
  
  Z = matrix(rep(0, 2*n), nrow = 2);
  ##### Each col in Z is a sample point #####
  
  X = gibbs_sampling5(4*n, mu1, sigma1, c(1, 1));
  Y = gibbs_sampling5(4*n, mu2, sigma2, c(-3, -3));
  
  x1 = X[[1]];
  x2 = X[[2]];
  y1 = Y[[1]];
  y2 = Y[[2]];

  ##### Take the last 1/4 of samples as a simulation ###
  for(i in 1:n) {
    u = runif(1);
    if(u > 0.5) {
      Z[1, i] = x1[i + 3*n];
      Z[2, i] = x2[i + 3*n];
    }
    else {
      Z[1, i] = y1[i + 3*n];
      Z[2, i] = y2[i + 3*n];
    }
  }
  return(Z);
}


n = 10000
z = simulate5(n)
plot(z[1, ], z[2, ])