import numpy as np
import matplotlib.pyplot as plt
from control import TransferFunction, bode

# Definir H(s) = s / (s + 2)
num = [1, 0]
den = [1, 2]
H = TransferFunction(num, den)

# Rango de frecuencias
w = np.logspace(-2, 3, 1000)

# Calcular magnitud y fase sin plot automático
mag, phase, omega = bode(H, w, plot=False)  # Cambiado Plot a plot

# Dibujar Bode
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(6, 4))

# Magnitud en dB
ax1.semilogx(omega, 20 * np.log10(mag))
ax1.set_ylabel('Magnitud (dB)')
ax1.grid(which='both', linestyle='--', alpha=0.5)
# Línea de quiebre en ω=2 y nivel –3 dB
ax1.axvline(2, color='red', linestyle=':')
ax1.axhline(-3, color='red', linestyle=':')

# Fase en grados
ax2.semilogx(omega, np.degrees(phase))
ax2.set_ylabel('Fase (°)')
ax2.set_xlabel('Frecuencia ω (rad/s)')
ax2.grid(which='both', linestyle='--', alpha=0.5)
# Regiones de aproximación de fase
ax2.axvline(0.2, color='red', linestyle=':')
ax2.axvline(20, color='red', linestyle=':')

plt.tight_layout()
plt.show()