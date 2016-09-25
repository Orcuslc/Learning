source('kmeans.R')

calc_squares = function(A) {
  # To calculate the squares within clusters, used in calc_w;
  n = nrow(A);
  if(is.null(n)) {
    return(0);
  }
  else {
    nsum = 0;
    for(i in 1:n) {
      for(j in i:n) {
        nsum = nsum + calc_dist(A[i, ], A[j, ]);
      }
    }
    return(nsum);
  }
}

calc_w = function(A, k, type, centers) {
  # Calculate the W(k) in C-H and H evaluation;
  nsum = 0;
  for(i in 1:k) {
    nsum = nsum + calc_squares(A[which(type==i), ]);
  }
  return(nsum);
}

calc_b = function(A, k, type, centers) {
  # Calculate the B(k) in C-H evaluation;
  return(calc_squares(centers));
}

evaluate_CH = function(A, max_k = 20, max_iter = 1000, min_error = 1e-6) {
  # Calinski & Harabasz method
  CH = rep(0, max_k);
  n = nrow(A);
  for(k in 2:max_k) {
    print(k);
    res = kmeans(A, k);
    type = res[[1]];
    centers = res[[2]];
    nCH = (calc_b(A, k, type, centers)/(k-1))/(calc_w(A, k, type, centers)/(n-k));
    CH[k] = nCH;
  }
  return(CH);
}

evaluate_H = function(A, max_k = 10, max_iter = 1000, min_error = 1e-6) {
  # Hartigan Method;
  # Optimized the computation;
  H = rep(0, max_k);
  n = nrow(A);

  res = kmeans(A, 2);
  type = res[[1]];
  centers = res[[2]];
  
  for(k in 2:max_k) {
    res_next = kmeans(A, k+1);
    type_next = res_next[[1]];
    centers_next = res_next[[2]];
    nH = (calc_w(A, k, type, centers)/calc_w(A, k+1, type_next, centers_next)-1)*(n-k-1);
    H[k] = nH;
    type = type_next;
    centers = centers_next;
  }
  return(H);
}

gen_GAP = function(A) {
  # Sample unifomly distributed data in the space of [min, max];
  # The length of dataset is set as the same of the original dataset.
  narg = ncol(A);
  ndata = nrow(A);
  # smp = rep(0, narg);
  smp = matrix(rep(0, narg*ndata), ncol = narg);
  for(i in 1:narg) {
    max_d = max(A[, i]);
    min_d = min(A[, i]);
    r = runif(ndata, min = min_d, max = max_d);
    smp[, i] = r;
  }
  return(smp);
}

evaluate_GAP = function(A, B = 100, max_k = 10, max_iter = 1000, min_error = 1e-6) {
  # Gap Statistic;
  # We use method (a) to generate reference datasets;
  gap_last = -Inf;
  gap = rep(0, max_k);
  nres = max_k;
  count = 0;
  for(m in 2:max_k) {
    res = calc_GAP(A, k = m);
    gap_k = res[[2]];
    log_W = res[[1]];
    l = mean(log_W);
    sd_k = sqrt(mean((log_W - l)^2));
    s_k = sd_k * sqrt(1+1/B);
    if(gap_last >= gap_k - s_k && count == 0) {
      nres = m - 1;
      count = count + 1;
    }
    gap_last = gap_k;
    gap[m] = gap_last;
  }
  return(list(nres, gap));
}

calc_GAP = function(A, B = 10, k) {
  res = kmeans(A, k);
  type = res[[1]];
  log_W_data = log(calc_w_GAP(A, k, type));
  log_W_ref_B = rep(0, B);
  for(i in 1:B) {
    smp = gen_GAP(A);
    res = kmeans(smp, k);
    type = res[[1]];
    W = log(calc_w_GAP(smp, k, type));
    log_W_ref_B[i] = W;
  }
  return(list(log_W_ref_B, mean(log_W_ref_B) - log_W_data));
}

calc_w_GAP = function(A, k, type) {
  sums = 0;
  for(i in 1:k) {
    nsum = 0;
    A_t = A[which(type == i), ];
    if(is.null(nrow(A_t))) {
      A_t = matrix(A_t);
    }
    n = nrow(A_t);
    if(n==1)
    {
      print(n)
    }
    for(j in 1:n) {
      for(k in 1:n) {
        nsum = nsum + calc_dist(A_t[j, ], A_t[k, ]);
      }
    }
    sums = sums + nsum/n;
  }
  return(sums);
}