import numpy as np
import matplotlib.pyplot as plt

labels_cov_save = ['Re(Cov(u, u_star))', 'Im(Cov(u, u_star))', 'Re(Cov(u, gamma))', 'Im(Cov(u, gamma))', 'Re(Cov(u, b))', 'Im(Cov(u, b))', 'Re(Cov(u, b_star))', 'Im(Cov(u, b_star))']
labels_cov = ['Re(Cov(u, u*))', 'Im(Cov(u, u*))', 'Re(Cov(u, gamma))', 'Im(Cov(u, gamma))', 'Re(Cov(u, b))', 'Im(Cov(u, b))', 'Re(Cov(u, b*))', 'Im(Cov(u, b*))']

x = np.linspace(0, 0.2, 200)
for i in range(8):
	plt.figure(i)
	sim = np.load(labels_cov_save[i]+'_sim.npy')
	theo = np.load(labels_cov_save[i]+'_theo.npy')
	l1, = plt.plot(x, sim)
	l2, = plt.plot(x, theo)
	plt.title(labels_cov[i])
	plt.ylabel(labels_cov[i])
	plt.xlabel('time')
	plt.legend((l1, l2), ('Simulation', 'Theoretical'))
	if i in [0, 1, 2, 3]:
		plt.ylim((-0.1, 0.05))
	elif i in [5, 6, 7]:
		plt.ylim((-0.01, 0.01))
	plt.show()
