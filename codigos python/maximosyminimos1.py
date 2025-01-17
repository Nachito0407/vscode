import numpy as np
import matplotlib.pyplot as plt

# Crear una malla para el dominio
x_vals = np.linspace(0, 2, 100)
y_vals = np.linspace(0, 1, 100)
X, Y = np.meshgrid(x_vals, y_vals)

# Evaluar la función en la malla
Z = X - X**2 + Y**2

# Graficar la superficie
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')

# Superficie
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.8)

# Marcar los puntos clave
critical_point = (0.5, 0, 0.25)
vertices = [(0, 0, 0), (0, 1, 1), (2, 0, -2), (2, 1, -1)]
extreme_points = vertices + [critical_point]

for point in extreme_points:
    ax.scatter(point[0], point[1], point[2], color='red', s=50, label=f"({point[0]}, {point[1]}, {point[2]})")

# Ajustes de la gráfica
ax.set_title("Gráfico de la función f(x, y)", fontsize=16)
ax.set_xlabel("x", fontsize=12)
ax.set_ylabel("y", fontsize=12)
ax.set_zlabel("f(x, y)", fontsize=12)

# Leyenda para identificar puntos clave
ax.legend(["Superficie", "Puntos clave"], loc='upper left')

plt.show()
