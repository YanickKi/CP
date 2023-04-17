import numpy as np 
import matplotlib.pyplot as plt 

step_size, derivative = np.genfromtxt('source/output/ex_1a.txt', unpack = True)

plt.plot(step_size, derivative)

plt.tight_layout()
plt.savefig("build/ex_1.pdf")  