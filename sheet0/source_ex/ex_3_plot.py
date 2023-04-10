import numpy as np 
import matplotlib.pyplot as plt 

normal_values, symm_values = np.genfromtxt('source_ex/output/ex_3_euler.txt', unpack = True)
t_plot = np.linspace(0, 10, normal_values.size)

plt.subplot(2,1,1)
plt.plot(t_plot, normal_values, label = "Euler-Verfahren")
plt.plot(t_plot, np.exp(-t_plot), label = "Exaktes Ergebnis")

plt.ylabel('y')
plt.legend()

plt.subplot(2,1,2)
plt.plot(t_plot, symm_values, label = "Symmetrisches Euler-Verfahren")
plt.plot(t_plot, np.exp(-t_plot), label = "Exaktes Ergebnis")

plt.xlabel('t')
plt.ylabel('y')


plt.legend()
plt.savefig("build/ex_3_plot_symm.pdf", bbox_inches='tight', pad_inches=0)