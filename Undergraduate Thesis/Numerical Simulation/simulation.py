import numpy as np
import scipy as sp
import random as rd
from simulation2 import kernel

############# Parameters ###############
d = 1.5
sigma = 0.1549
omega = 1.78
gamma_b = 0.1*d
sigma_gamma = 5*sigma
sigma_b = 5*sigma
omega_b = omega
b_hat_re = 0.2
b_hat_im = 0.2
d_gamma = 0.1*d
gamma_hat = 1.5
EM_STEP = 1
############## Func Paras ##############
f = lambda t: 1.5*np.exp(0.1*1j*t)
randn = lambda : rd.normalvariate(0, 1)
########################################

def simulation(t):
	[u_re, u_im, b_re, b_im, gamma] = [np.zeros(t.size) for i in range(5)]
	[u_re[0], u_im[0], b_re[0], b_im[0], gamma[0]] = [randn() for i in range(5)]
	# b_re[0] += b_hat_re
	# b_im[0] += b_hat_im
	# gamma[0] += gamma_hat
	for i in range(EM_STEP, t.size, EM_STEP):
		dt = t[i] - t[i-EM_STEP]
		stp = np.sqrt(dt)/np.sqrt(EM_STEP)
		u_re[i] = u_re[i-1] + (-gamma[i-1]*u_re[i-1]-omega*u_im[i-1]+sp.real(f(t[i-1])))*dt + sigma*sum([randn() for i in range(EM_STEP)])*stp
		u_im[i] = u_im[i-1] + (-gamma[i-1]*u_im[i-1]+omega*u_re[i-1]+sp.imag(f(t[i-1])))*dt + sigma*sum([randn() for i in range(EM_STEP)])*stp
		b_re[i] = b_re[i-1] + (-gamma_b*(b_re[i-1]-b_hat_re)-omega_b*(b_im[i-1]-b_hat_im))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp
		b_im[i] = b_im[i-1] + (-gamma_b*(b_im[i-1]-b_hat_im)+omega_b*(b_re[i-1]-b_hat_re))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp
		gamma[i] = gamma[i-1] + (-d_gamma*(gamma[i-1]-gamma_hat))*dt + sigma_gamma*sum([randn() for i in range(EM_STEP)])*stp
	return u_re, u_im, b_re, b_im, gamma

def MC(n, t):
	[u_re, u_im, b_re, b_im, gamma] = [np.zeros((n, t.size)) for i in range(5)]
	for i in range(n):
		u_re[i,:], u_im[i,:], b_re[i,:], b_im[i,:], gamma[i,:] = simulation(t)
	return [u_re, u_im, b_re, b_im, gamma]

def stat(data):
	mean = list(map(lambda x: np.mean(x, axis = 0), data))
	var = list(map(lambda x: np.var(x, axis = 0), data))
	return mean, var
