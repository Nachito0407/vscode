import numpy as np
import matplotlib.pyplot as plt

# Establecemos el rango para x entre 1 y 9 para representar los puntos (1 + i) a (9 + 3i)
x_vals = np.linspace(1, 9, 100)
y_vals = np.sqrt(x_vals)  # y = sqrt(x)

# Convertimos los puntos para graficar en el plano complejo
z_vals_real = x_vals  # Parte real de z
z_vals_imag = y_vals  # Parte imaginaria de z

# Puntos inicial y final
z_start = 1 + 1j  # (1, 1)
z_end = 9 + 3j    # (9, 3)

# Crear la figura
plt.figure(figsize=(10, 6))
plt.plot(z_vals_real, z_vals_imag, label=r'$y = \sqrt{x}$', color='blue')  # La curva
plt.scatter([z_start.real, z_end.real], [z_start.imag, z_end.imag], color='red')  # Puntos inicial y final

# Anotaciones para los puntos
plt.text(z_start.real, z_start.imag, '  $1 + i$', color='red', fontsize=12, verticalalignment='bottom')
plt.text(z_end.real, z_end.imag, '  $9 + 3i$', color='red', fontsize=12, verticalalignment='bottom')

# Etiquetas y estilo del gráfico
plt.xlabel('Parte Real (x)')
plt.ylabel('Parte Imaginaria (y)')
plt.title('Curva en el plano complejo: $y = \sqrt{x}$ de $1 + i$ a $9 + 3i$')
plt.grid(True)
plt.legend()
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)

plt.show()
