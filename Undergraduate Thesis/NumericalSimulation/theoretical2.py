# from generate import *
import numpy as np
import scipy
from simulation2 import *
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
	dW = np.sqrt(step)*randn()
	W[0] = dW
	for i in range(1, len(time)):
		dW = np.sqrt(step)*randn();
		W[i] = W[i-1]+dW;
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
Var_J = lambda s, t: 1/(d_gamma**2)*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))**2 - (sigma_gamma**2)/(d_gamma**3)*(1+d_gamma*(s-t)+np.exp(-d_gamma*(s+t))*(-1-np.exp(2*d_gamma*s)+np.cosh(d_gamma*(s-t))))

E_u = lambda t: quad(lambda s: np.exp(lambda_hat*(t-s))*(b_hat+np.exp(lambda_b*s)*(-b_hat))*np.exp(-E_J+1/2*Var_J(s, t)), 0, t) + quad(lambda s: np.exp(lambda_hat*(t-s))*f(s)*np.exp(-E_J+1/2*Var_J(s, t)), 0, t)
 # np.exp(lambda_hat*t-E_J+1/2*Var_J(0, t)) + 
# print(E_u(0))

E_b = lambda t: b_hat*(1-np.exp(lambda_b*t))

E_gamma = lambda t: gamma_hat*(1-np.exp(-d_gamma*t))

real = lambda f, t: [scipy.real(f(i)) for i in t]
imag = lambda f, t: [scipy.imag(f(i)) for i in t]



if __name__ == '__main__':
	inteval = [0, 1]
	step = 1e-3
	start = 0
	t = np.arange(inteval[0], inteval[1], step)
	n = 2000
	# W = brownian(inteval, step)
	# plt.plot(t, W)
	# plt.show()
	u_re, u_im, b_re, b_im, gamma = Monte_Carlo(n, t)
	[u_re, u_im, b_re, b_im, gamma, t] = map(lambda x: x[start:], [u_re, u_im, b_re, b_im, gamma, t])

	plt.subplot(511)
	# plt.plot(t, u_re)
	plt.plot(t, real(E_u, t))
	plt.ylabel('Re(u)')

	plt.subplot(512)
	plt.plot(t, u_im)
	plt.plot(t, imag(E_u, t))
	plt.ylabel('Im(u)')

	plt.subplot(513)
	plt.plot(t, b_re)
	plt.plot(t, real(E_b, t))
	plt.ylabel('Re(b)')

	plt.subplot(514)
	plt.plot(t, b_im)
	plt.plot(t, imag(E_b, t))
	plt.ylabel('Im(b)')

	plt.subplot(515)
	plt.plot(t, gamma)
	plt.plot(t, E_gamma(t))
	plt.ylabel('gamma')
	plt.xlabel('time')
	plt.show()
