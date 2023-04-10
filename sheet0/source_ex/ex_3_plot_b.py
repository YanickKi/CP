import numpy as np 
import matplotlib.pyplot as plt 

normal_values_small, symm_values_small = np.genfromtxt('source_ex/output/ex_3_euler_small_b.txt', unpack = True)
normal_values_big, symm_values_big = np.genfromtxt('source_ex/output/ex_3_euler_big_b.txt', unpack = True)


t_plot = np.linspace(0, 10, normal_values_small.size)

fig, axs = plt.subplots(2, 2)
axs[0, 0].plot(t_plot, normal_values_small, label = "Euler")
axs[0, 0].plot(t_plot, np.exp(-t_plot), label = "Exakt")
axs[0, 0].set_title(r'$N = 150$')
axs[1, 0].plot(t_plot, symm_values_small, label = "Symm.")
axs[1, 0].plot(t_plot, np.exp(-t_plot), label = "Exakt")
axs[1, 0].sharex(axs[0, 0])
 
del t_plot 
 
t_plot = np.linspace(0, 10, normal_values_big.size)

axs[0, 1].plot(t_plot, normal_values_big, label = "Euler")
axs[0, 1].plot(t_plot, np.exp(-t_plot), label = "Exakt")
axs[0, 1].set_title(r'$N = \num{1e5}$')
axs[1, 1].plot(t_plot, symm_values_big, label = "Symm.")
axs[1, 1].plot(t_plot, np.exp(-t_plot), label = "Exakt") 

for i in range(2):
    for j in range(2):
        axs[i,j].legend()

plt.tight_layout()
plt.savefig("build/ex_3_b.pdf")