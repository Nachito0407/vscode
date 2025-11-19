import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Constantes de tiempo diferentes
taus = [0.5, 1.0, 2.0]

# Tiempo de simulación
t = np.linspace(0, 10, 500)

# Función respuesta impulso unitario
def respuesta_impulso(t, tau):
    y = np.zeros_like(t)
    y[t >= 0] = (1/tau) * np.exp(-t[t >= 0]/tau)
    return y

# Preparar figura para animar
fig, ax = plt.subplots(figsize=(10, 5))
ax.set_xlim(0, t[-1])
ax.set_ylim(0, 2.5)
ax.set_xlabel('Tiempo [s]')
ax.set_ylabel('Respuesta $y(t)$')
ax.set_title('Respuesta impulso unitario - sistema primer orden')
ax.grid(True)

# Cálculo de respuestas estáticas
ys = [respuesta_impulso(t, tau) for tau in taus]
lines = [ax.plot([], [], label=f'$\\tau={tau}$')[0] for tau in taus]

def init():
    for line in lines:
        line.set_data([], [])
    return lines

def animate(frame):
    current_t = t[:frame]
    for i, line in enumerate(lines):
        line.set_data(current_t, ys[i][:frame])
    return lines

# Crear animación
ani = FuncAnimation(fig, animate, frames=len(t), init_func=init, interval=25, blit=True)

ax.legend()
plt.show()
