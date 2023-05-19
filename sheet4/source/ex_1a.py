import matplotlib.pyplot as plt
import numpy as np

# a 2D array with linearly increasing values on the diagonal
phi = np.loadtxt('source/output/a)setAufgabe1.dat', unpack=True)


plt.imshow(phi)
plt.colorbar()
plt.xticks([0, 5, 10, 15], [0, 0.25, 0.5, 0.75])
plt.yticks([5, 10, 15, 19], [0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
#plt.matshow(phi, 1)
#plt.colorbar()
plt.savefig('build/ex_1a.pdf')
plt.close()




Ex = np.loadtxt('source/output/Ex_b.dat', unpack=True)
Ey = np.loadtxt('source/output/Ey_b.dat', unpack=True)

index = np.linspace(0,19,20)
X,Y = np.meshgrid(index, index[::-1])
plt.quiver(X,Y, Ex, Ey)
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')


plt.savefig('build/ex_1b_el.pdf')
