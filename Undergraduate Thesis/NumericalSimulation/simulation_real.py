import numpy as np
import scipy as sp
import random as rd

d = 1.5
sigma = 0.1549
omega = 1.78
gamma_b = 0.1*d
sigma_gamma = 5*sigma
sigma_b = 5*sigma
omega_b = omega
b_hat = 0.2
# b_hat_im = 0.2
d_gamma = 0.1*d
gamma_hat = 1.5
EM_STEP = 1

f = lambda t: 1.5*np.exp(0.1*1j*t)
randn = lambda : rd.normalvariate(0, 1)
conj = sp.conj

def simulation(t):
	[u, b, gamma] = [np.zeros(t.size) for i in range(3)]
	[u[0], b[0], gamma[0]] = [randn() for i in range(3)]
	for i in range(EM_STEP, t.size, EM_STEP):
		dt = t[i] - t[i-EM_STEP]
		stp = np.sqrt(dt)/np.sqrt(EM_STEP)
		u[i] = u[i-1] + (-gamma[i-1]+)
