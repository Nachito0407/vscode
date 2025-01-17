import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Parámetros del péndulo
longitud = 2.0  # Longitud del péndulo (metros)
gravedad = 9.81  # Aceleración gravitacional (m/s^2)
amplitud_inicial = np.radians(50)  # Ángulo inicial (grados a radianes)
dt = 0.01  # Paso de tiempo (segundos)

# Cálculo del período del péndulo
periodo = 2 * np.pi * np.sqrt(longitud / gravedad)

# Función del movimiento del péndulo (aproximación para ángulos pequeños)
def angulo(t, theta0, g, l):
    omega = np.sqrt(g / l)  # Frecuencia angular
    return theta0 * np.cos(omega * t)

# Configuración de la figura
fig, ax = plt.subplots()
ax.set_xlim(-longitud - 0.5, longitud + 0.5)
ax.set_ylim(-longitud - 0.5, 0.5)
ax.set_aspect('equal')
ax.set_title("Animación de un Péndulo Simple")

# Elementos del gráfico
linea, = ax.plot([], [], lw=2, color='blue')
punto, = ax.plot([], [], 'o', color='red')

# Función de inicialización
def init():
    linea.set_data([], [])
    punto.set_data([], [])
    return linea, punto

# Función de actualización
def actualizar(frame):
    t = frame * dt
    theta = angulo(t, amplitud_inicial, gravedad, longitud)
    
    # Posición del péndulo
    x = longitud * np.sin(theta)
    y = -longitud * np.cos(theta)
    
    linea.set_data([0, x], [0, y])
    punto.set_data([x], [y])
    return linea, punto

# Configuración de la animación
frames = int(periodo / dt)  # Número de frames en un período
anim = FuncAnimation(fig, actualizar, frames=frames, init_func=init, blit=True, repeat=True, interval=10)

# Mostrar la animación
plt.show()