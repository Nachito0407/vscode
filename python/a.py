import numpy as np
import matplotlib.pyplot as plt

def presion_func(altura):
    P0 = 101325
    L = -0.0065
    T0 = 288.15
    g = 9.81
    M = 0.0289644
    R = 8.31447
    
    return P0 * (1 - (L * altura) / T0) ** ((g * M) / (R * L))

altitudes = np.linspace(0, 20000, 1000)
presiones = presion_func(altitudes)

plt.figure(figsize=(10, 6))
plt.plot(presiones, altitudes)
plt.title('Presión en función de la Altitud')
plt.xlabel('Presión (Pa)')
plt.ylabel('Altitud (m)')
plt.grid(True)
plt.gca().invert_yaxis()  # Invertir el eje y para que la altitud aumente hacia arriba
plt.show()
