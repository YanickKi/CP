import numpy as np
import matplotlib.pyplot as plt

######################logistische Funktion########################
def logistic(r, x):
    return r*x*(1-x)

n = 4000 #entspricht einem DeltaR von 0.001
r = np.linspace(1e-4, 4, n)

iterations = 10000
last = 10000

x = 0.75 * np.ones(n)

lyapunov = np.zeros(n)

#Plot des Bifurkationsdiagramms
plt.figure(figsize=(6,7));
plt.subplot(211);
for i in range(iterations):
    x = logistic(r, x)
    # We compute the partial sum of the Lyapunov exponent.
    lyapunov += np.log(abs(r-2*r*x))
    if i >= (iterations - last):
        plt.plot(r, x, ',k', alpha=.04)
points = len(r) * n
plt.xlim(0, 4);
plt.title("Bifurcationsdiagramm für logistische Funktion")
plt.text(0.5, 0.75, 'total points: %s'%points)

#Ljapunow Exponent plotten
plt.subplot(212);
plt.plot(r[lyapunov<0], lyapunov[lyapunov<0] / iterations,
         ',k', alpha=.2);
plt.plot(r[lyapunov>=0], lyapunov[lyapunov>=0] / iterations,
         ',r', alpha=.5);
plt.xlim(0, 4);
plt.ylim(-2, 1);
plt.title("Ljapunow-Exponent logistische Funktion")
plt.savefig('Logistic075.png', dpi = 300)
plt.tight_layout()
#plt.show()


#Bestimmung der Nullannäherungen Ljapunow Exponent
for i in range(len(lyapunov)):
    if (lyapunov[i]/iterations) >= -0.002:
        if (lyapunov[i]/iterations) <=0.005:
            print('logistic->0 bei r = ', r[i], 'Lyapunov/iterations = ', (lyapunov[i]/iterations))

#########################kubische Funktion###########################
def kubic(r_, x_):
    return r_*x_ - (x_**3)

n3 = 3000 #entspricht einem DeltaR von 0.001
r3 = np.linspace(1e-4, 3, n3)

iterations3 = 10000
last3 = 10000

x3 = 1e-4 * np.ones(n3)

lyapunov3 = np.zeros(n3)

#Plot des Bifurkationsdiagramms
plt.figure(figsize=(6,7));
plt.subplot(211);
for i in range(iterations3):
    x3 = kubic(r3, x3)
    # We compute the partial sum of the Lyapunov exponent.
    lyapunov3 += np.log(abs(r3-2*r3*x3))
    if i >= (iterations3 - last3):
        plt.plot(r3, x3, ',k', alpha=.04)
points3 = len(r3) * n3
plt.xlim(0, 3);
plt.title("Bifurkationsdiagramm für kubische Funktion")
plt.text(0.5, 1.5, 'total points: %s'%points3)

#Ljapunow Exponent plotten
plt.subplot(212);
plt.plot(r3[lyapunov3<0], lyapunov3[lyapunov3<0] / iterations3,
         ',k', alpha=.2);
plt.plot(r3[lyapunov3>=0], lyapunov3[lyapunov3>=0] / iterations3,
         ',r', alpha=.5);
plt.xlim(0, 3);
plt.ylim(-2, 1);
plt.title("Ljapunow-Exponent kubische Funktion")
plt.savefig('Kubic.png', dpi = 300)
plt.tight_layout()
#plt.show()


#Bestimmung der Nullannäherungen Ljapunow Exponent
for i in range(len(lyapunov3)):
    if (lyapunov3[i]/iterations3) >= -0.002:
        if (lyapunov3[i]/iterations3) <=0.005:
            print('kubic->0 bei r = ', r3[i], 'Lyapunov/iterations = ', (lyapunov3[i]/iterations3))