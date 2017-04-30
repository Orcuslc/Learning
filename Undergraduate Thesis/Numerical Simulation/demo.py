from simulation import *
from theoretical import *
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from simulation2 import Monte_Carlo

inteval = [0, 0.2]
step = 1e-3
start = 0
t = np.arange(inteval[0], inteval[1], step)
n = 10000

## simulation results ###
data = MC(n, t)
mean, var = stat(data)
[E_u_re_sim, E_u_im_sim, E_b_re_sim, E_b_im_sim, E_gamma_sim] = mean
[Var_u_re_sim, Var_u_im_sim, Var_b_re_sim, Var_b_im_sim, Var_gamma_sim] = var

## theoretical results ###
E_u = [E_u(i) for i in t]
# Var_u = Var_u(t)
E_b = [E_b(i) for i in t]
E_gamma = [E_gamma(i) for i in t]
Var_b = [Var_b(i) for i in t]
Var_gamma = [Var_gamma(i) for i in t]

theo = [real(E_u), imag(E_u), real(E_b), imag(E_b), E_gamma]
labels = ['Re(u)', 'Im(u)', 'Re(b)', 'Im(b)', 'gamma']
### Expectations ###
plt.figure(1)
for i in range(5):
	plt.subplot(510+i+1)
	plt.plot(t[::EM_STEP], mean[i][::EM_STEP])
	plt.plot(t[::EM_STEP], theo[i][::EM_STEP])
	plt.ylabel(labels[i])
plt.xlabel('time')
plt.show()
