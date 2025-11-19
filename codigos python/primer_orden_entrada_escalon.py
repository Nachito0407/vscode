import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
from matplotlib.animation import FuncAnimation

# Entrada escalón unitario
def entrada(t):
    return 1

# Ecuación diferencial para sistema de primer orden: dy/dt = (x(t) - y)/tau
def sistema(y, t, tau):
    return (entrada(t) - y) / tau

# Tiempo
t = np.linspace(0, 10, 500)

# Diferentes constantes de tiempo para comparar
taus = [0.5, 1.0, 2.0]

# Preparar figura
fig, ax = plt.subplots(figsize=(10, 6))
ax.set_xlim(0, t[-1])
ax.set_ylim(0, 1.2)
ax.set_xlabel('Tiempo [s]')
ax.set_ylabel('Respuesta $y(t)$')
ax.set_title('Respuesta sistema 1er orden ante entrada escalón unitario')
ax.grid(True)

# Resolver para cada tau y preparar líneas vacías
ys = [odeint(sistema, 0, t, args=(tau,)).flatten() for tau in taus]
lines = [ax.plot([], [], label=f'$\\tau = {tau}$')[0] for tau in taus]

# Graficar entrada escalón unitario
ax.plot(t, np.ones_like(t), 'k--', label='$x(t) = 1$')

def init():
    for line in lines:
        line.set_data([], [])
    return lines

def animate(frame):
    time = t[:frame]
    for i, line in enumerate(lines):
        line.set_data(time, ys[i][:frame])
    return lines

ani = FuncAnimation(fig, animate, frames=len(t), init_func=init, interval=25, blit=True)

ax.legend()
plt.show()
