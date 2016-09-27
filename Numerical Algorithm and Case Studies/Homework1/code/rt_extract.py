import scipy.optimize as op
f = lambda x: x**2 - 1e8* x + 1
x1 = op.fsolve(f, x0 = 0)
x2 = op.fsolve(f, x0 = 1e9)