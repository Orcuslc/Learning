import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import ode

class ZNN:
	def __init__(self, Pt, Qt, dPt, dQt):
		xi, p = 4, 3
		self.powersigmoid, self.dpowersigmoid = self._powersigmoid(xi, p), self._dpowersigmoid(xi, p)
		self.gamma = 1
		self.P, self.Q = Pt, Qt
		self.dP, self.dQ = dPt, dQt

	def _powersigmoid(self, xi, p):
		def ps(X, xi = xi, p = p):
			r = (1+np.exp(-xi))/(1-np.exp(xi))*(1-np.exp(-xi*X))/(1+np.exp(-xi*X))
			place = np.where(abs(X) >= 1)
			r[place] = np.power(X[place], p)
			return r
		return ps

	def _dpowersigmoid(self, xi, p):
		def dps(xi, p, X):
			r = (1+np.exp(-xi))/(1-np.exp(xi))*(2*xi*np.exp(-xi*X))/((1+np.exp(-xi*X))**2)
			place = np.where(X >= 1)
			r[place] = p*np.power(X[place], p-1)
			return r
		return dps

	def _righthand_side(self, t, X, func):
		X = np.asmatrix(X).reshape(X.size, 1)
		return self.P(t).I * (-self.dP(t)*X-self.gamma*func(self.P(t)*X+self.Q(t))-self.dQ(t))

	def construct_solver(self, func):
		initial_x = np.random.randn(self.Q(0).size, 1)
		# initial_x = np.zeros((self.Q(0).size, 1))
		initial_t = 0
		self.solver = ode(self._righthand_side).set_integrator('dopri5', nsteps = 100)
		self.solver.set_initial_value(initial_x, initial_t)
		self.solver.set_f_params(func)

	###############################################
	#		The parts for setting parameters	  #
	###############################################
	def set_ps(self, xi, p):
		self.powersigmoid, self.dpowersigmoid = self._powersigmoid(xi, p), self._dpowersigmoid(xi, p)

	def set_parameter(self, gamma):
		self.gamma = gamma

def Q(t):	
	return np.matrix([[np.sin(t)], [np.cos(t)]])

def P(t):
	return np.matrix([[0.5*np.sin(t)+2, np.cos(t)], [np.cos(t), 0.5*np.cos(t)+2]])

def dQ(t):
	return np.matrix([[np.cos(t)], [-np.sin(t)]])

def dP(t):
	return np.matrix([[0.5*np.cos(t), -np.sin(t)], [-np.sin(t), -0.5*np.sin(t)]])

znn = ZNN(P, Q, dP, dQ)
znn.construct_solver(znn.powersigmoid)

x1 = []
x2 = []
at = []

while znn.solver.successful() and znn.solver.t < 100:
	#znn.solver.t+1
	at.append(znn.solver.t)
	x = znn.solver.integrate(znn.solver.t+0.1)
	x1.append(x[0, 0])
	x2.append(x[1, 0])
	
a = plt.subplot(211)
a.plot(at, x1)
b = plt.subplot(212)
b.plot(at, x2)
plt.show()