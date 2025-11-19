import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
from matplotlib.animation import FuncAnimation

# Entrada x(t) = t
def entrada(t):
    return t

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
ax.set_ylim(0, max(entrada(t)) * 1.1)
ax.set_xlabel('Tiempo [s]')
ax.set_ylabel('Respuesta $y(t)$')
ax.set_title('Respuesta temporal sistema 1er orden ante entrada $x(t) = t$')
ax.grid(True)

# Resolver para cada tau y plot inicial vacío
ys = [odeint(sistema, 0, t, args=(tau,)).flatten() for tau in taus]
lines = [ax.plot([], [], label=f'$\\tau = {tau}$')[0] for tau in taus]

# Graficar entrada sin animación
ax.plot(t, entrada(t), 'k--', label='$x(t) = t$')

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
