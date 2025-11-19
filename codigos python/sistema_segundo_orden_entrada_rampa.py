import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
from matplotlib.animation import FuncAnimation

def sistema(y, t, zeta, omega_n):
    u = t  # entrada rampa unitaria: u(t) = t
    dy1dt = y[1]
    dy2dt = -2*zeta*omega_n*y[1] - omega_n**2*y[0] + u
    return [dy1dt, dy2dt]

omega_n = 5.0  # frecuencia natural
zetas = [0.05, 0.1, 0.5, 1.0]  # diferentes amortiguamientos

t = np.linspace(0, 5, 1000)
y0 = [0, 0]  # condiciones iniciales nulas

ys = []
for zeta in zetas:
    sol = odeint(sistema, y0, t, args=(zeta, omega_n))
    ys.append(sol[:, 0])

fig, ax = plt.subplots(figsize=(10, 6))
ax.set_xlim(t[0], t[-1])
ylim_min = np.min(ys) * 1.1
ylim_max = np.max(ys) * 1.1
ax.set_ylim(ylim_min, ylim_max)
ax.set_xlabel('Tiempo (s)')
ax.set_ylabel('Respuesta $y(t)$')
ax.set_title('Respuesta sistema 2º orden ante entrada rampa unitaria')
ax.grid(True)

labels = [f'$\\zeta={zeta}$ ' if zeta < 1 else f'$\\zeta={zeta}$' for zeta in zetas]
lines = [ax.plot([], [], label=label)[0] for label in labels]

def init():
    for line in lines:
        line.set_data([], [])
    return lines

def animate(i):
    time = t[:i]
    for line, y in zip(lines, ys):
        line.set_data(time, y[:i])
    return lines

ani = FuncAnimation(fig, animate, frames=len(t), init_func=init, interval=20, blit=True)

ax.legend()
plt.show()
