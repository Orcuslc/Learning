# from generate import *
import numpy as np
import scipy
from simulation import *
from matplotlib import pyplot as plt
# import scipy.integrate as integrate
from scipy.integrate import quad as quad1

######### Configurations ############
b_hat = b_hat_re + 1j*b_hat_im
b_hat_star = b_hat_re - 1j*b_hat_im
cov_u0_u0_star = 2
cov_u0_gamma0 = 0
cov_u0_b0 = 0
cov_u0_b0_star = 0

lambda_hat = -gamma_hat + 1j*omega
lambda_b = -gamma_b + 1j*omega_b
#####################################

def brownian(inteval, step):
	time = np.arange(inteval[0], inteval[1], step)
	W = np.zeros(time.shape)
	dW = np.zeros(time.shape)
	dW[0] = np.sqrt(step)*randn()
	W[0] = dW[0]
	for i in range(1, len(time)):
		dW[i] = np.sqrt(step)*randn();
		W[i] = W[i-1]+dW[i];
	return W

def intepolate_brownian(func, inteval, step = 1e-2):
	# Since in definition of It^o integration choose the left side of each inteval
	pass

def quad(func, a, b, **kwargs):
	def real(x):
		return scipy.real(func(x))
	def imag(x):
		return scipy.imag(func(x))
	real_int = quad1(real, a, b, **kwargs)
	imag_int = quad1(imag, a, b, **kwargs)
	return real_int[0]+1j*imag_int[0]

E_J = 0
Var_J = lambda s, t: 1/(d_gamma**2)*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))**2 - sigma_gamma**2/(d_gamma**3)*(1+d_gamma*(s-t)+np.exp(-d_gamma*(s+t))*(-1-np.exp(2*d_gamma*s)+np.cosh(d_gamma*(s-t))))

def E_u(t):
	return np.exp(lambda_hat*t-E_J+1/2*Var_J(0, t)) + quad(lambda s: np.exp(lambda_hat*(t-s))*(b_hat+np.exp(lambda_b*s)*(-b_hat))*np.exp(-E_J+1/2*Var_J(s, t)), 0, t) + quad(lambda s: np.exp(lambda_hat*(t-s))*f(s)*np.exp(-E_J+1/2*Var_J(s, t)), 0, t)


if __name__ == '__main__':
	inteval = [0, 0.2]
	step = 1e-3
	t = np.arange(inteval[0], inteval[1], step)
	n = 10000
	# W = brownian(inteval, step)
	# plt.plot(time, W)
	# plt.show()
	u_re, u_im, b_re, b_im, gamma = Monte_Carlo(n, t)
	plt.subplot(511)
	plt.plot(t, u_re)
	plt.plot(t, [scipy.real(E_u(i)) for i in t])
	plt.ylabel('Re(u)')

	plt.subplot(512)
	plt.plot(t, u_im)
	plt.plot(t, [scipy.imag(E_u(i)) for i in t])
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
