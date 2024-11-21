import matplotlib.pyplot as plt
import numpy as np

# Configuración del trazado
fig, ax = plt.subplots(figsize=(10, 6))

# Datos iniciales
f_lens = 20  # distancia focal de la lente (cm)
d_object_lens = 30  # distancia del objeto a la lente (cm)
f_mirror = 22.24  # distancia focal del espejo (cm)
d_lens_mirror = 100  # distancia entre la lente y el espejo (cm)

# Cálculo de la imagen generada por la lente
d_image_lens = 1 / (1 / f_lens - 1 / d_object_lens)

# Cálculo del objeto para el espejo
d_object_mirror = d_lens_mirror - d_image_lens

# Cálculo de la imagen generada por el espejo
d_image_mirror = 1 / (1 / f_mirror - 1 / d_object_mirror)

# Coordenadas
object_x = 0  # posición del objeto
lens_x = d_object_lens  # posición de la lente
image_lens_x = lens_x + d_image_lens  # posición de la imagen de la lente
mirror_x = lens_x + d_lens_mirror  # posición del espejo
image_mirror_x = mirror_x + d_image_mirror  # posición de la imagen del espejo

# Dibujar sistema óptico
ax.axvline(lens_x, color="blue", linestyle="--", label="Lente convergente")
ax.axvline(mirror_x, color="red", linestyle="--", label="Espejo cóncavo")

# Dibujar objeto, imágenes y rayos
ax.plot(object_x, 0, "o", color="green", label="Objeto")
ax.plot(image_lens_x, 0, "o", color="purple", label="Imagen (lente)")
ax.plot(image_mirror_x, 0, "o", color="orange", label="Imagen final (espejo)")

# Rayos de luz
# Rayo paralelo y focal en la lente
ax.plot([object_x, lens_x], [0, 3], color="black")  # del objeto al lente
ax.plot([lens_x, image_lens_x], [3, 0], color="black", linestyle="--")  # después de la lente

# Rayo paralelo y focal en el espejo
ax.plot([image_lens_x, mirror_x], [0, 2], color="black")  # hacia el espejo
ax.plot([mirror_x, image_mirror_x], [2, 0], color="black", linestyle="--")  # después del espejo

# Configuración gráfica
ax.axhline(0, color="black", linewidth=0.8)  # Eje óptico
ax.set_xlim(-10, mirror_x + 50)
ax.set_ylim(-5, 5)
ax.set_xlabel("Posición (cm)")
ax.set_ylabel("Eje óptico")
ax.legend()
ax.set_title("Trazado de rayos en el sistema óptico")

plt.grid()
plt.show()
