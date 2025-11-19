import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
from scipy.signal import lti, step

# Parámetros iniciales
K = 1.0
T_e_init = 0.1
T_m_init = 0.5

t = np.linspace(0, 5, 500)

fig, (ax_plot, ax_polos) = plt.subplots(2, 1, figsize=(8, 10))
plt.subplots_adjust(left=0.15, bottom=0.3, hspace=0.35)

# Configuración gráfico respuesta temporal
#ax_plot.set_title('Respuesta temporal motor de CC (entrada escalón)')
ax_plot.set_xlabel('Tiempo [s]')
ax_plot.set_ylabel('Velocidad Angular [rad/s]')
ax_plot.set_xlim(0, 5)
ax_plot.set_ylim(0, 1.2 * K)
ax_plot.grid(True)

# Anotación fórmula transferencia
formula = r"$G(s) = \frac{K}{(T_e s + 1)(T_m s + 1)}$"
ax_plot.annotate(formula, xy=(0.5, 1.05), xycoords='axes fraction', ha='center', fontsize=16)

# Configuración gráfico polos
#ax_polos.set_title('Polos del sistema')
ax_polos.set_xlabel('Parte real σ')
ax_polos.set_ylabel('Parte imaginaria jω')
ax_polos.axhline(0, color='black', lw=0.8)
ax_polos.axvline(0, color='black', lw=0.8)
ax_polos.grid(True)

ax_polos.set_xlim(-10, 1)
ax_polos.set_ylim(-5, 5)

# Función de transferencia y cálculo de polos
def transfer_function(T_e, T_m):
    num = [K]
    den = np.convolve([T_e, 1], [T_m, 1])
    return lti(num, den)

def get_polos(T_e, T_m):
    system = transfer_function(T_e, T_m)
    return system.poles

# Datos iniciales
system = transfer_function(T_e_init, T_m_init)
t_out, y_out = step(system, T=t)
line, = ax_plot.plot(t_out, y_out, lw=2, color='b')

poles = get_polos(T_e_init, T_m_init)
poles_plot, = ax_polos.plot(poles.real, poles.imag, 'x', ms=10, mew=2, color='r')

# Sliders
axcolor = 'lightgoldenrodyellow'
ax_Te = plt.axes([0.15, 0.15, 0.65, 0.03], facecolor=axcolor)
ax_Tm = plt.axes([0.15, 0.1, 0.65, 0.03], facecolor=axcolor)

slider_Te = Slider(ax_Te, 'Const. Tiempo Eléctrica T_e [s]', 0.01, 2.0, valinit=T_e_init)
slider_Tm = Slider(ax_Tm, 'Const. Tiempo Mecánica T_m [s]', 0.01, 2.0, valinit=T_m_init)

def update(val):
    T_e = slider_Te.val
    T_m = slider_Tm.val
    system = transfer_function(T_e, T_m)
    t_out, y_out = step(system, T=t)
    line.set_data(t_out, y_out)
    ax_plot.set_ylim(0, 1.2 * max(y_out))

    polos = get_polos(T_e, T_m)
    poles_plot.set_data(polos.real, polos.imag)

    fig.canvas.draw_idle()

slider_Te.on_changed(update)
slider_Tm.on_changed(update)

plt.show()
