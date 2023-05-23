import numpy as np 
import matplotlib.pyplot as plt 
from matplotlib import animation

u = dict()

def f(u,n):
    plt.figure(n)
    plt.imshow(u)
    plt.colorbar(label=r'$\u$')
    #plt.xticks([0, 5, 10, 15, 19], [0, 0.25, 0.5, 0.75, 1])
    #plt.yticks([0, 5, 10, 15, 19], [1, 0.75, 0.5, 0.25, 0])
    plt.xlabel(r'$x$')
    plt.ylabel(r'$y$')
    plt.savefig(f'build/2e_{n}.pdf')


for i in range (100, 1001, 100):
    n = i-1
    u[n] = np.genfromtxt(f'source/output/2e_{n}.txt')
    f(u[n],n) 

zero = np.genfromtxt(f'source/output/2e_0.txt')
one = np.genfromtxt(f'source/output/2e_1.txt')
ten = np.genfromtxt(f'source/output/2e_10.txt')
fifty = np.genfromtxt(f'source/output/2e_50.txt')
six = np.genfromtxt(f'source/output/2e_5.txt')

f(zero, 0)
f(one,1)
f(ten, 11)
f(fifty, 51)
f(six, 6)

#u = np.empty([1000, 150, 100])
#
#fps = 30
#nSeconds = 999
#
#
#for i in range(0,1000):
#    u[i] = np.genfromtxt(f'source/output/2e_{i}.txt')
#    print(i, "\n")
#