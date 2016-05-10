source('em_func.R')
em = function(x, dim, mu, sigma, t, maxit = 100, error = 1e-6) {
  # mu, sigma, t are listsa containing init data
  # Init
  n = nrow(x)
  T = matrix(rep(0, n*dim), ncol=dim)

  for(step in 1:maxit) {
    
    # E-step
    for(j in 1:dim) {
      for(i in 1:n) {
        # print(x[i, ])
        T[i, j] = em_FUNC(x[i, ], mu[[j]], sigma[[j]]) * t(j)
      }
    }
    
    T = T/rowSums(T)
    sigma0 = sigma
    t0 = t
    mu0 = mu
    
    # M-step
    for(j in 1:dim) {
      v1 = sum(T[, j])
      v2 = matrix(rep(0, ncol(x)), nrow=1)
      for(i in 1:n) {
        v2 = v2 + (T[i, j] * x[i, ])
      }
      mu[[j]] = v2 / v1
      t[j] = v1 / n
      v3 = matrix(rep(0, ncol(x)^2), nrow=ncol(x))
      for(i in 1:n) {
        temp1 = matrix(x[i, ])
        temp2 = matrix(mu[[j]])
        delta = temp1 - temp2
        v3 = v3 + (T[i, j] * delta %*% t(delta))
      }
      sigma[[j]] = (v3/v1)
    }
    mu_sum = 0
    sigma_sum = 0
    for(i in 1:length(mu)) {
      mu_sum = mu_sum + sum(abs(mu0[[i]] - mu[[i]]))
    }
    for(i in 1:length(sigma)) {
      sigma_sum = sigma_sum + sum(abs(sigma0[[i]] - sigma[[i]]))
    }
    # Check if converged
    if(mu_sum < error & sigma_sum < error & sum(abs(t-t0)) < error)
      break
    print(mu)
  }
  returnlist = list(mu, sigma, t)
  
  return(returnlist)
}