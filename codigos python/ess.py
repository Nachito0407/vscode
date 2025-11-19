import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from scipy.signal import step, lti

# Tiempo de simulacion
t = np.linspace(0, 10, 500)

# Entradas tipo 0-2
escalon = np.ones_like(t)
rampa = t
parabola = 0.5 * t**2
entradas = [escalon, rampa, parabola]
entradas_labels = ["Escalón unitario", "Rampa unitaria", "Parábola"]

def salida_tipo_0(entrada):
    if np.array_equal(entrada, escalon):
        return 0.85 * entrada
    else:
        return 0.2 * entrada

def salida_tipo_1(entrada):
    if np.array_equal(entrada, escalon):
        return entrada
    elif np.array_equal(entrada, rampa):
        return 0.8 * entrada
    else:
        return 0.1 * entrada

def salida_tipo_2(entrada):
    if np.array_equal(entrada, escalon) or np.array_equal(entrada, rampa):
        return entrada
    else:
        return 0.9 * entrada

def animacion_tipo(tipo_funcion, nombre_tipo):
    fig, axs = plt.subplots(1, 3, figsize=(18,5))
    fig.suptitle(f"Sistema {nombre_tipo} ante distintas entradas")

    salidas = [tipo_funcion(entrada) for entrada in entradas]
    lines_in, lines_out = [], []

    for i in range(3):
        axs[i].set_xlim(0, t[-1])
        # Ajuste de escala vertical exclusivo para escalón
        if i == 0:
            axs[i].set_ylim(-0.1, 1.2)
        else:
            axs[i].set_ylim(min(parabola)*1.1, max(parabola)*1.1)

        axs[i].set_title(entradas_labels[i])
        axs[i].set_xlabel("Tiempo (s)")
        axs[i].set_ylabel("Amplitud")
        line_in, = axs[i].plot([], [], 'b-', label='Entrada r(t)')
        line_out, = axs[i].plot([], [], 'g-', label='Salida c(t)')
        axs[i].legend()
        axs[i].grid()
        lines_in.append(line_in)
        lines_out.append(line_out)

    def animate(frame):
        for i in range(3):
            lines_in[i].set_data(t[:frame], entradas[i][:frame])
            lines_out[i].set_data(t[:frame], salidas[i][:frame])
        return lines_in + lines_out

    ani = FuncAnimation(fig, animate, frames=len(t), interval=20, blit=True, repeat=False)
    plt.show()

# Función para calcular respuesta para entradas escalón, rampa y parábola en sistemas con función transferencia
def respuesta_sistema_orden(sys, t):
    t_step, y_step = step(sys, T=t)
    y_rampa = np.cumsum(y_step) * (t[1] - t[0])
    y_parabola = np.cumsum(y_rampa) * (t[1] - t[0])
    return [y_step, y_rampa, y_parabola]

def animacion_sistema_orden(nombre, sys):
    entradas_labels_orden = ["Escalón unitario", "Rampa unitaria", "Parábola"]
    salidas = respuesta_sistema_orden(sys, t)

    fig, axs = plt.subplots(1, 3, figsize=(18,5))
    fig.suptitle(f"Sistema {nombre} ante distintas entradas")

    lines_in, lines_out = [], []

    for i in range(3):
        axs[i].set_xlim(0, t[-1])
        # Ajuste escala vertical para escalón solamente
        if i == 0:
            axs[i].set_ylim(-0.1, 1.2)
        else:
            axs[i].set_ylim(min(parabola)*1.1, max(parabola)*1.1)

        axs[i].set_title(entradas_labels_orden[i])
        axs[i].set_xlabel("Tiempo (s)")
        axs[i].set_ylabel("Amplitud")
        line_in, = axs[i].plot([], [], 'b-', label='Entrada r(t)')
        line_out, = axs[i].plot([], [], 'g-', label='Salida c(t)')
        axs[i].legend()
        axs[i].grid()
        lines_in.append(line_in)
        lines_out.append(line_out)

    entradas_orden = [np.ones_like(t), t, 0.5 * t**2]

    def animate(frame):
        for i in range(3):
            lines_in[i].set_data(t[:frame], entradas_orden[i][:frame])
            lines_out[i].set_data(t[:frame], salidas[i][:frame])
        return lines_in + lines_out

    ani = FuncAnimation(fig, animate, frames=len(t), interval=20, blit=True, repeat=False)
    plt.show()

# Animaciones sistemas tipo 0, 1, 2
animacion_tipo(salida_tipo_0, "Tipo 0")
animacion_tipo(salida_tipo_1, "Tipo 1")
animacion_tipo(salida_tipo_2, "Tipo 2")

# Parámetros sistemas primer y segundo orden
K = 1
tau = 2
wn = 2
# Sistema primer orden
sys_1er = lti([K], [tau, 1])
animacion_sistema_orden("Primer Orden", sys_1er)

# Sistema segundo orden con amortiguamiento ξ=0.7
sys_2do = lti([K*wn**2], [1, 2*0.7*wn, wn**2])
animacion_sistema_orden("Segundo Orden ξ=0.7", sys_2do)
