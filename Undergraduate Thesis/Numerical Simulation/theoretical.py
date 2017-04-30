import numpy as np
import scipy as sp
from scipy.integrate import quad
from simulation import *

######### Configurations #########
b_hat = b_hat_re + 1j*b_hat_im
b_hat_star = b_hat_re - 1j*b_hat_im
cov_u0_u0_star = 2
cov_u0_gamma0 = 0
cov_u0_b0 = 0
cov_u0_b0_star = 0

lambda_hat = -gamma_hat + 1j*omega
lambda_b = -gamma_b + 1j*omega_b
##################################

def brownian(inteval, step):
	time = np.arange(inteval[0], inteval[1], step)
	W = np.zeros(time.shape)
	dW = np.sqrt(step)*randn()
	W[0] = dW
	for i in range(1, len(time)):
		dW = np.sqrt(step)*randn();
		W[i] = W[i-1]+dW;
	return W

def intepolate_brownian(func, inteval, step):
	pass

real = lambda x: sp.real(x)
imag = lambda x: sp.imag(x)

def complex_quad(func, a, b, **kwargs):
	real_quad = quad(lambda x: real(func(x)), a, b, **kwargs)
	imag_quad = quad(lambda x: imag(func(x)), a, b, **kwargs)
	return real_quad[0] + 1j*imag_quad[0]

E_J = lambda s, t: 1/d_gamma*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))*(-gamma_hat)
Var_J = lambda s, t: 1/(d_gamma**2)*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))**2 - (sigma_gamma**2)/(d_gamma**3)*(1+d_gamma*(s-t)+np.exp(-d_gamma*(s+t))*(-1-np.exp(2*d_gamma*s)+np.cosh(d_gamma*(s-t))))
E_u = lambda t: complex_quad(lambda s: np.exp(lambda_hat*(t-s))*(b_hat+np.exp(lambda_b*s)*(-b_hat))*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t) + complex_quad(lambda s: np.exp(lambda_hat*(t-s))*f(s)*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t)
E_b = lambda t: b_hat + (-b_hat)*np.exp(lambda_b*t)
E_gamma = lambda t: gamma_hat + (-gamma_hat)*np.exp(-d_gamma*t)
Var_b = lambda t: np.exp(-2*gamma_b*t) + (sigma_b**2)/(2*gamma_b)*(1-np.exp(-2*gamma_b*t))
Var_gamma = lambda t: np.exp(-2*d_gamma*t) + (sigma_gamma**2)/(2*d_gamma)*(1-np.exp(-2*d_gamma*t))