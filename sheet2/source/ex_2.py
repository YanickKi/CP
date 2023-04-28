import numpy as np 
import matplotlib.pyplot as plt 

s, r, z, psi = np.genfromtxt('source/output/ex_2c.txt', unpack = True)

plt.figure(1)

plt.plot(s, r)
plt.xlabel(r'$s \mathbin{/} a$')
plt.ylabel(r'$r \mathbin{/} a$')
plt.tight_layout()
plt.savefig('build/ex_2c_r.pdf')

plt.figure(2)

plt.plot(s, z)
plt.xlabel(r'$s \mathbin{/} a$')
plt.ylabel(r'$z \mathbin{/} a$')
plt.tight_layout()
plt.savefig('build/ex_2c_z.pdf')

plt.figure(3)

plt.plot(s, psi)
plt.xlabel(r'$s \mathbin{/} a$')
plt.ylabel(r'$  \Psi$')
plt.tight_layout()
plt.savefig('build/ex_2c_psi.pdf')