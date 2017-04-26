import numpy as np
from scipy.integrate import odeint
import random
from matplotlib import pyplot as plt

############# Configuration ############
delta_t = 1e-3 # step
omega, sigma = 2, 1/2
omega_b, sigma_b = 5, 1/2
gamma_b, d_gamma, sigma_gamma = 1, 2, 1/3
gamma_hat, b_hat = 1, 2

def f(t):
	return np.sin(t)
########################################

def complex_white_noise():
	return white_noise() + 1j*white_noise()

def white_noise():
	return random.normalvariate(0, 1)

def func(vec, t):
	u, b, gamma = vec.tolist()
	return (-gamma+1j*omega)*u+b+f(t)+sigma*complex_white_noise(), \
		(-gamma_b+1j*omega_b)*(b-b_hat)+sigma_b*complex_white_noise(), \
		-d_gamma*(gamma-gamma_hat)+sigma_gamma*white_noise()

t = np.arange(0, 10, 0.02)
u_0 = complex_white_noise()
b_0 = complex_white_noise()
gamma_0 = white_noise()

track = odeint(func, (u_0, b_0, gamma_0), t)
print(track)
# Plotting
# fig = plt.figure()
# ax = 