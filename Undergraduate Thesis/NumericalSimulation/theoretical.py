import numpy as np
import scipy as sp
from scipy.integrate import quad, dblquad
from simulation import *
# from simulation_real import *

######### Configurations #########
######## Const Init Values #######
Cov_u0_u0_star = 0
Cov_u0_gamma0 = 0 
Cov_u0_b0 = 0 
Cov_u0_b0_star = 0
Cov_b0_b0_star = 0
Cov_u0_star_b0_star = 0
Cov_b0_gamma0 = 0
Var_b0 = 1
Var_u0 = 1 
Var_gamma0 = 1 
E_u0 = 0
E_b0 = 0
E_b0_star = 0
E_gamma0 = 0 
##################################
b_hat = b_hat_re + 1j*b_hat_im
b_hat_star = b_hat_re - 1j*b_hat_im
lambda_hat = -gamma_hat + 1j*omega
lambda_b = -gamma_b + 1j*omega_b
lambda_b_star = -gamma_b - 1j*omega_b
##################################
# b_hat_star = b_hat
# lambda_hat = -gamma_hat
# lambda_b = -gamma_b
# lambda_b_star = -gamma_b

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

def complex_dblquad(func, a, b, gfunc, hfunc, **kwargs):
	real_quad = dblquad(lambda x, y: real(func(x, y)), a, b, gfunc, hfunc, **kwargs)
	imag_quad = dblquad(lambda x, y: imag(func(x, y)), a, b, gfunc, hfunc)
	return real_quad[0] + 1j*imag_quad[0]

E_J = lambda s, t: 1/d_gamma*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))*(E_gamma0-gamma_hat)

Var_J = lambda s, t: 1/(d_gamma**2)*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))**2*Var_gamma0 - (sigma_gamma**2)/(d_gamma**3)*(1+d_gamma*(s-t)+np.exp(-d_gamma*(s+t))*(-1-np.exp(2*d_gamma*s)+np.cosh(d_gamma*(s-t))))

Cov_u0_Jst = lambda s, t: 1/d_gamma*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))*Cov_u0_gamma0

Cov_b0_Jst = lambda s, t: 1/d_gamma*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))*Cov_b0_gamma0

Cov_bt_gammat = lambda t: np.exp((-d_gamma+lambda_b)*t)*Cov_b0_gamma0

E_u = lambda t: np.exp(lambda_hat*t)*(E_u0-Cov_u0_Jst(0, t))*np.exp(-E_J(0, t)+1/2*Var_J(0, t)) + complex_quad(lambda s: np.exp(lambda_hat*(t-s))*(b_hat+np.exp(lambda_b*s)*(-b_hat))*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t) + complex_quad(lambda s: np.exp(lambda_hat*(t-s))*f(s)*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t)

E_b = lambda t: b_hat + (E_b0-b_hat)*np.exp(lambda_b*t)

E_gamma = lambda t: gamma_hat + (E_gamma0-gamma_hat)*np.exp(-d_gamma*t)

Var_b = lambda t: Var_b0*np.exp(-2*gamma_b*t) + (sigma_b**2)/(2*gamma_b)*(1-np.exp(-2*gamma_b*t))

Var_gamma = lambda t: Var_gamma0*np.exp(-2*d_gamma*t) + (sigma_gamma**2)/(2*d_gamma)*(1-np.exp(-2*d_gamma*t))

Cov_Jst_Jrt = lambda t, s, r: Var_J(s, t) + Cov_Jst_Jrs(t, s, r)

Cov_Jst_Jrs = lambda t, s, r: Var_gamma0/(d_gamma**2)*(np.exp(-d_gamma*t)-np.exp(-d_gamma*s))*(np.exp(-d_gamma*s)-np.exp(-d_gamma*r))-(sigma_gamma**2)/(2*d_gamma**3)*(np.exp(-d_gamma*(t-s))-np.exp(-d_gamma*(t-r))+np.exp(-d_gamma*(t+s))-np.exp(-d_gamma*(t+r))-1+np.exp(-d_gamma*(s-r))-np.exp(-2*d_gamma*s)+np.exp(-d_gamma*(s+r)))

E_bs_br_star = lambda s, r: (1-np.exp(lambda_b*s))*(1-np.exp(lambda_b_star*r))*abs(b_hat)**2 + np.exp(-gamma_b*s)*(1-np.exp(lambda_b_star*r))*b_hat_star*E_b0 + np.exp(lambda_b_star*r)*(1-np.exp(lambda_b*s))*b_hat*E_b0_star + np.exp(lambda_b*s)*np.exp(lambda_b_star*r)*(Var_b0 + abs(E_b0)**2) + (sigma_b**2)/(2*gamma_b)*(np.exp(-gamma_b*(s+r-2*min(s, r)))-np.exp(-gamma_b*(s+r)))*np.exp(1j*omega_b*(s-r))

Cov_br_Jst = lambda t, s, r: 1/d_gamma*(np.exp(-d_gamma*s)-np.exp(-d_gamma*t))*np.exp(-lambda_b*r)*Cov_b0_gamma0

conj = np.conj

t1 = lambda s, t: np.exp(-E_J(0, t)-E_J(s, t)+1/2*Var_J(0, t)+1/2*Var_J(s, t)+Cov_Jst_Jrt(t, 0, s)) * (Cov_u0_star_b0_star + conj(E_u0)*E_b0 - conj(E_u0)*(Cov_b0_Jst(0, t)+Cov_b0_Jst(s, t)) - E_b0*conj(Cov_u0_Jst(0, t)+Cov_u0_Jst(s, t)) + (Cov_b0_Jst(0, t)+Cov_b0_Jst(s, t))*conj(Cov_u0_Jst(0, t)+Cov_u0_Jst(s, t)))
t2 = lambda s, t: np.exp(-E_J(0, t)-E_J(s, t)+1/2*Var_J(0, t)+1/2*Var_J(s, t)+Cov_Jst_Jrt(t, 0, s)) * (E_u0-Cov_u0_Jst(0, t)-Cov_u0_Jst(s, t))

def Var_u(t):
	A = np.exp(-2*gamma_hat*t)*(Var_u0)*np.exp(-2*E_J(0, t)+2*Var_J(0, t))
	# B = complex_dblquad(lambda s, r: np.exp(-gamma_hat*(2*t-s-r)+1j*omega*(r-s))*np.exp(-E_J(s, t)-E_J(r, t)+1/2*Var_J(s, t)+1/2*Var_J(r, t)+Cov_Jst_Jrt(t, s, r)) * (E_bs_br_star(s, r) - E_b(s)*(conj(Cov_br_Jst(t, s, r))+conj(Cov_br_Jst(t, r, r))) - conj(E_b(r))*(Cov_br_Jst(t, s, s)+Cov_br_Jst(t, r, s)) + (conj(Cov_br_Jst(t, s, r))+conj(Cov_br_Jst(t, r, r)))*(Cov_br_Jst(t, s, s)+Cov_br_Jst(t, r, s)) + conj(f(r))*(E_b(s)-Cov_br_Jst(t, s, s)) + f(s)*(conj(E_b(r)-conj(Cov_br_Jst(t, s, r)))) + f(s)*conj(f(r))), 0, t, lambda s: 0, lambda s: t)
	B = complex_dblquad(lambda s, r: np.exp(-gamma_hat*(2*t-s-r)+1j*omega*(r-s))*np.exp(-E_J(s, t)-E_J(r, t)+1/2*Var_J(s, t)+1/2*Var_J(r, t)+Cov_Jst_Jrt(t, s, r)) * (E_bs_br_star(s, r) - E_b(s)*(conj(Cov_br_Jst(t, s, r))+conj(Cov_br_Jst(t, r, r))) - conj(E_b(r))*(Cov_br_Jst(t, s, s)+Cov_br_Jst(t, r, s)) + (conj(Cov_br_Jst(t, s, r))+conj(Cov_br_Jst(t, r, r)))*(Cov_br_Jst(t, s, s)+Cov_br_Jst(t, r, s)) + conj(f(r))*(E_b(s)-Cov_br_Jst(t, s, s)-Cov_br_Jst(t, r, s)) + f(s)*(conj(E_b(r))-conj(Cov_br_Jst(t, s, r))-conj(Cov_br_Jst(t, r, r))) + f(s)*conj(f(r))), 0, t, lambda s: 0, lambda s: t)
	C = sigma**2 * complex_quad(lambda s: np.exp(-2*gamma_hat*(t-s))*np.exp(-2*E_J(s, t)+2*Var_J(s, t)), 0, t)
	AB = np.exp(-gamma_hat*t)*(complex_quad(lambda s: np.exp((lambda_b-1j*omega)*s-gamma_hat*(t-s))*t1(s, t), 0, t) + complex_quad(lambda s: np.exp(1j*omega*(-s)-gamma_hat*(t-s))*(b_hat*(1-np.exp(lambda_b*s))+f(s))*conj(t2(s, t)), 0, t))
	return A+B+C+2*real(AB) - abs(E_u(t))**2

E_bs_br = lambda s, r: (1-np.exp(lambda_b*s))*(1-np.exp(lambda_b*r))*b_hat**2 + np.exp(lambda_b*s)*(1-np.exp(lambda_b*r))*b_hat*E_b0 + np.exp(lambda_b*r)*(1-np.exp(lambda_b*s))*b_hat*E_b0 + np.exp(lambda_b*s)*np.exp(lambda_b*r)*(Var_b0*abs(E_b0)**2)

def Cov_u_u_star(t):
	A = np.exp(2*lambda_hat*t)*(E_u0**2+Cov_u0_u0_star-4*E_u0*Cov_u0_Jst(0, t)+4*Cov_u0_Jst(0, t)**2)*np.exp(-2*E_J(0, t)+2*Var_J(0, t))
	B = complex_dblquad(lambda s, r: np.exp(lambda_hat*(2*t-s-r))*np.exp(-E_J(s, t)-E_J(r, t)+1/2*Var_J(s, t)+1/2*Var_J(r, t)+Cov_Jst_Jrt(t, s, r)) * (E_bs_br(s, r) - E_b(s)*(Cov_br_Jst(t, s, r)+Cov_br_Jst(t, r, r)) - E_b(r)*(Cov_br_Jst(t, s, s)+Cov_br_Jst(t, r, s)) + (Cov_br_Jst(t, s, r)+Cov_br_Jst(t, r, r))*(Cov_br_Jst(t, s, s)+Cov_br_Jst(t, r, s)) + f(r)*(E_b(s)-Cov_br_Jst(t, s, s)-Cov_br_Jst(t, r, s)) + f(s)*(E_b(r)-Cov_br_Jst(t, s, r)-Cov_br_Jst(t, r, r)) + f(s)*f(r)), 0, t, lambda s: 0, lambda s: t)
	AB = complex_quad(lambda s: np.exp(lambda_hat*(2*t-s)+lambda_b*s)*(Cov_u0_b0_star + E_u0*E_b0 - E_u0*(Cov_b0_Jst(0, t)+Cov_b0_Jst(s, t)) - E_b0*(Cov_u0_Jst(0, t)+Cov_u0_Jst(s, t)) + (Cov_b0_Jst(0, t)+Cov_b0_Jst(s, t))*(Cov_u0_Jst(0, t)+Cov_u0_Jst(s, t)))*np.exp(-E_J(0, t)-E_J(s, t)+1/2*Var_J(0, t)+1/2*Var_J(s, t)+Cov_Jst_Jrt(t, 0, s)), 0, t) + complex_quad(lambda s: np.exp(lambda_hat*(2*t-s))*(b_hat*(1-np.exp(lambda_b*s))+f(s))*t2(s, t), 0, t)
	# return A+B+2*AB-abs(E_u(t))**2
	return A+B+2*AB-E_u(t)**2

def Cov_u_gamma(t):
	pVar_J = lambda s, t: -1/(d_gamma**2)*(sigma_gamma**2*(np.exp(-d_gamma*(t-s))-1)) + (sigma_gamma**2-2*d_gamma*Var_gamma0)*(np.exp(-d_gamma*(t+s))-np.exp(-2*d_gamma*t))
	A = np.exp(lambda_hat*t)*(0+(E_u0-Cov_u0_Jst(0, t))*(gamma_hat-E_gamma(t)+1/2*pVar_J(0, t)))*np.exp(-E_J(0, t)+1/2*Var_J(0, t))
	B = complex_quad(lambda s: np.exp(lambda_hat*(t-s))*(0+(E_b(s)+f(s)-Cov_br_Jst(t, s, s))*(gamma_hat-E_gamma(t)+1/2*pVar_J(s, t)))*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t)
	return -A-B+E_u(t)*(gamma_hat-E_gamma(t))

def Cov_u_b(t):
	A = E_u(t)*conj(b_hat)*(1-np.exp(conj(lambda_b)*t)) + np.exp((lambda_hat+conj(lambda_b))*t)*(Cov_u0_b0 + E_u0*conj(E_b0)-conj(E_b0)*Cov_u0_Jst(0, t)-E_u0*conj(Cov_b0_Jst(0, t)) + Cov_u0_Jst(0, t)*conj(Cov_b0_Jst(0, t)))*np.exp(-E_J(0, t)+1/2*Var_J(0, t))
	B = np.exp(conj(lambda_b)*t)*complex_quad(lambda s: np.exp(lambda_hat*(t-s))*(np.exp(lambda_b*s)*Var_b0 + E_b(s)*conj(E_b0) - conj(E_b0)*Cov_br_Jst(t, s, s) - E_b(s)*conj(Cov_b0_Jst(s, t)) + Cov_br_Jst(t, s, s)*conj(Cov_b0_Jst(s, t)))*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t)
	C = np.exp(conj(lambda_b)*t)*complex_quad(lambda s: np.exp(gamma_hat*(t-s))*f(s)*conj((E_b0-Cov_b0_Jst(s, t))*np.exp(-E_J(s, t)+1/2*Var_J(s, t))), 0, t)
	D = (sigma_b**2)/(2*gamma_b)*complex_quad(lambda s: np.exp(-E_J(s, t)+1/2*Var_J(s, t))*np.exp((-gamma_hat+1j*(omega-omega_b))*(t-s))*(np.exp(-gamma_b*(t-s))-np.exp(-gamma_b*(s+t))), 0, t)
	return A+B+C+D-E_u(t)*conj(E_b(t))

def Cov_u_b_star(t):
	A = E_u(t)*b_hat*(1-np.exp(lambda_b*t)) + np.exp((lambda_hat+lambda_b)*t)*(Cov_u0_b0_star + E_u0*E_b0 - E_b0*Cov_u0_Jst(0, t) - E_u0*Cov_b0_Jst(0, t) + Cov_u0_Jst(0, t)*Cov_b0_Jst(0, t))*np.exp(-E_J(0, t)+1/2*Var_J(0, t))
	# B = np.exp(lambda_b*t)*complex_quad(lambda s: np.exp(-lambda_hat*(t-s))*(np.exp(lambda_b*s)*Cov_b0_b0_star + E_b(s)*E_b0 - E_b0*Cov_br_Jst(t, s, s) - E_b(s)*Cov_b0_Jst(s, t) + Cov_br_Jst(t, s, s)*Cov_b0_Jst(s, t))*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t)
	B = np.exp(lambda_b*t)*complex_quad(lambda s: np.exp(-lambda_hat*(t-s))*(Cov_b0_b0_star + E_b(s)*E_b0 - E_b0*Cov_br_Jst(t, s, s) - E_b(s)*Cov_b0_Jst(s, t) + Cov_br_Jst(t, s, s)*Cov_b0_Jst(s, t))*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t)
	C = np.exp(lambda_b*t)*complex_quad(lambda s: np.exp(lambda_hat*(t-s))*f(s)*(E_b0-Cov_b0_Jst(s, t))*np.exp(-E_J(s, t)+1/2*Var_J(s, t)), 0, t)
	return A+B+C - E_u(t)*E_b(t)

def test():
	from matplotlib import pyplot as plt
	t = np.arange(0, 1, 1e-3)
	v = [Var_u(i) for i in t]
	plt.plot(t, v)
	plt.show()


if __name__ == '__main__':
	t = 0
	print(Cov_u_b(t))