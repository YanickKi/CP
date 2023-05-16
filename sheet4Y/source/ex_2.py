import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation

a = np.genfromtxt('source/output/2a.txt')

a.transpose()
print(a.shape)
def lol(timeDep, filename):
    # First set up the figure, the axis, and the plot element we want to animate
    fig = plt.figure()
    ax = plt.axes(xlim=(0, 1), ylim=(0, 1.2))
    line, = ax.plot([], [], lw=2)

    # initialization function: plot the background of each frame
    def init():
        line.set_data([], [])
        return line,

    # animation function.  This is called sequentially
    def animate(i):
        x = np.linspace(0, 1, int(1/0.01))
        y = timeDep[i]
        line.set_data(x, y)
        print(x.shape, " ", y.shape)
        return line,
    

    # call the animator.  blit=True means only re-draw the parts that have changed.
    anim = animation.FuncAnimation(fig, animate, init_func=init,
                                   frames=timeDep.shape[0], blit=True)

    #canim.save(filename, fps=30, extra_args=['-vcodec', 'libx264'])

    plt.show()

lol(a, 'build/2a.mp4')  