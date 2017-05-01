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







# Plotting


# from matplotlib.figure import Figure
# from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas

# fig = Figure()
# canvas = FigureCanvas(fig)
# ax = fig.add_axes([0.1, 0.1, 0.9, 0.9])

if __name__ == '__main__':
	plot(100, t)