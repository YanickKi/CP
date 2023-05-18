import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation

a =             np.genfromtxt('source/output/2a.txt').transpose()
b_stable =      np.genfromtxt('source/output/2b_stable.txt').transpose()
b_unstable =    np.genfromtxt('source/output/2b_unstable.txt').transpose()
c_1 =           np.genfromtxt('source/output/2c_1.txt').transpose()
c_2 =           np.genfromtxt('source/output/2c_2.txt').transpose()
c_3 =           np.genfromtxt('source/output/2c_3.txt').transpose()

"""
Matplotlib Animation Example    

author: Jake Vanderplas
email: vanderplas@astro.washington.edu
website: http://jakevdp.github.com
license: BSD
Please feel free to use and modify this, but keep the above information. Thanks!
"""

def lol(timeDep, filename):
    # First set up the figure, the axis, and the plot element we want to animate
    fig = plt.figure()
    ax = plt.axes(xlim=(0, 1), ylim=(0, 1.2), xlabel=r'$x$', ylabel=r'$u$')
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
        return line,
    

    # call the animator.  blit=True means only re-draw the parts that have changed.
    anim = animation.FuncAnimation(fig, animate, init_func=init,
                                   frames=timeDep.shape[0], blit=True)

    anim.save(filename, fps=30, extra_args=['-vcodec', 'libx264'])

lol(a, 'build/2a.mp4')  
lol(b_stable, 'build/2b_stable.mp4')  
lol(b_unstable, 'build/2b_unstable.mp4')  
lol(c_1, 'build/2c_1.mp4')  
lol(c_2, 'build/2c_2.mp4')  
lol(c_3, 'build/2c_3.mp4')  
