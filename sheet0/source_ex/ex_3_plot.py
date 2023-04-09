import numpy as np 
import matplotlib.pyplot as plt 

values = np.genfromtxt('source_ex/output/ex_3_symm.txt', unpack = True)

t_plot = np.linspace(0, 10, values.size)

plt.plot(t_plot, values, label = "Euler-Verfahren")
plt.plot(t_plot, np.exp(-t_plot), label = "Exaktes Ergebnis")
plt.legend()
plt.savefig("build/ex_3_plot_symm.pdf", bbox_inches='tight', pad_inches=0)