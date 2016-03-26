em_FUNC <- function(x, mu, sigma) {
  n = ncol(t(matrix(x)))
  res = 1/((sqrt(2*pi))^n * sqrt(abs(det(sigma)))) * exp(-1/2 * (x-mu)%*%solve(sigma)%*%t(x-mu))
  return (res)
}
