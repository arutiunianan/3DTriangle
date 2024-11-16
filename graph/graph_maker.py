import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection, Line3DCollection

def plot_triangle(ax, vertices, color='b'):
    unique_vertices = set(map(tuple, vertices))
    
    if len(unique_vertices) == 3:
        triangle = Poly3DCollection([vertices], color=color, alpha=0.5)
        ax.add_collection3d(triangle)
    elif len(unique_vertices) == 2:
        line = Line3DCollection([vertices], colors=color, linewidths=2)
        ax.add_collection3d(line)
    elif len(unique_vertices) == 1:
        ax.scatter(*vertices[0], color=color, s=30)

if __name__ == "__main__":
    triangle1 = np.array([[0, 5, 3], [5, 0, 0], [0, 0, 0]])
    triangle2 = np.array([[0, 0, 2], [2.5, 2.5, 1], [5, 5, 0]]) 
    triangle3 = np.array([[4, 2, 0], [4, 2, 0], [4, 2, 0]])

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    plot_triangle(ax, triangle1, color='r')
    plot_triangle(ax, triangle2, color='g')
    plot_triangle(ax, triangle3, color='b')

    ax.set_xlim([0, 6])
    ax.set_ylim([0, 6])
    ax.set_zlim([0, 6])

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    plt.show()
