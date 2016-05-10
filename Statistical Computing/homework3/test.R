# TEST
source("main.R")

# Problem 1.1
lambda = 0.5
k = 4
a = matrix(c(1, 10000))
# r1 = p11(a, lambda, k)
# hist(r1)
# 
# Problem 1.2
# r2 = p12(a, lambda, k)
# hist(r2)

# Problem 2
# r3 = p2(a)
# hist(r3)

# Problem 3
# r3 = p3(a)
# hist(r3)

# Problem 4
r4 = p4(a)
hist(r4)

# Problem 5
r5 = p5(a, lambda = 0.5)
hist(r5)