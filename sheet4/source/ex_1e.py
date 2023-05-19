import matplotlib.pyplot as plt
import numpy as np

# a 2D array with linearly increasing values on the diagonal
phi = np.loadtxt('source/output/e)setAufgabe1.dat', unpack=True)

plt.imshow(phi)
plt.colorbar()
plt.xticks([0, 5, 10, 15], [0, 0.25, 0.5, 0.75])
plt.yticks([5, 10, 15, 19], [0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')

plt.savefig('build/ex_1e.pdf')
plt.close()

Ex = np.loadtxt('source/output/Ex_e.dat', unpack=True)
Ey = np.loadtxt('source/output/Ey_e.dat', unpack=True)

index = np.linspace(0,19,20)
X,Y = np.meshgrid(index, index)
plt.quiver(X,Y, Ex, Ey)
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')

plt.savefig('build/ex_1e_el.pdf')