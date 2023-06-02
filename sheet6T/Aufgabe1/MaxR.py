import numpy as np
import matplotlib.pyplot as plt
import math as m

def logistic(r, x):
    return r*x*(1-x)

def kubic(r_, x_):
    return r_*x_ - (x_**3)

x = np.linspace(0, 1, 1000)
r = np.linspace(0, 10, 1000)

#setColormap
cmap = plt.cm.ScalarMappable(cmap = plt.cm.get_cmap('plasma'), # Der Farbgradient
                             norm = plt.Normalize(0, 1000)) # start und end wert des Mappings
cmap.set_array([])

#Plot kubische Funktion
fig = plt.figure()
for i in range(1000):
    xn = kubic(r[i], x)
    GrenzeKubic = m.sqrt(1+r[i])
    if abs(np.max(xn)) <= GrenzeKubic:
        if abs(np.max(xn)) >= GrenzeKubic * (-1):
            plt.plot(x, xn, color = cmap.to_rgba(i))
            print(r[i])
    else:
        plt.plot(x, xn, color='grey')
plt.title('maximale r für kubische Funktion')
plt.text(0, 5, 'Grau: $x_n$ außerhalb des Intervalls', fontsize='large')
plt.savefig('kubicMaxR.png', dpi = 300)
#plt.show()

#Plot logistische Funktion
for i in range(1000):
    xn = logistic(r[i], x)
    if np.max(xn) <= 1:
        plt.plot(x, xn, color = cmap.to_rgba(i))
        print(r[i])
    else:
        plt.plot(x, xn, color='grey')
plt.title('maximale r für ligistische Funktion')
plt.text(0, 2.3, 'Grau: $x_n$ außerhalb des Intervalls', fontsize='large')
plt.savefig('logisticMaxR.png', dpi = 300)
#plt.show()