import numpy as np
import scipy as sp
import random as rd
from simulation2 import kernel
# from theoretical import real, imag

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

conj = sp.conj

def simulation(t):
	[u_re, u_im, b_re, b_im, gamma] = [np.zeros(t.size) for i in range(5)]
	# [u_re[0], u_im[0], b_re[0], b_im[0], gamma[0]] = [randn() for i in range(5)]
	gamma[0] = randn()
	[u_re[0], u_im[0], b_re[0], b_im[0]] = [randn()/np.sqrt(2) for i in range(4)]
	# b_re[0] += b_hat_re
	# b_im[0] += b_hat_im
	# gamma[0] += gamma_hat
	for i in range(EM_STEP, t.size, EM_STEP):
		dt = t[i] - t[i-EM_STEP]
		stp = np.sqrt(dt)/np.sqrt(EM_STEP)
		u_re[i] = u_re[i-1] + (-gamma[i-1]*u_re[i-1]-omega*u_im[i-1]+b_re[i-1]+sp.real(f(t[i-1])))*dt + sigma*sum([randn() for i in range(EM_STEP)])*stp/np.sqrt(2)
		u_im[i] = u_im[i-1] + (-gamma[i-1]*u_im[i-1]+omega*u_re[i-1]+b_im[i-1]+sp.imag(f(t[i-1])))*dt + sigma*sum([randn() for i in range(EM_STEP)])*stp/np.sqrt(2)
		b_re[i] = b_re[i-1] + (-gamma_b*(b_re[i-1]-b_hat_re)-omega_b*(b_im[i-1]-b_hat_im))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp*1/np.sqrt(2)
		b_im[i] = b_im[i-1] + (-gamma_b*(b_im[i-1]-b_hat_im)+omega_b*(b_re[i-1]-b_hat_re))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp*1/np.sqrt(2)
		gamma[i] = gamma[i-1] + (-d_gamma*(gamma[i-1]-gamma_hat))*dt + sigma_gamma*sum([randn() for i in range(EM_STEP)])*stp
	return u_re, u_im, b_re, b_im, gamma

def simulation_half_step(t):
	[u_re, u_im, b_re, b_im, gamma] = [np.zeros(t.size) for i in range(5)]
	gamma[0] = randn()
	[u_re[0], u_im[0], b_re[0], b_im[0]] = [randn()/np.sqrt(2) for i in range(4)]
	for i in range(EM_STEP, t.size, EM_STEP):
		dt = t[i] - t[i-EM_STEP]
		stp = np.sqrt(dt)/np.sqrt(EM_STEP)
		gamma[i] = gamma[i-1] + (-d_gamma*(gamma[i-1]-gamma_hat))*dt + sigma_gamma*sum([randn() for i in range(EM_STEP)])*stp
		b_re[i] = b_re[i-1] + (-gamma_b*(b_re[i-1]-b_hat_re)-omega_b*(b_im[i-1]-b_hat_im))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp*1/np.sqrt(2)
		b_im[i] = b_im[i-1] + (-gamma_b*(b_im[i-1]-b_hat_im)+omega_b*(b_re[i-1]-b_hat_re))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp*1/np.sqrt(2)
		gamma_half = (gamma[i]+gamma[i-1])/2
		b_re_half = (b_re[i]+b_re[i-1])/2
		b_im_half = (b_im[i]+b_im[i-1])/2
		t_half = (t[i]+t[i-1])/2
		u_re[i] = u_re[i-1] + (-gamma_half*u_re[i-1]-omega*u_im[i-1]+sp.real(f(t_half)))*dt + sigma*sum([randn() for i in range(EM_STEP)])*stp/np.sqrt(2)
		u_im[i] = u_im[i-1] + (-gamma_half*u_im[i-1]+omega*u_re[i-1]+sp.real(f(t_half)))*dt + sigma*sum([randn() for i in range(EM_STEP)])*stp/np.sqrt(2)
		b_re[i] = b_re[i-1] + (-gamma_b*(b_re[i-1]-b_hat_re)-omega_b*(b_im[i-1]-b_hat_im))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp*1/np.sqrt(2)
		b_im[i] = b_im[i-1] + (-gamma_b*(b_im[i-1]-b_hat_im)+omega_b*(b_re[i-1]-b_hat_re))*dt + sigma_b*sum([randn() for i in range(EM_STEP)])*stp*1/np.sqrt(2)
		gamma[i] = gamma[i-1] + (-d_gamma*(gamma[i-1]-gamma_hat))*dt + sigma_gamma*sum([randn() for i in range(EM_STEP)])*stp
	return u_re, u_im, b_re, b_im, gamma

def MC(n, t):
	[u_re, u_im, b_re, b_im, gamma] = [np.zeros((n, t.size)) for i in range(5)]
	for i in range(n):
		u_re[i,:], u_im[i,:], b_re[i,:], b_im[i,:], gamma[i,:] = simulation(t)
	return [u_re, u_im, b_re, b_im, gamma]

def _stat_(data):
	mean = list(map(lambda x: np.mean(x, axis = 0), data))
	data2 = [data[0]+1j*data[1],data[2]+1j*data[3], data[4]]
	data2_abs = [abs(i)**2 for i in data2]
	data2_abs_mean = list(map(lambda x: np.mean(x, axis = 0), data2_abs))
	mean2 = list(map(lambda x: np.mean(x, axis = 0), data2))
	mean2_abs = [abs(i)**2 for i in mean2]
	var = [data2_abs_mean[i] - mean2_abs[i] for i in range(3)]
	return mean, var

def stat(data):
	mean = list(map(lambda x: np.mean(x, axis = 0), data))
	var = list(map(lambda x: np.var(x, axis = 0, ddof = 1), data))
	col = data[0].shape[1]
	# Cov_u_u_star_re = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[0][:, i]-1j*data[1][:, i])[0] for i in range(col)])
	# Cov_u_u_star_im = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[0][:, i]-1j*data[1][:, i])[1] for i in range(col)])
	# Cov_u_gamma_re = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[4][:, i])[0] for i in range(col)])
	# Cov_u_gamma_im = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[4][:, i])[1] for i in range(col)])
	# Cov_u_b_re = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[2][:, i]+1j*data[3][:, i])[0] for i in range(col)])
	# Cov_u_b_im = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[2][:, i]+1j*data[3][:, i])[1] for i in range(col)])
	# Cov_u_b_star_re = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[2][:, i]-1j*data[3][:, i])[0] for i in range(col)])
	# Cov_u_b_star_im = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[2][:, i]-1j*data[3][:, i])[1] for i in range(col)])
	Cov_u_u_star = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[0][:, i]-1j*data[1][:, i]) for i in range(col)], dtype=np.complex64)
	Cov_u_gamma = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[4][:, i]) for i in range(col)], dtype=np.complex64)
	Cov_u_b = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[2][:, i]+1j*data[3][:, i]) for i in range(col)], dtype=np.complex64)
	Cov_u_b_star = np.asarray([cov(data[0][:, i]+1j*data[1][:, i], data[2][:, i]-1j*data[3][:, i]) for i in range(col)], dtype=np.complex64)
	return mean, [var[0]+var[1], var[2]+var[3], var[4]], [sp.real(Cov_u_u_star), sp.imag(Cov_u_u_star), sp.real(Cov_u_gamma), sp.imag(Cov_u_gamma), sp.real(Cov_u_b), sp.imag(Cov_u_b), sp.real(Cov_u_b_star), sp.imag(Cov_u_b_star)]

def cov(x, y):
	# print(x, y)
	# print(x-np.mean(x), y-np.mean(y), (x-np.mean(x))*conj(y-np.mean(y)))
	cov = np.mean((x-np.mean(x))*conj(y-np.mean(y)))
	return cov

def cov_(x, y):
	# return np.mean(x*conj(y)) - np.mean(x)*np.mean(conj(y))
	return np.cov(x, y)[0, 0]

def test(n):
	a = np.asarray([[randn() for i in range(10)] for j in range(n)])
	b = np.asarray([[randn() for i in range(10)] for j in range(n)])
	# print(np.var(a, axis = 0)+np.var(b, axis = 0))
	print([np.cov(a[:,i], b[:,i])[0, 0] for i in range(10)])

def test_cov(n):
	re = np.zeros(n)
	im = np.zeros(n)
	for i in range(n):
		re[i] = randn()/np.sqrt(2)
		im[i] = randn()/np.sqrt(2)
	# print(cov(re+1j*im, re-1j*im))

def test_sim(n, t):
	data = MC(n, t)
	_, _, cov = stat(data)
	print(cov)
	
def test_rd():
	[r1, r2, i1, i2] = [randn() for i in range(4)]
	x = np.asarray([r1+1j*i1, r2+1j*i2])
	y = np.asarray([r1-1j*i1, r2-1j*i2])
	print(cov(x, y))

if __name__ == '__main__':
	t = np.arange(0, 0.2, 1e-1)
	# data = MC(100, t)
	# _, _, cov = stat(data)
	# import matplotlib.pyplot as plt
	# print(cov[0])
	# plt.plot(t, cov[0])
	# plt.show()
	# test_cov(10000)
	# test(1000000)
	test_sim(10, t)
	# test_rd()