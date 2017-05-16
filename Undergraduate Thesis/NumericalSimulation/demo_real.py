# from simulation import *
from simulation_real import *
from theoretical import *
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from simulation2 import Monte_Carlo

inteval = [0, 0.2]
step = 1e-3
start = 0
t = np.arange(inteval[0], inteval[1], step)
n = 100000

## simulation results ###
data = MC(n, t)
mean, var, cov = stat(data)

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

theo_mean = [E_u, E_b, E_gamma]
theo_var = [Var_u, Var_b, Var_gamma]
theo_cov = [Cov_u_u_star, Cov_u_gamma, Cov_u_b, Cov_u_b_star]

labels_mean = ['u', 'b', 'gamma']
labels_var = ['u', 'b', 'gamma']
labels_cov = ['Cov(u, u*)', 'Cov(u, gamma)', 'Cov(u, b)', 'Cov(u, b*)']
### Plot ###
### Expectations ###

for i in range(3):
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
	plt.figure(3+i)
	plt.title('Variance of ' + labels_var[i])
	l1, = plt.plot(t[::EM_STEP], var[i][::EM_STEP])
	l2, = plt.plot(t[::EM_STEP], theo_var[i][::EM_STEP])
	plt.ylabel(labels_var[i])
	plt.legend((l1, l2), ('Simulation', 'Theoretical'))
	plt.xlabel('time')
	plt.show()
	
## Covariances ###
for i in range(4):
	plt.figure(6+i)
	plt.title(labels_cov[i])
	l1, = plt.plot(t[::EM_STEP], cov[i][::EM_STEP])
	l2, = plt.plot(t[::EM_STEP], theo_cov[i][::EM_STEP])
	plt.ylabel(labels_cov[i])
	plt.legend((l1, l2), ('Simulation', 'Theoretical'))
	plt.xlabel('time')
	plt.show()