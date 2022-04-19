

import numpy as np
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d as p3d

#############################################################################
### plot1D loads data from given file - assumes 3 columns (t,x,v).
#############################################################################
def plot1D (filename):
    
    # Load data
    t,x,y,z = np.loadtxt(filename, unpack=True)

    # Plot (x(t) - t) and (v(t) - t)
    plt.figure()
    
    gap_x = (max(x)-min(x))/4
    gap_y = (max(y)-min(y))/4
    gap_z = (max(z)-min(z))/4

    # Make (x(t) - t) plot
    plt.subplot(221)
    plt.plot(x, y, 'o')
    # plt.axis([min(x)-gap_x, max(x)+gap_x, min(y)-gap_y, max(y)+gap_y])
    plt.xlabel('x(t)')
    plt.ylabel('y(t)')

    # Make (v(t) - t) plot
    plt.subplot(222)
    plt.plot(z, y, 'o')
    # plt.axis([min(z)-gap_z, max(z)+gap_z, min(y)-gap_y, max(y)+gap_y])
    plt.xlabel('z(t)')
    plt.ylabel('y(t)')

    # Make (v(t) - t) plot
    plt.subplot(223)
    plt.plot(x, z, 'o')
    # plt.axis([min(x)-gap_x, max(x)+gap_x, min(z)-gap_z, max(z)+gap_z])
    plt.xlabel('x(t)')
    plt.ylabel('z(t)')

    # Make plot3D
    ax=plt.subplot(224,projection="3d")
    ax.scatter(x,y,z)
    ax.set_xlabel('x(t)')
    ax.set_ylabel('y(t)')
    ax.set_zlabel('z(t)')

    # Make subplots look good
    plt.tight_layout()

    # Make v(t) - x(t) plot
    '''
    plt.figure(2)
    plt.scatter(x, y, color='blue')
    plt.axis([(min(x)+min(x)/4), max(x)+max(x)/4, (min(y)+min(y)/4), max(y)+max(y)/4])
    plt.grid(True)
    plt.xlabel('x(t)')
    plt.ylabel('y(t)')
    plt.title('Phase Space')
    '''
    # Show Plot
    plt.show()

plot1D("./output/out.txt")
