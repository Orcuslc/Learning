import numpy as np
from scipy.integrate import odeint
import random
from matplotlib import pyplot as plt

############# Configuration ############
omega, sigma = 1/2, 1/20
omega_b, sigma_b = 1/5, 1/20
gamma_b, d_gamma, sigma_gamma = 1/100, 1/2, 1/3
gamma_hat, b_hat_re, b_hat_im = 1, 2, 1
NUM_POINT = 1000
END = 10
t = np.arange(0, END, END/NUM_POINT)
def f(t):
	return 1/4*np.sin(t)
########################################

def complex_white_noise():
	return white_noise() + 1j*white_noise()

def white_noise():
	return random.normalvariate(0, 1)

def func(vec, t):
	u_re, u_im, b_re, b_im, gamma = vec.tolist()
	return (-gamma*u_re-omega*u_im+b_re+f(t)+sigma*white_noise(), \
			omega*u_re-gamma*u_im+b_im+sigma*white_noise(), \
			-gamma_b*(b_re-b_hat_re)-omega_b*(b_im-b_hat_im)+sigma_b*white_noise(), \
			-gamma_b*(b_im-b_hat_im)+omega_b*(b_re-b_hat_re)+sigma_b*white_noise(), \
			-d_gamma*(gamma-gamma_hat)+sigma_gamma*white_noise()
			)

def Monte_Carlo(n):
	u_re = u_im = b_re = b_im = gamma = np.zeros(NUM_POINT)
	for i in range(n):
		u_0_re = white_noise()
		u_0_im = white_noise()
		b_0_re = white_noise()
		b_0_im = white_noise()
		gamma_0 = white_noise()
		track = odeint(func, (u_0_re, u_0_im, b_0_re, b_0_im, gamma_0), t)
		track_i = lambda i: np.asarray([point[i] for point in track])
		u_re += track_i(0)
		u_im = track_i(1)
		b_re = track_i(2)
		b_im = track_i(3)
		gamma = track_i(4)
	return u_re/n, u_im/n, b_re/n, b_im/n, gamma/n



# Plotting
def plot(n):
	u_re, u_im, b_re, b_im, gamma = Monte_Carlo(n)
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

# from matplotlib.figure import Figure
# from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas

# fig = Figure()
# canvas = FigureCanvas(fig)
# ax = fig.add_axes([0.1, 0.1, 0.9, 0.9])

if __name__ == '__main__':
	plot(100)