import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# 1. Definir la Función de Transferencia
# H(s) = (s + 5) / ((s + 1)(s + 4))
# Numerador: [1, 5]  -> 1*s + 5
# Denominador: (s + 1)(s + 4) = s^2 + 5s + 4 -> [1, 5, 4]

num = [1, 5]
den = [1, 5, 4]

# Creamos el sistema
sistema = signal.TransferFunction(num, den)

# 2. Definir el rango de frecuencias (escala logarítmica)
# Vamos de 10^-1 (0.1) a 10^2.5 (~300) rad/s para ver bien la curva
w = np.logspace(-1, 2.5, 1000)

# 3. Calcular la respuesta en frecuencia (Diagrama de Bode)
# w: frecuencias, mag: magnitud en dB, phase: fase en grados
w, mag, phase = signal.bode(sistema, w)

# --- GRAFICACIÓN ---
plt.figure(figsize=(10, 8))

# Subgráfico 1: Magnitud
plt.subplot(2, 1, 1)
plt.semilogx(w, mag, linewidth=2, color='blue')
plt.title('Diagrama de Bode - Magnitud')
plt.ylabel('Magnitud (dB)')
plt.grid(which='both', axis='both', linestyle='--', linewidth=0.5)

# Marcar puntos clave (Polos y Ceros)
puntos_clave = [1, 4, 5]
for p in puntos_clave:
    plt.axvline(x=p, color='green', linestyle=':', alpha=0.7)
    plt.text(p, min(mag), f' $\omega$={p}', rotation=90, verticalalignment='bottom')

# Marcar el punto del inciso a) omega = 3 rad/s
omega_a = 3
mag_a_idx = (np.abs(w - omega_a)).argmin() # Buscar índice más cercano
plt.plot(w[mag_a_idx], mag[mag_a_idx], 'ro', label=f'Inciso a: $\omega$=3 rad/s')
plt.legend()


# Subgráfico 2: Fase
plt.subplot(2, 1, 2)
plt.semilogx(w, phase, linewidth=2, color='orange')
plt.title('Diagrama de Bode - Fase')
plt.ylabel('Fase (grados)')
plt.xlabel('Frecuencia (rad/s)')
plt.grid(which='both', axis='both', linestyle='--', linewidth=0.5)

# Marcar el punto del inciso a) en la fase
plt.plot(w[mag_a_idx], phase[mag_a_idx], 'ro')
plt.text(w[mag_a_idx], phase[mag_a_idx]+5, f'{phase[mag_a_idx]:.2f}°', color='red')

plt.tight_layout()
plt.show()