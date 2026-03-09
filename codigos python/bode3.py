import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# --- 1. Definición del sistema ---

# Función de transferencia: H(s) = 5s / ((s+20)(s+5000))

# Numerador: 5s
# En Python los coeficientes van de mayor a menor potencia de s: [s^1, s^0]
num = [5, 0] 

# Denominador: (s+20) * (s+5000)
# Podemos multiplicarlos manualmente (s^2 + 5020s + 100000) 
# o usar convolución para que Python haga la multiplicación de polinomios:
polo1 = [1, 20]
polo2 = [1, 5000]
den = np.convolve(polo1, polo2) # Resultado: [1, 5020, 100000]

# Crear el objeto del sistema lineal
sys = signal.TransferFunction(num, den)

# --- 2. Configuración de frecuencias ---

# Generamos un vector de frecuencias logarítmico.
# np.logspace(inicio_exponente, fin_exponente, cantidad_puntos)
# 10^-1 = 0.1 rad/s  hasta  10^6 = 1,000,000 rad/s
w_start = -1 
w_stop = 6
w = np.logspace(w_start, w_stop, 1000)

# Calcular la respuesta en frecuencia (Bode)
w, mag, phase = signal.bode(sys, w)

# --- 3. Graficar ---

plt.figure(figsize=(10, 8)) # Tamaño de la imagen

# -- Subplot 1: Magnitud --
plt.subplot(2, 1, 1)
plt.semilogx(w, mag, 'b', linewidth=2) # 'b' es blue (azul)
plt.title('Diagrama de Bode: H(s) = 5s / [(s+20)(s+5000)]')
plt.ylabel('Magnitud (dB)')
plt.grid(which='both', axis='both', alpha=0.5)

# Marcar las frecuencias de corte (los polos)
plt.axvline(20, color='r', linestyle='--', label='ω = 20 rad/s')
plt.axvline(5000, color='g', linestyle='--', label='ω = 5000 rad/s')
plt.legend()

# -- Subplot 2: Fase --
plt.subplot(2, 1, 2)
plt.semilogx(w, phase, 'r', linewidth=2) # 'r' es red (rojo)
plt.ylabel('Fase (grados)')
plt.xlabel('Frecuencia (rad/s)')
plt.grid(which='both', axis='both', alpha=0.5)

# Marcar las frecuencias de corte también aquí
plt.axvline(20, color='b', linestyle='--')
plt.axvline(5000, color='g', linestyle='--')
plt.yticks(np.arange(-90, 100, 45)) # Forzar marcas cada 45 grados para mejor lectura

plt.tight_layout()
plt.show()