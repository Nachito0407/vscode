import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def draw_branch(ax, x, y, z, dx, dy, dz, depth, angle=np.pi/6):
    if depth == 0:
        return

    # Punto final de la rama
    x2, y2, z2 = x + dx, y + dy, z + dz
    ax.plot([x, x2], [y, y2], [z, z2], color='brown')

    # Rotaciones para bifurcación (3 ramas)
    for theta in [-angle, 0, angle]:
        for phi in [-angle, angle]:
            # Vector rotado en 3D
            new_dx = dx * np.cos(theta) + dy * np.sin(theta)
            new_dy = -dx * np.sin(theta) + dy * np.cos(theta)
            new_dz = dz * 0.7  # Reduce altura para cada nivel
            draw_branch(ax, x2, y2, z2, new_dx * 0.7, new_dy * 0.7, new_dz, depth - 1)

# Crear figura 3D
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Dibujar el árbol
draw_branch(ax, 0, 0, 0, 0, 0, 1, depth=5)

# Ajustes de vista
ax.set_xlim(-2, 2)
ax.set_ylim(-2, 2)
ax.set_zlim(0, 4)
plt.title("Árbol Fractal 3D")
plt.show()
