import numpy as np 
import matplotlib.pyplot as plt 

tn, x1, y1, x2, y2, vx1, vy1, vx2,vy2 = np.genfromtxt('source/output/ex_3_verlet.txt', unpack = True)
tn_, x1_, y1_, x2_, y2_, vx1_, vy1_, vx2_,vy2_ = np.genfromtxt('source/output/ex_3_euler.txt', unpack = True)
tn__, x1__, y1__, x2__, y2__, vx1__, vy1__, vx2__,vy2__ = np.genfromtxt('source/output/ex_3_verlet_schl.txt', unpack = True)
tn_e2, x1_e2, y1_e2, x2_e2, y2_e2, vx1_e2, vy1_e2, vx2_e2,vy2_e2 = np.genfromtxt('source/output/ex_3_euler_schl.txt', unpack = True)


plt.subplot(2,2,1)
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.plot(x1, y1, label = r' $\vec{r}_1$')
plt.plot(x2, y2, label = r' $\vec{r}_2$')
plt.title('Verlet mit guten Schritten')
plt.legend()

plt.subplot(2,2,2)
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.plot(x1_, y1_, label = r' $\vec{r}_1$')
plt.plot(x2_, y2_, label = r' $\vec{r}_2$')
plt.title('Euler mit guten Schritten')
plt.legend()

plt.subplot(2,2,3)
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.plot(x1__, y1__, label = r' $\vec{r}_1$')
plt.plot(x2__, y2__,label = r' $\vec{r}_2$')
plt.title('Verlet mit schlechten Schritten')
plt.legend()

plt.subplot(2,2,4)
plt.xlabel(r'$x \mathbin{/} m$')
plt.ylabel(r'$y \mathbin{/} m$')
plt.tight_layout()
plt.plot(x1_e2, y1_e2, label = r' $\vec{r}_1$')
plt.plot(x2_e2, y2_e2, label = r' $\vec{r}_2$')
plt.title('Euler mit schlechten Schritten')
plt.legend()

plt.savefig('build/ex_3_a.pdf')