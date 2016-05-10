# Problem 1.1
p11 = function(a, lambda, k) {
  # The following functions have the same comments.
  # Generate a matrix A of random variables;
  # The number of rows and columns of A is a[1] and a[2];
  # lambda and k are the parameters in the distributional function;
  q = matrix(rep(0, k+1), nrow = 1)
  qsum = matrix(rep(0, k+1), nrow = 1)
  q0 = exp(-lambda)
  qsum0 = 0
  for(i in 1:(k+1)) {
    q[i] = q0
    qsum0 = qsum0 + q0
    qsum[i] = qsum0
    q0 = q0 * lambda / i
  }
  q = q / rowSums(q)
  qsum = qsum / qsum[k+1]
  A = matrix(rep(0, a[1] * a[2]), ncol = a[2])
  U = matrix(runif(a[1] * a[2]), ncol = a[2])
  for (i in 1:a[1]) {
    for (j in 1:a[2]) {
      place = which(U[i, j] < qsum)
      A[i, j] = place[1] - 1
    }
  }
  return(A)
}

# Problem 1.2
p12 = function(a, lambda, k) {
  q0 = exp(-lambda)
  q = matrix(rep(0, k+1), nrow = 1)
  for(i in 1:(k+1)) {
    q[i] = q0
    q0 = q0*lambda/i
  }
  q = q/rowSums(q)
  A = matrix(rep(0, a[1]*a[2]), ncol = a[2])
  for(i in 1:a[1]) {
    for(j in 1:a[2]) {
      while(1) {
        z = runif(1)
        y = floor(z*(k+1))
        c = (k+1) * q[1]
        u = runif(1)
        if (u < (k+1)/c*q[y+1]) {
          A[i, j] = y
          break
        }
      }
    }
  }
  return(A)
}

# Problem 2
p2 = function(a) {
  handle_func = function(u) {
    if(u < 0.55) {
      return(2*floor(u/0.11)+5)
    }
    else {
      return(2*floor((u-0.55)/0.09)+6)
    }
  }
  f = Vectorize(handle_func)
  A = matrix(runif(a[1] * a[2]), ncol = a[2])
  return(f(A))
}

# Problem 3
p3 = function(a) {
  A = matrix(runif(a[1] * a[2]), ncol = a[2])
  t = 0.5 * log(A)
  v = matrix(runif(a[1] * a[2]), ncol = a[2])
  change_place = which(v >= 0.5)
  t[change_place] = -t[change_place]
  return(t)
}

# Problem 4
p4 = function(a) {
  f = function(x) {
    return(30*(x^2-2*x^3+x^4))
  }
  A = matrix(rep(0, a[1] * a[2]), ncol = a[2])
  c = 30/16
  for(i in 1:a[1]) {
    for(j in 1:a[2]) {
      while(1) {
        u = runif(1)
        y = runif(1)
        if(u <= f(y)/c) {
          A[i, j] = y
          break
        }
      }
    }
  }
  return(A)
}

# Problem 5
p5 = function(a, lambda) {
  f = function(x) {
    return(0.5 * x^2 *exp(-x))
  }
  g = function(x) {
    return(lambda * exp(-lambda * x))
  }
  c = 2/(lambda * (1-lambda)^2) * exp(-2)
  A = matrix(rep(0, a[1] * a[2]), ncol = a[2])
  for(i in 1:a[1]) {
    for(j in 1:a[2]) {
      while(1) {
        u = runif(1)
        y = -1/lambda * log(u)
        v = runif(1)
        if(v < f(y)/(c*g(y))) {
          A[i, j] = y
          break
        }
      }
    }
  }
  return(A)
}