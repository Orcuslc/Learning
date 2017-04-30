import numpy as np
from scipy.integrate import odeint
import random
from matplotlib import pyplot as plt

############# Parameters ###############
d = 1.5
sigma = 0.1549
omega = 1.78
gamma_b = 0.1*d
sigma_gamma = 5*sigma
sigma_b = 5*sigma
omega_b = omega
b_hat_re = 0
b_hat_im = 0
d_gamma = 0.01*d
gamma_hat = 0

def f(t):
	return 0
########################################

def randn():
	return random.normalvariate(0, 1)

def func(vec, t):
	u_re, u_im, b_re, b_im, gamma = vec.tolist()
	return -gamma*u_re-omega*u_im+b_re+f(t)+sigma*randn(), \
			omega*u_re-gamma*u_im+b_im+sigma*randn(), \
			-gamma_b*(b_re-b_hat_re)-omega_b*(b_im-b_hat_im)+sigma_b*randn(), \
			-gamma_b*(b_im-b_hat_im)+omega_b*(b_re-b_hat_re)+sigma_b*randn(), \
			-d_gamma*(gamma-gamma_hat)+sigma_gamma*randn()

def func_(vec, t):
	u_re, u_im, b_re, b_im = vec.tolist()
	return -d*u_re-omega*u_im+b_re+sigma*randn(), \
			omega*u_re-d*u_im+b_im+sigma*randn(), \
			-gamma_b*(b_re-b_hat_re)-omega_b*(b_im-b_hat_im)+sigma_b*randn(), \
			-gamma_b*(b_im-b_hat_im)+omega_b*(b_re-b_hat_re)+sigma_b*randn()

######### Parameters for Computation ##########
NUM_POINT = 200
END = 0.2
t = np.arange(0, END, END/NUM_POINT)
###############################################

def kernel0(t):
	u_0_re = randn()
	u_0_im = randn()
	b_0_re = randn()
	b_0_im = randn()
	gamma_0 = randn()
	track = odeint(func, (u_0_re, u_0_im, b_0_re, b_0_im, gamma_0), t)
	track_i = lambda i: np.asarray([point[i] for point in track])
	return tuple([track_i(i) for i in range(5)])

def kernel(t):
	u_0_re = randn()
	u_0_im = randn()
	b_0_re = randn()
	b_0_im = randn()
	gamma_0 = randn()
	u_re = np.zeros(t.size)
	u_im = np.zeros(t.size)
	b_re = np.zeros(t.size)
	b_im = np.zeros(t.size)
	gamma = np.zeros(t.size)
	u_re[0] = u_0_re
	u_im[0] = u_0_im
	b_re[0] = b_0_re
	b_im[0] = b_0_im
	gamma[0] = gamma_0
	for i in range(1, t.size):
		dt = t[i] - t[i-1]
		stp = np.sqrt(dt)
		du_re = -gamma[i-1]*u_re[i-1]-omega*u_im[i-1]+b_re[i-1]+f(t[i-1])+sigma*randn()
		du_im = omega*u_re[i-1]-gamma[i-1]*u_im[i-1]+b_im[i-1]+sigma*randn()
		db_re = -gamma_b*(b_re[i-1]-b_hat_re)-omega_b*(b_im[i-1]-b_hat_im)+sigma_b*randn()
		db_im = -gamma_b*(b_im[i-1]-b_hat_im)+omega_b*(b_re[i-1]-b_hat_re)+sigma_b*randn()
		dgamma = -d_gamma*(gamma[i-1]-gamma_hat)+sigma_gamma*randn()
		u_re[i] = u_re[i-1]+du_re*dt
		u_im[i] = u_im[i-1]+du_im*dt
		b_re[i] = b_re[i-1]+db_re*dt
		b_im[i] = b_im[i-1]+db_im*dt
		gamma[i] = gamma[i-1] + dgamma*dt
	return u_re, u_im, b_re, b_im, gamma


def Monte_Carlo(n, t):
	NUM_POINT = len(t)
	u_re, u_im, b_re, b_im, gamma = np.zeros(NUM_POINT), np.zeros(NUM_POINT), np.zeros(NUM_POINT), np.zeros(NUM_POINT), np.zeros(NUM_POINT)
	for i in range(n):
		u_re_, u_im_, b_re_, b_im_, gamma_ = kernel(t)
		u_re += u_re_
		u_im += u_im_
		b_re += b_re_
		b_im += b_im_
		gamma += gamma_
	return u_re/n, u_im/n, b_re/n, b_im/n, gamma/n

def Monte_Carlo_(n, t):
	NUM_POINT = len(t)
	u_re, u_im, b_re, b_im = np.zeros(NUM_POINT), np.zeros(NUM_POINT), np.zeros(NUM_POINT), np.zeros(NUM_POINT)
	for i in range(n):
		u_0_re = randn()
		u_0_im = randn()
		b_0_re = randn()
		b_0_im = randn()
		track = odeint(func_, (u_0_re, u_0_im, b_0_re, b_0_im), t)
		track_ = lambda i: np.asarray([ts[i] for ts in track])
		u_re += track_(0)
		u_im += track_(1)
		b_re += track_(2)
		b_im += track_(3)
	return u_re/n, u_im/n, b_re/n, b_im/n

def plot(n, t):
	u_re, u_im, b_re, b_im, gamma = Monte_Carlo(n, t)
	plt.subplot(511)
	plt.plot(t, u_re)
	plt.ylabel('Re(u)')

	plt.subplot(512)
	plt.plot(t, u_im)
	plt.ylabel('Im(u)')

	plt.subplot(513)
	plt.plot(t, b_re)
	plt.ylabel('Re(b)')

	plt.subplot(514)
	plt.plot(t, b_im)
	plt.ylabel('Im(b)')

	plt.subplot(515)
	plt.plot(t, gamma)
	plt.ylabel('gamma')
	plt.xlabel('time')
	plt.show()

def plot_(n, t):
	u_re, u_im, b_re, b_im = Monte_Carlo_(n, t)
	plt.subplot(411)
	plt.plot(t, u_re)
	plt.ylabel('Re(u)')

	plt.subplot(412)
	plt.plot(t, u_im)
	plt.ylabel('Im(u)')

	plt.subplot(413)
	plt.plot(t, b_re)
	plt.ylabel('Re(b)')

	plt.subplot(414)
	plt.plot(t, b_im)
	plt.ylabel('Im(b)')

	plt.xlabel('time')
	plt.show()

if __name__ == '__main__':
	# plot_(2000, t)
	plot(5000, t)