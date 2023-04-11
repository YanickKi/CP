import numpy as np 
import matplotlib.pyplot as plt 

x_small, x_big, x_period, a_bad, a_good, b_bad, b_good, c_bad, c_good, a_rel, b_rel, c_rel = np.genfromtxt('source_ex/output/ex_2.txt', unpack = True)

plt.figure(1)

plt.subplot(1,2,1)
plt.plot(x_big, a_bad,  label = "orig.")
plt.plot(x_big, a_good, label = "umgeformt")
plt.legend() 

plt.subplot(1,2,2)
plt.plot(x_big, a_rel, label = "Relative Abweichung")
plt.legend()
plt.tight_layout()
plt.savefig("build/ex_2_a.pdf")


plt.figure(2)

plt.subplot(1,2,1)
plt.plot(x_small, b_bad,  label = "orig.")
plt.plot(x_small, b_good, label = "umgeformt")
plt.legend()

plt.subplot(1,2,2)
plt.plot(x_small, b_rel, label = "Relative Abweichung")
plt.legend()
plt.tight_layout()
plt.savefig("build/ex_2_b.pdf")


plt.figure(3)

plt.subplot(1,2,1)
plt.plot(x_period, c_bad,  label = "orig.")
plt.plot(x_period, c_good, label = "umgeformt")
plt.legend()

plt.subplot(1,2,2)
plt.plot(x_period, c_rel, label = "Relative Abweichung")
plt.legend()
plt.tight_layout()
plt.savefig("build/ex_2_c.pdf")