import numpy as np
import matplotlib.pyplot as plt

# Parámetros del circuito
V1 = 10.0       # amplitud del escalón (modificalo si querés)
alpha = 5500    # coeficiente exponencial
wd = 8930       # frecuencia amortiguada rad/s

# Constantes obtenidas en la solución
K1 = -V1/1100
K2 = 0.01064 * V1
Iinf = V1 / 1100

# Vector de tiempo
t = np.linspace(0, 3e-3, 2000)  # 0 a 3 ms

# Respuesta completa de la corriente
i_t = Iinf + np.exp(-alpha*t)*(K1*np.cos(wd*t) + K2*np.sin(wd*t))

# Gráfica
plt.figure(figsize=(8,4))
plt.plot(t*1000, i_t, 'b', linewidth=2)
plt.grid(True)
plt.title("Corriente i(t) entregada por la fuente")
plt.xlabel("Tiempo [ms]")
plt.ylabel("Corriente i(t) [A]")
plt.axhline(Iinf, color='r', linestyle='--', label="I_infinito")
plt.legend()
plt.show()
