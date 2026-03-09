import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# 1. Definir la Función de Transferencia
# H(s) = (s + 5) / (s + 2)^2
# H(s) = (s + 5) / (s^2 + 4s + 4)

# Los coeficientes se ponen en orden descendente de potencias de 's'
num = [1, 5]          # 1*s + 5
den = [1, 4, 4]       # 1*s^2 + 4*s + 4

# Creamos el sistema
system = signal.TransferFunction(num, den)

# 2. Generar datos para el Diagrama de Bode
# Definimos el rango de frecuencias (de 10^-1 a 10^2 rad/s) para ver bien la curva
w_start = 0.1
w_stop = 100
w_range = np.logspace(np.log10(w_start), np.log10(w_stop), 1000)

# signal.bode devuelve: frecuencias (w), magnitud (mag) y fase (phase)
w, mag, phase = signal.bode(system, w_range)

# 3. Graficar la Magnitud
plt.figure(figsize=(10, 6))

# Trazado de la curva real
plt.semilogx(w, mag, label='Respuesta Real (Magnitud)', color='b', linewidth=2)

# --- Decoración del gráfico para análisis ---
plt.title('Diagrama de Bode de Magnitud: H(s) = (s+5)/(s+2)^2')
plt.xlabel('Frecuencia [rad/s]')
plt.ylabel('Magnitud [dB]')
plt.grid(which='both', axis='both', linestyle='--', linewidth=0.5)

# Marcar las frecuencias de corte teóricas (Polos y Ceros)
plt.axvline(x=2, color='r', linestyle='--', label='Polo doble (w=2 rad/s)')
plt.axvline(x=5, color='g', linestyle='--', label='Cero simple (w=5 rad/s)')

# Marcar la ganancia en DC aproximada (aprox 1.94 dB)
plt.axhline(y=20*np.log10(1.25), color='orange', linestyle=':', label='Ganancia DC (~1.94 dB)')

plt.legend()
plt.tight_layout()

# Mostrar gráfico
plt.show()