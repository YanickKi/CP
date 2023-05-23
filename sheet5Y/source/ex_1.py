import numpy as np 
import matplotlib.pyplot as plt 
from matplotlib import animation


u = np.zeros([501,200])

for n in range (501):
    u[n] = np.genfromtxt(f'source/output/1c_{n}.txt')

def lol(timeDep, filename):
    # First set up the figure, the axis, and the plot element we want to animate
    fig = plt.figure()
    ax = plt.axes(xlim=(-11, 11), ylim=(0, 1.2), xlabel=r'$x$', ylabel=r'$u$')
    line, = ax.plot([], [], lw=2)

    # initialization function: plot the background of each frame
    def init():
        line.set_data([], [])
        return line,

    # animation function.  This is called sequentially
    def animate(i):
        x = np.linspace(-10, 10, 200)
        y = timeDep[i]
        line.set_data(x, y)
        return line,
    

    # call the animator.  blit=True means only re-draw the parts that have changed.
    anim = animation.FuncAnimation(fig, animate, init_func=init,
                                   frames=timeDep.shape[0], blit=True)

    anim.save(filename, fps=30, extra_args=['-vcodec', 'libx264'])

lol(u, 'build/ex_1.mp4')