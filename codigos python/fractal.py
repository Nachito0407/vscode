import numpy as np
import matplotlib.pyplot as plt

# Configuración del tamaño de la imagen y los límites del gráfico
width, height = 800, 800
x_min, x_max = -2.0, 1.0
y_min, y_max = -1.5, 1.5

# Número máximo de iteraciones para determinar la pertenencia al conjunto
max_iter = 256

# Crear una matriz vacía para almacenar los valores de color de cada píxel
image = np.zeros((height, width))

# Generar el fractal
for x in range(width):
    for y in range(height):
        zx = x * (x_max - x_min) / (width - 1) + x_min
        zy = y * (y_max - y_min) / (height - 1) + y_min
        c = complex(zx, zy)
        z = 0 + 0j
        for i in range(max_iter):
            if abs(z) > 2.0:
                break
            z = z * z + c
        image[y, x] = i

# Mostrar el fractal
plt.imshow(image, extent=(x_min, x_max, y_min, y_max), cmap='inferno')
plt.colorbar()
plt.title("Conjunto de Mandelbrot")
plt.xlabel("Re(z)")
plt.ylabel("Im(z)")
plt.show()
