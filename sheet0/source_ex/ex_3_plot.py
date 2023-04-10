import numpy as np 
import matplotlib.pyplot as plt 

normal_values_small, symm_values_small = np.genfromtxt('source_ex/output/ex_3_euler_small.txt', unpack = True)
normal_values_big, symm_values_big = np.genfromtxt('source_ex/output/ex_3_euler_big.txt', unpack = True)


t_plot = np.linspace(0, 10, normal_values_small.size)

fig, axs = plt.subplots(2, 2)
axs[0, 0].plot(t_plot, normal_values_small, label = "Euler-Verfahren")
axs[0, 0].plot(t_plot, np.exp(-t_plot), label = "Exaktes Ergebnis")
axs[0, 0].set_title("main")
axs[1, 0].plot(t_plot, symm_values_small, label = "Symmetrisches Euler-Verfahren")
axs[1, 0].plot(t_plot, np.exp(-t_plot), label = "Exaktes Ergebnis")
axs[1, 0].set_title("shares x with main")
axs[1, 0].sharex(axs[0, 0])

del t_plot 

t_plot = np.linspace(0, 10, normal_values_big.size)


axs[0, 1].plot(t_plot, normal_values_big, label = "Euler-Verfahren")
axs[0, 1].plot(t_plot, np.exp(-t_plot), label = "Exaktes Ergebnis")
axs[0, 1].set_title("unrelated")
axs[1, 1].plot(t_plot, normal_values_big, label = "Euler-Verfahren")
axs[1, 1].plot(t_plot, np.exp(-t_plot), label = "Exaktes Ergebnis")
axs[1, 1].set_title("also unrelated")
fig.tight_layout()

plt.savefig("build/ex_3.pdf", bbox_inches='tight', pad_inches=0)
