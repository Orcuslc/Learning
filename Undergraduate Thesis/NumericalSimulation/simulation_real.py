import numpy as np
import scipy as sp
import random as rd

d = 1.5
sigma = 0.1549
omega = 0
gamma_b = 0.1*d
sigma_gamma = 5*sigma
sigma_b = 5*sigma
omega_b = omega
b_hat = 0.2
# b_hat_im = 0.2
d_gamma = 0.1*d
gamma_hat = 1.5
EM_STEP = 1

# f = lambda t: 1.5*np.exp(0.1*1j*t)
f = lambda t: 1.5*np.exp(0.1*t)
randn = lambda : rd.normalvariate(0, 1)
conj = sp.conj

def simulation(t):
	[u, b, gamma] = [np.zeros(t.size) for i in range(3)]
	[u[0], b[0], gamma[0]] = [randn() for i in range(3)]
	for i in range(EM_STEP, t.size, EM_STEP):
		dt = t[i] - t[i-EM_STEP]
		stp = np.sqrt(dt)/np.sqrt(EM_STEP)
		u[i] = u[i-1] + (-gamma[i-1]*u[i-1]+b[i-1]+f(t[i-1]))*dt + sigma*sum([randn() for i in range(EM_STEP)])*stp
		b[i] = b[i-1] + (-gamma_b*(b[i] - b_hat))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp
		gamma[i] = gamma[i-1] + (-d_gamma*(gamma[i-1]-gamma_hat)) + sigma_gamma*sum([randn() for i in range(EM_STEP)])*stp
	return u, b, gamma

def MC(n, t):
	[u, b, gamma] = [np.zeros((n, t.size)) for i in range(3)]
	for i in range(n):
		u[i, :], b[i, :], gamma[i, :] = simulation(t)
	return [u, b, gamma]

def stat(data):
	mean = list(map(lambda x: np.mean(x, axis = 0), data))
	var = list(map(lambda x: np.var(x, axis = 0, ddof = 1), data))
	col = data[0].shape[1]
	cov_u_u_star = [np.cov(data[0][:, i], data[0][:, i])[0, 0] for i in range(col)]
	cov_u_gamma = [np.cov(data[0][:, i], data[2][:, i])[0, 0] for i in range(col)]
	cov_u_b = [np.cov(data[0][:, i], data[1][:, i])[0, 0] for i in range(col)]
	cov_u_b_star = [np.cov(data[0][:, i], data[1][:, i])[0, 0] for i in range(col)]
	return mean, var, [cov_u_u_star, cov_u_gamma, cov_u_b, cov_u_b_star]
