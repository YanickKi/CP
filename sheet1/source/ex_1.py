import numpy as np 
import matplotlib.pyplot as plt 

step_size, derivative = np.genfromtxt('source/output/ex_1a.txt', unpack = True)
x, num_deriv, ana_deriv, rel_error = np.genfromtxt('source/output/ex_1a_error.txt', unpack = True)
x_sec, num_sec_deriv, ana_sec_deriv, sec_rel_error = np.genfromtxt('source/output/ex_1b.txt', unpack = True)
x_vier, num_vier_deriv, ana_vier_deriv, vier_rel_error = np.genfromtxt('source/output/ex_1c.txt', unpack = True)
#x_f2, two_f2, four_f2, rel_error_f2 = np.genfromtxt('source/output/ex_1c.txt', unpack = True)


plt.figure(1)
plt.plot(step_size, derivative)
plt.xlabel(r'$h$')
plt.ylabel(r'$f_1^{\prime}(x)$')
plt.tight_layout()
plt.savefig('build/ex_1a_varstep.pdf') 

plt.figure(2)
plt.plot(x, num_deriv, label = 'Numerisch')
plt.plot(x, ana_deriv, label = 'Analytisch')
plt.xlabel(r'$x$')
plt.ylabel(r'$f_1^{\prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1a_compare.pdf')

plt.figure(3)
plt.plot(x, rel_error)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime} $')
plt.tight_layout()
plt.savefig('build/ex_1a_error.pdf')

plt.figure(4)
plt.plot(x_sec, num_sec_deriv, label = 'Numerisch')
plt.plot(x_sec, ana_sec_deriv, label = 'Analytisch')
plt.xlabel(r'$x$')
plt.ylabel(r'$f_1^{\prime \prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1b_compare.pdf')

plt.figure(5)
plt.plot(x_sec, sec_rel_error)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime \prime} $')
plt.tight_layout()
plt.savefig('build/ex_1b_error.pdf')
##
plt.figure(6)
plt.plot(x_vier, num_vier_deriv, label = 'Numerisch')
plt.plot(x_vier, ana_vier_deriv, label = 'Analytisch')
plt.xlabel(r'$x$')
plt.ylabel(r'$f_1^{ \prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1c_compare.pdf')

plt.figure(7)
plt.plot(x_vier, vier_rel_error)
plt.xlabel(r'$x$')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{ \prime} $')
plt.tight_layout()
plt.savefig('build/ex_1c_error.pdf')

#plt.figure(8)
#plt.plot(x_vier, vier_rel_error)
#plt.xlabel(r'$x$')
#plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime \prime} $')
#plt.tight_layout()
#plt.savefig('build/ex_1c_error.pdf')