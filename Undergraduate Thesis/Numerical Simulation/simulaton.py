import numpy as np
from scipy.integrate import odeint
import random
from matplotlib import pyplot as plt
from generate import white_noise, func, Monte_Carlo, plot

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

def f(t):
	return 0
########################################

def func_(vec, t):
	u_re, u_im, b_re, b_im = vec.tolist()
	return -d*u_re-omega*u_im+b_re+sigma*white_noise(), \
			omega*u_re-d*u_im+b_im+sigma*white_noise(), \
			-gamma_b*(b_re-b_hat_re)-omega_b*(b_im-b_hat_im)+sigma_b*white_noise(), \
			-gamma_b*(b_im-b_hat_im)+omega_b*(b_re-b_hat_re)+sigma_b*white_noise()

######### Parameters for Computation ##########
NUM_POINT = 1000
END = 500
t = np.arange(0, END, END/NUM_POINT)
###############################################

def Monte_Carlo_(n, t):
	u_re, u_im, b_re, b_im = np.zeros(NUM_POINT), np.zeros(NUM_POINT), np.zeros(NUM_POINT), np.zeros(NUM_POINT)
	for i in range(n):
		u_0_re = white_noise()
		u_0_im = white_noise()
		b_0_re = white_noise()
		b_0_im = white_noise()
		track = odeint(func_, (u_0_re, u_0_im, b_0_re, b_0_im), t)
		track_ = lambda i: np.asarray([ts[i] for ts in track])
		u_re += track_(0)
		u_im += track_(1)
		b_re += track_(2)
		b_im += track_(3)
	return u_re/n, u_im/n, b_re/n, b_im/n

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
	plot(100, t)