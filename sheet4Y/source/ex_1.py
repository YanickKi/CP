import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

b = np.genfromtxt('source/output/1b.txt')
c = np.genfromtxt('source/output/1c.txt')
c_analytical = np.genfromtxt('source/output/1c_analytical.txt')
d = np.genfromtxt('source/output/1d.txt')
d_E = np.genfromtxt('source/output/1d_E.txt')
e = np.genfromtxt('source/output/1e.txt')
e_E = np.genfromtxt('source/output/1e_E.txt')

plt.figure(1)

plt.imshow(c)
plt.colorbar(label=r'$\Phi$')
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.savefig('build/1c.pdf')

plt.figure(2)

plt.imshow(c_analytical)
plt.colorbar(label=r'$\Phi$')
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.savefig('build/1c_analytical.pdf')

plt.figure(3)

plt.imshow(d)
plt.colorbar(label=r'$\Phi$')
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.savefig('build/1d.pdf')

plt.figure(4)

plt.imshow(d_E)
plt.colorbar(label=r'$E$')
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.savefig('build/1d_E.pdf')

plt.figure(5)

plt.imshow(e)
plt.colorbar(label=r'$\Phi$')
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.savefig('build/1e.pdf')

plt.figure(6)

plt.imshow(e_E)
plt.colorbar(label=r'$E$')
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.savefig('build/1e_E.pdf')

plt.figure(7)

plt.imshow(b)
plt.colorbar(label=r'$\Phi$')
plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.savefig('build/1b.pdf')