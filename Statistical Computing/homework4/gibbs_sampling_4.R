##### Gibbs Sampling for Problem 4 #####
sample4_x = function(y, n) {
  probs = rep(0, n+1);
  c = 1; # C_{n}^{x};
  ycon = 1; # y^x * (1-y)^(nx);
  for(i in 1:(n+1)) {
    probs[i] = c * ycon;
    c = c*(n-i)/(i+1);
    ycon = ycon * y * (1-y)^n;
  }
  normalized_probs = rep(0, n+1);
  sums = 0;
  total_sum = sum(probs);
  u = runif(1);
  
  for(i in 1:(n+1)) {
    sums = sums + probs[i];
    normalized_probs[i] = sums/total_sum;
    if(u < normalized_probs[i]) {
      x = i-1;
      break;
    }
  }
  return(x);
}

sample4_y = function(x, n, alpha, beta) {
  y = rbeta(1, x+alpha, n*x+beta);
  return(y);
}


sample4_n = function(x, y, lambda) {
  ### Use Acceptance-Rejection Method to generate N ###
  if(x == 0){
    n_max = 0;
  }
  else {
    n_max = floor(x/(1-(1-y)^x));
  }
  c = choose(n_max, x)*(1-y)^(n*x);
  # print(c(n_max, x, y, n));
  while(1) {
    pois = -1;
    while(pois < x) {
      pois = rpois(1, lambda);
    }
    u = runif(1);
    if(u*c < choose(pois, x)*(1-y)^(pois*x)) {
      return(pois);
    }
  }
}

gibbs_sampling4 = function(n, alpha, beta, lambda, init_param) {
  x = rep(0, n);
  y = rep(0, n);
  n = rep(0, n);
  x[1] = init_param[1];
  y[1] = init_param[2];
  n[1] = init_param[3];
  
  for(i in 2:n) {
    print(i)
    x[i] = sample4_x(y[i-1], n[i-1]);
    y[i] = sample4_y(x[i], n[i-1], alpha, beta);
    n[i] = sample4_n(x[i], y[i], lambda);
  }
  rlist = list(x, y, n);
  return(rlist);
}

estimate4 = function(n, alpha, beta, lambda) {
  rl = gibbs_sampling4(4*n, alpha, beta, lambda, c(2, 0.5, 3));
  x = rl[[1]];
  y = rl[[2]];
  n = rl[[3]];
  
  ex = mean(x[(3*n):(4*n)]);
  ey = mean(y[(3*n):(4*n)]);
  en = mean(n[(3*n):(4*n)]);
  return(c(ex, ey, en));
}

n = 10000
alpha = 2
beta = 3
lambda = 4
estimate4(n, alpha, beta, lambda)