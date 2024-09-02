import numpy as np
import matplotlib.pyplot as plt

# Configuración del tamaño de la imagen y los límites del gráfico
width, height = 800, 800
x_min, x_max = -1.5, 1.5
y_min, y_max = -1.5, 1.5

# Parámetro complejo del conjunto de Julia
c = complex(-0.7, 0.27015)

# Número máximo de iteraciones
max_iter = 256

# Crear una matriz vacía para almacenar los valores de color de cada píxel
image = np.zeros((height, width))

# Generar el fractal
for x in range(width):
    for y in range(height):
        zx = x * (x_max - x_min) / (width - 1) + x_min
        zy = y * (y_max - y_min) / (height - 1) + y_min
        z = complex(zx, zy)
        for i in range(max_iter):
            if abs(z) > 2.0:
                break
            z = z * z + c
        image[y, x] = i

# Mostrar el fractal
plt.imshow(image, extent=(x_min, x_max, y_min, y_max), cmap='twilight_shifted')
plt.colorbar()
plt.title("Conjunto de Julia")
plt.xlabel("Re(z)")
plt.ylabel("Im(z)")
plt.show()
