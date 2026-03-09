import numpy as np
import matplotlib.pyplot as plt

# Parámetros del circuito calculados
R1, R2 = 100, 1000
L = 0.01
C = 1e-6
V1 = 1  # Asumimos 1V para la escala

# Parámetros de la respuesta
alpha = 5500
wd = 8930  # omega_d
i_final = V1 / (R1 + R2) # 0.000909 A

# Constantes A y B halladas en el paso anterior
A = -i_final
# B se calculó usando di/dt(0) = V1/L
# di/dt(0) = -alpha*A + wd*B = V1/L
B = ( (V1/L) + alpha*A ) / wd 

# Vector de tiempo (de 0 a 2.5 milisegundos para ver el transitorio completo)
t = np.linspace(0, 0.0025, 1000)

# Ecuación de la corriente
i_t = i_final + np.exp(-alpha * t) * (A * np.cos(wd * t) + B * np.sin(wd * t))

# Convertir a miliamperios para mejor lectura
i_t_mA = i_t * 1000
t_ms = t * 1000

# Graficar
plt.figure(figsize=(10, 6))
plt.plot(t_ms, i_t_mA, label=r'$i(t)$', color='blue', linewidth=2)
plt.axhline(y=i_final*1000, color='r', linestyle='--', label='Estado Estable (0.909 mA)')
plt.title('Respuesta Subamortiguada de la Corriente i(t)')
plt.xlabel('Tiempo (ms)')
plt.ylabel('Corriente (mA)')
plt.grid(True, which='both', linestyle='--', alpha=0.7)
plt.legend()
plt.show()