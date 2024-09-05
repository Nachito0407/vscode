import matplotlib.pyplot as plt
import numpy as np

# Configurar la gráfica
fig, ax = plt.subplots(figsize=(10, 6))
ax.set_xlim(-20, 130)
ax.set_ylim(-20, 60)

# Dibujar los lentes
ax.plot([0, 0], [-20, 60], 'k-', lw=2, label="Lente 1 (f1 = 40 cm)")
ax.plot([50, 50], [-20, 60], 'k-', lw=2, label="Lente 2 (f2 = 20 cm)")

# Posiciones importantes
objeto_x = -80
imagen1_x = 80  # Imagen formada por el primer lente
objeto2_x = 30  # Objeto para el segundo lente (imagen del primer lente)
imagen2_x = 62  # Imagen final formada por el segundo lente (12 cm del lente 2)

# Dibujar el objeto
ax.plot([objeto_x, objeto_x], [0, 20], 'g-', lw=2, label="Objeto")

# Rayos para el primer lente
ax.plot([objeto_x, 0], [10, 10], 'b--')  # Rayo paralelo al eje óptico
ax.plot([0, imagen1_x], [10, 0], 'b--')  # Rayo que pasa por el foco después del primer lente
ax.plot([objeto_x, 0], [10, 40], 'r--')  # Rayo que pasa por el centro del lente sin desviarse
ax.plot([0, imagen1_x], [40, 0], 'r--')  # Rayo que continúa sin desviarse

# Dibujar la imagen del primer lente
ax.plot([imagen1_x, imagen1_x], [0, 20], 'm-', lw=2, label="Imagen 1 (real)")

# Rayos para el segundo lente
ax.plot([imagen1_x, 50], [0, 0], 'g--')  # Rayo paralelo al eje óptico
ax.plot([50, imagen2_x], [0, 20], 'g--')  # Rayo que pasa por el foco después del segundo lente
ax.plot([imagen1_x, 50], [0, -20], 'r--')  # Rayo que pasa por el centro del lente sin desviarse
ax.plot([50, imagen2_x], [-20, 20], 'r--')  # Rayo que continúa sin desviarse

# Dibujar la imagen del segundo lente
ax.plot([imagen2_x, imagen2_x], [0, 20], 'c-', lw=2, label="Imagen 2 (real)")

# Configurar el gráfico
ax.axhline(0, color='black', lw=0.5)
ax.axvline(0, color='black', lw=0.5)
ax.axvline(50, color='black', lw=0.5)
ax.set_xlabel("Distancia (cm)")
ax.set_ylabel("Altura (cm)")
ax.legend()
ax.grid(True)

plt.title("Trazado de Rayos a través de dos lentes convergentes")
plt.show()
