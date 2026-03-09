import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# Definición de la Función de Transferencia
# H(s) = 10^8 / (s^2 + 11000s + 1.1*10^8)
num = [1e8]
den = [1, 11000, 1.1e8]

# Crear el sistema
sys = signal.TransferFunction(num, den)

# Calcular Bode
w, mag, phase = signal.bode(sys, w=np.logspace(2, 6, 1000)) # De 100 a 1,000,000 rad/s

# Configuración de la figura
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8), sharex=True)

# 1. Gráfico de Magnitud
ax1.semilogx(w, mag, color='blue', linewidth=2)
ax1.set_title('Diagrama de Bode')
ax1.set_ylabel('Magnitud (dB)')
ax1.grid(True, which="both", ls="-", alpha=0.6)
ax1.axvline(x=10488, color='red', linestyle='--', label='ω0 = 10,488 rad/s')
ax1.legend()

# 2. Gráfico de Fase
ax2.semilogx(w, phase, color='green', linewidth=2)
ax2.set_ylabel('Fase (grados)')
ax2.set_xlabel('Frecuencia (rad/s)')
ax2.grid(True, which="both", ls="-", alpha=0.6)
ax2.set_yticks([0, -45, -90, -135, -180])
ax2.axvline(x=10488, color='red', linestyle='--')

plt.tight_layout()
plt.show()