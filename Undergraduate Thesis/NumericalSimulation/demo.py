# from simulation import *
from simulation_real import *
from theoretical import *
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from simulation2 import Monte_Carlo

inteval = [0, 0.2]
step = 1e-2
start = 0
t = np.arange(inteval[0], inteval[1], step)
n = 100

## simulation results ###
data = MC(n, t)
mean, var, cov = stat(data)
[E_u_re_sim, E_u_im_sim, E_b_re_sim, E_b_im_sim, E_gamma_sim] = mean
[Var_u_sim, Var_b_sim, gamma_sim] = var
[Cov_u_u_star_re_sim, Cov_u_u_star_im_sim, Cov_u_u_star_re_sim, Cov_u_u_star_im_sim, Cov_u_b_re_sim, Cov_u_b_im_sim, Cov_u_b_star_re_sim, Cov_u_b_star_im_sim] = cov

## theoretical results ###
E_u = [E_u(i) for i in t]
E_b = [E_b(i) for i in t]
E_gamma = [E_gamma(i) for i in t]

Var_b = [Var_b(i) for i in t]
Var_gamma = [Var_gamma(i) for i in t]
Var_u = [Var_u(i) for i in t]

Cov_u_u_star = [Cov_u_u_star(i) for i in t]
Cov_u_gamma = [Cov_u_gamma(i) for i in t]
Cov_u_b = [Cov_u_b(i) for i in t]
Cov_u_b_star = [Cov_u_b_star(i) for i in t]

theo_mean = [real(E_u), imag(E_u), real(E_b), imag(E_b), E_gamma]
theo_var = [Var_u, Var_b, Var_gamma]
theo_cov = [real(Cov_u_u_star), imag(Cov_u_u_star), real(Cov_u_gamma), imag(Cov_u_gamma), real(Cov_u_b), imag(Cov_u_b), real(Cov_u_b_star), imag(Cov_u_b_star)]

labels_mean = ['Re(u)', 'Im(u)', 'Re(b)', 'Im(b)', 'gamma']
labels_var = ['u', 'b', 'gamma']
labels_cov = ['Re(Cov(u, u*))', 'Im(Cov(u, u*))', 'Re(Cov(u, gamma))', 'Im(Cov(u, gamma))', 'Re(Cov(u, b))', 'Im(Cov(u, b))', 'Re(Cov(u, b*))', 'Im(Cov(u, b*))']
### Plot ###
### Expectations ###

for i in range(5):
	plt.figure(i)
	plt.title('Expectation of '+ labels_mean[i])
	l1, = plt.plot(t[::EM_STEP], mean[i][::EM_STEP], label = 'Simulation')
	l2, = plt.plot(t[::EM_STEP], theo_mean[i][::EM_STEP], label = 'Theoretical')
	plt.ylabel(labels_mean[i])
	plt.legend((l1,l2), ('Simulation', 'Theoretical'))
	plt.xlabel('time')
	plt.show()

# # ## Variances ###
for i in range(3):
	plt.figure(6+i)
	plt.title('Variance of ' + labels_var[i])
	l1, = plt.plot(t[::EM_STEP], var[i][::EM_STEP])
	l2, = plt.plot(t[::EM_STEP], theo_var[i][::EM_STEP])
	plt.ylabel(labels_var[i])
	plt.legend((l1, l2), ('Simulation', 'Theoretical'))
	plt.xlabel('time')
	plt.show()
	
## Covariances ###
for i in range(8):
	plt.figure(9+i)
	plt.title(labels_cov[i])
	l1, = plt.plot(t[::EM_STEP], cov[i][::EM_STEP])
	l2, = plt.plot(t[::EM_STEP], theo_cov[i][::EM_STEP])
	plt.ylabel(labels_cov[i])
	plt.legend((l1, l2), ('Simulation', 'Theoretical'))
	plt.xlabel('time')
	plt.show()