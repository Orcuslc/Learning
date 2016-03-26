GMM_FUNC <- function(x, mu, sigma) {
  1/(sqrt(2*pi) * sigma) * exp(-((x - mu)^2) / (2*(sigma^2)))
}