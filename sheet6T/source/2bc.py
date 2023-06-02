import numpy as np
import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import Axes3D


x, y, z = np.genfromtxt('source/output/pr20_1.txt', delimiter= ", ", unpack= True)

plt.figure(1)
plt.xlim(-15, 15)
plt.ylim(-20, 20)
plt.xlabel("x")
plt.ylabel("y")

plt.plot(x, y, 'r-', linewidth = 0.7)
plt.savefig('build/pr20_1.pdf')
plt.close()

x, y, z = np.genfromtxt('source/output/pr20_23.txt', delimiter= ", ", unpack= True)

plt.figure(2)
plt.xlim(-10, -4)
plt.ylim(-10, -2)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x, y, 'r-')
plt.savefig('build/pr20_23.pdf')
plt.close()

plt.figure(3)
fig = plt.figure()
ax = fig.add_subplot(projection = "3d")
ax.plot(x,y,z, linewidth = 0.75, label = "3D plot mit r = 20")
ax.legend()
ax.set_xlabel(r'$X$')
ax.set_ylabel(r'$Y$')
ax.set_zlabel(r'$Z$')
ax.set_xlim(-10, 5)
ax.set_ylim(-10, 5)
ax.set_zlim(10, 25)


plt.savefig('build/pr20_3d.pdf')
plt.close()


x, y, z = np.genfromtxt('source/output/pr20_32.txt', delimiter= ", ", unpack= True)

plt.figure(4)
plt.xlim(-10, -4)
plt.ylim(-10, -2)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x, y, 'r-')
plt.savefig('build/pr20_32.pdf')
plt.close()




plt.figure(5)

x, y, z = np.genfromtxt("source/output/pr28_1.txt", delimiter= ", ", unpack= True)
plt.xlim(-20, 20)
plt.ylim(-20, 23)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x, y, 'k-', linewidth = 1)
plt.savefig('build/pr28_1.pdf')
plt.close()

plt.figure(6)

x, y, z = np.genfromtxt("source/output/pr28_23.txt", delimiter= ", ", unpack= True)
plt.xlim(-20, 20)
plt.ylim(-20, 23)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x, y, 'k-' ,linewidth = 1)
plt.savefig('build/pr28_23.pdf')
plt.close()

plt.figure(7)

fig = plt.figure()
ax = fig.add_subplot(projection = "3d")

ax.plot(x,y,z, linewidth = 0.2, label = "3D plot mit r = 28")
ax.legend()

ax.set_xlabel(r'$X$')
ax.set_ylabel(r'$Y$')
ax.set_zlabel(r'$Z$')

plt.savefig('build/pr28_3d.pdf')
plt.close()

plt.figure(8)

x, y, z = np.genfromtxt("source/output/pr28_32.txt", delimiter= ", ", unpack= True)
plt.xlim(-20, 20)
plt.ylim(-20, 23)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x, y, 'k-' ,linewidth = 1)
plt.savefig('build/pr28_32.pdf')
plt.close()


# Die Z = 20 plots

plt.figure(9)

x, y = np.genfromtxt("source/output/z20_20.txt", delimiter= ", ", unpack= True)
plt.plot(x, y, 'k.')
plt.savefig('build/z20_20.pdf')
plt.close()

plt.figure(10)

x, y = np.genfromtxt("source/output/z20_28.txt", delimiter= ", ", unpack= True)
plt.plot(x, y, 'k.')
plt.savefig('build/z20_28.pdf')
plt.close()












