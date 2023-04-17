import numpy as np 
import matplotlib.pyplot as plt 

step_size, derivative = np.genfromtxt('source/output/ex_1a.txt', unpack = True)
x, num_deriv, ana_deriv, rel_error = np.genfromtxt('source/output/ex_1a_error.txt', unpack = True)


plt.figure(1)
plt.plot(step_size, derivative)
plt.xlabel('h')
plt.ylabel(r'$f_1^{\prime}(x)$')
plt.legend()
plt.tight_layout()
plt.savefig('build/ex_1a_varstep.pdf') 

plt.figure(2)
plt.plot(x, num_deriv, label = 'Numerisch')
plt.plot(x, ana_deriv, label = 'Analytisch')
plt.xlabel('x')
plt.ylabel(r'$f_1^{\prime} (x)$')
plt.tight_layout()
plt.legend()
plt.savefig('build/ex_1a_compare.pdf')

plt.figure(3)
plt.plot(x, rel_error)
plt.xlabel('x')
plt.ylabel(r'$\symup{\Delta} f_{1, \text{Zweipunkt}}^{\prime} $')
plt.tight_layout()
plt.savefig('build/ex_1a_error.pdf')
