import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
from matplotlib.animation import FuncAnimation


# Ecuación diferencial segundo orden con entrada escalón unitario
def sistema(y, t, zeta, omega_n):
    u = 1 if t >= 0 else 0  # entrada escalón unitario
    dy1dt = y[1]
    dy2dt = -2*zeta*omega_n*y[1] - omega_n**2*y[0] + u
    return [dy1dt, dy2dt]


omega_n = 5.0  # frecuencia natural
zetas = [0.1, 0.5, 1.0]
t = np.linspace(0, 5, 1000)
y0 = [0, 0]  # condiciones iniciales nulas


ys = []
for zeta in zetas:
    sol = odeint(sistema, y0, t, args=(zeta, omega_n))
    ys.append(sol[:, 0])


fig, ax = plt.subplots(figsize=(10, 6))
ax.set_xlim(t[0], t[-1])
ax.set_ylim(np.min(ys)*1.1, np.max(ys)*1.1)
ax.set_xlabel('Tiempo (s)')
ax.set_ylabel('Respuesta $y(t)$')
ax.set_title('Respuesta sistema 2º orden ante escalón unitario\nCondiciones iniciales nulas')
ax.grid(True)


lines = [ax.plot([], [], label=f'$\\zeta={zeta}$')[0] for zeta in zetas]


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
