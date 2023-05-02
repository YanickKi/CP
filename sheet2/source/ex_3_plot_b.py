import numpy as np 
import matplotlib.pyplot as plt 


tn, x1, y1, x2, y2, vx1, vy1, vx2,vy2 = np.genfromtxt('source/output/ex_3_euler.txt', unpack = True)
tne, x1e, y1e, x2e, y2e, vxe, vy1e, vx2e,vy2e = np.genfromtxt('source/output/ex_3_verlet_vertrau.txt', unpack = True)


plt.subplot(2,1,1)
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.plot(x1, y1, label = r' $\vec{r}_1$')
plt.plot(x2, y2, label = r' $\vec{r}_2$')
plt.title('Euler')
plt.legend()


plt.subplot(2,1,2)
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.plot(x1e, y1e, label = r' $\vec{r}_1$')
plt.plot(x2e, y2e, label = r' $\vec{r}_2$')
plt.title('Verlet')
plt.legend()

plt.savefig('build/ex_3_b.pdf')