import numpy as np 
import matplotlib.pyplot as plt 

step_size, derivative = np.genfromtxt('source/output/ex_1a.txt', unpack = True)
x, num_deriv, ana_deriv, rel_error = np.genfromtxt('source/output/ex_1a_error.txt', unpack = True)
x_sec, num_sec_deriv, ana_sec_deriv, sec_rel_error = np.genfromtxt('source/output/ex_1b.txt', unpack = True)
x_vier, num_vier_deriv, ana_vier_deriv, vier_rel_error = np.genfromtxt('source/output/ex_1c.txt', unpack = True)
x_f2, two_f2, four_f2, rel_error_f2 = np.genfromtxt('source/output/ex_1d.txt', unpack = True)


plt.figure(1)
plt.plot(step_size, derivative)
plt.xlabel(r'$h$')
plt.ylabel(r'$f_1^{\prime}(x)$')
plt.tight_layout()
plt.savefig('build/ex_1a_varstep.pdf') 

plt.figure(2)
plt.plot(x, num_deriv, label = 'Zweipunkt')
plt.plot(x, ana_deriv, label = 'Analytisch')
plt.xlabel(r'$x$')
plt.ylabel(r'$f_1^{\prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1a_compare.pdf')

plt.figure(3)

plt.subplot(2,2,1)
plt.plot(x, rel_error)
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime} $')

plt.subplot(2,2,2)
plt.plot(x, rel_error)
plt.ylim(5e-7, 1e-4)
plt.yscale('log')

plt.subplot(2,2,3)
plt.plot(x, rel_error)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime} $')
plt.xlim(-np.pi/2 - 0.025, -np.pi/2 + 0.025)

plt.subplot(2,2,4)
plt.plot(x, rel_error)
plt.xlabel(r'$x$')
plt.xlim(np.pi/2 - 0.025, np.pi/2 + 0.025)

plt.tight_layout()
plt.savefig('build/ex_1a_error.pdf')

plt.figure(4)
plt.plot(x_sec, num_sec_deriv, label = 'Zweipunkt')
plt.plot(x_sec, ana_sec_deriv, label = 'Analytisch')
plt.xlabel(r'$x$')
plt.ylabel(r'$f_{1, \text{Zweipunkt}}^{\prime \prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1b_compare.pdf')

plt.figure(5)

plt.subplot(2,1,2)
plt.plot(x_sec, sec_rel_error)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime} $')

plt.subplot(2,2,1)
plt.plot(x_sec, sec_rel_error)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime} $')
plt.xlim(-np.pi-0.003, -np.pi + 0.017)

plt.subplot(2,2,2)
plt.plot(x_sec, sec_rel_error)
plt.xlabel(r'$x$')
plt.ylim(1e-7, 1e-2)
plt.yscale('log')
plt.tight_layout()

plt.tight_layout()
plt.savefig('build/ex_1b_error.pdf')

plt.figure(6)
plt.plot(x_vier, num_vier_deriv, label = 'Vierpunkt')
plt.plot(x_vier, ana_vier_deriv, label = 'Analytisch')
plt.xlabel(r'$x$')
plt.ylabel(r'$f_{1,\text{Vierpunkt}}^{ \prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1c_compare.pdf')

plt.figure(7)

plt.subplot(2,2,1)
plt.plot(x_vier, vier_rel_error)
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Vierpunkt}}^{\prime} $')

plt.subplot(2,2,2)
plt.plot(x_vier, vier_rel_error)
plt.ylim(5e-9, 1e-3)
plt.yscale('log')

plt.subplot(2,2,3)
plt.plot(x_vier, vier_rel_error)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Vierpunkt}}^{\prime} $')
plt.xlim(-np.pi/2 - 0.025, -np.pi/2 + 0.025)

plt.subplot(2,2,4)
plt.plot(x_vier, vier_rel_error)
plt.xlabel(r'$x$')
plt.xlim(np.pi/2 - 0.025, np.pi/2 + 0.025)

plt.tight_layout()
plt.savefig('build/ex_1c_error.pdf')

plt.figure(8)
plt.plot(x_f2, two_f2, label = 'Zweipunkt')
plt.plot(x_f2, four_f2, label = 'Vierpunkt')
plt.xlabel(r'$x$')
plt.ylabel(r'$f_2^{ \prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1d_compare.pdf')

plt.figure(9)

plt.figure(figsize=(6,6))

plt.subplot(3,2,1)
plt.plot(x_f2, rel_error_f2)
plt.ylabel(r'$\symup{\Delta} f_{2, \text{Vierpunkt}}^{\prime} $')
plt.ylim(5e-6, 1e-4)
plt.yscale('log')

plt.subplot(3,2,2)
plt.plot(x_f2, rel_error_f2)
plt.xlim(-np.pi - 0.005, -np.pi + 0.03)

plt.subplot(3,2,3)
plt.plot(x_f2, rel_error_f2)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{2, \text{Vierpunkt}}^{\prime} $')
plt.xlim(-0.05, 0.05)

plt.subplot(3,2,4)
plt.plot(x_f2, rel_error_f2)
plt.xlabel(r'$x$')
plt.xlim(np.pi-0.03, np.pi + 0.005)

plt.subplot(3,1,3)
plt.plot(x_f2, rel_error_f2)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{2, \text{Vierpunkt}}^{\prime} $')

plt.tight_layout()
plt.savefig('build/ex_1d_error.pdf')