import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import lti, step
from matplotlib.widgets import Slider

omega_n = 5.0
t_resp = np.linspace(0, 5, 500)
zeta_init = 0.5  # amortiguamiento inicial

fig, (ax_polos, ax_resp) = plt.subplots(2, 1, figsize=(8, 10))
plt.subplots_adjust(left=0.1, bottom=0.25)

# Gráfico de polos
ax_polos.set_xlim(-6, 1)
ax_polos.set_ylim(-6, 6)
ax_polos.grid(True)
ax_polos.axhline(0, color='black', linewidth=1)
ax_polos.axvline(0, color='black', linewidth=1)
poles_points, = ax_polos.plot([], [], 'x', color='red', markersize=10, label='Polos')
ax_polos.legend()

# Ajuste posición etiquetas
ax_polos.set_xlabel('σ')
ax_polos.xaxis.set_label_coords(1.01, 0.5)

ax_polos.set_ylabel('jω')
ax_polos.yaxis.set_label_coords(0.90, 0.95)

ax_polos.set_title('Movimiento de polos sistema segundo orden')

# Gráfico de respuesta temporal
ax_resp.set_xlim(t_resp[0], t_resp[-1])
ax_resp.set_ylim(-0.5, 2)
ax_resp.set_xlabel('Tiempo (s)')
ax_resp.set_ylabel('Respuesta $y(t)$')
ax_resp.set_title('Respuesta temporal ante escalón unitario')
ax_resp.grid(True)
response_line, = ax_resp.plot([], [], 'b', label='Respuesta')
ax_resp.legend()

# Slider para amortiguamiento ζ (0.01 a 2)
ax_slider = plt.axes([0.25, 0.1, 0.5, 0.03])
slider_zeta = Slider(ax_slider, 'Amortiguamiento ζ', 0.01, 2.0, valinit=zeta_init)

def calcular_polos(zeta, omega_n):
    if zeta < 1:
        real = -zeta * omega_n
        imag = omega_n * np.sqrt(1 - zeta**2)
        return np.array([real + 1j*imag, real - 1j*imag])
    else:
        return np.array([-omega_n*(zeta - np.sqrt(zeta**2 - 1)),
                         -omega_n*(zeta + np.sqrt(zeta**2 - 1))])

def calcular_respuesta(zeta, omega_n, t):
    system = lti([omega_n**2], [1, 2*zeta*omega_n, omega_n**2])
    t_out, y_out = step(system, T=t)
    return t_out, y_out

def update(val):
    zeta = slider_zeta.val
    p = calcular_polos(zeta, omega_n)
    poles_points.set_data(np.real(p), np.imag(p))
    
    t_out, y_out = calcular_respuesta(zeta, omega_n, t_resp)
    response_line.set_data(t_out, y_out)
    
    ax_polos.set_title(f'Movimiento de polos - Amortiguamiento ζ = {zeta:.2f}')
    ax_resp.set_title(f'Respuesta temporal - Amortiguamiento ζ = {zeta:.2f}')
    
    fig.canvas.draw_idle()

slider_zeta.on_changed(update)

update(zeta_init)

plt.show()
