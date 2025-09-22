import numpy as np
import matplotlib.pyplot as plt

# Definir la función original en (0,2]
def f_original(t):
    return 1 + 0.5*t**2

# Intervalo para graficar varios periodos
t = np.linspace(-2, 6, 2000)
f = np.zeros_like(t)

# Construir la extensión periódica de periodo 2
for k in range(-2, 4):
    mask = (t > 2*k) & (t <= 2*(k+1))
    f[mask] = f_original(t[mask]-2*k)

# Graficar
plt.figure(figsize=(10,5))
plt.plot(t, f, label="Extensión periódica", color="blue")
plt.axhline(0, color="black", linewidth=0.8)
plt.axvline(0, color="black", linewidth=0.8)

# Marcar extremos abiertos (círculos huecos) y cerrados (círculos llenos)
for k in range(-2,4):
    # extremo izquierdo abierto en (2k, valor=1)
    plt.plot(2*k, 1, 'o', color="blue", markerfacecolor="white", markersize=8)
    # extremo derecho cerrado en (2k+2, valor=3)
    plt.plot(2*k+2, 3, 'o', color="blue", markersize=8)
    # punto de convergencia de la serie (promedio=2)
    plt.plot(2*k, 2, 'ro')

plt.title("Extensión 2-periódica de f(t)=1+(1/2)t^2 con extremos abiertos/cerrados")
plt.xlabel("t")
plt.ylabel("f(t)")
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend()
plt.show()