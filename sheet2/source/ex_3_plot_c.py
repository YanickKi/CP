import numpy as np 
import matplotlib.pyplot as plt 


tn, x1, y1, x2, y2, vx1, vy1, vx2,vy2 = np.genfromtxt('source/output/ex_3_euler_ruck.txt', unpack = True)
tne, x1e, y1e, x2e, y2e, vxe, vy1e, vx2e,vy2e = np.genfromtxt('source/output/ex_3_verlet_rück.txt', unpack = True)

plt.figure(1)

plt.subplot(2,1,1)
plt.plot(x1, y1, label = r' $\vec{r}_1$')
plt.plot(x2, y2, label = r' $\vec{r}_2$')
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.legend()


plt.subplot(2,1,2)
plt.plot(x1e, y1e, label = r' $\vec{r}_1$')
plt.plot(x2e, y2e, label =  r' $\vec{r}_2$')
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.legend()

plt.savefig('build/ex_3_c.pdf')