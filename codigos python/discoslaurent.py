import matplotlib.pyplot as plt

# Configuración básica del gráfico
fig, ax = plt.subplots(figsize=(6, 6))

# Coordenadas del centro
z0 = 0 + 2j

# Radios de los anillos
radii = [1, 2]

# Dibujar las regiones de los anillos
# Región 1: |z - z0| < 1 (Serie de Taylor)
circle1 = plt.Circle((z0.real, z0.imag), radii[0], color='lightblue', alpha=0.5, label=r"$|z - 2i| < 1$")

# Región 2: 1 < |z - z0| < 2 (Serie de Laurent)
circle2_outer = plt.Circle((z0.real, z0.imag), radii[1], color='lightgreen', alpha=0.5, label=r"$1 < |z - 2i| < 2$")
circle2_inner = plt.Circle((z0.real, z0.imag), radii[0], color='white', zorder=10)  # Espacio vacío para el anillo

# Dibujar las singularidades (z = 0, z = 1, z = i)
singularidades = [0, 1, 1j]  # Coordenadas de las singularidades

# Agregar las regiones
ax.add_artist(circle1)  # Región 1
ax.add_artist(circle2_outer)  # Parte externa de la región 2
ax.add_artist(circle2_inner)  # Parte interna (vacía)

# Agregar puntos para las singularidades
for sing in singularidades:
    ax.plot(sing.real, sing.imag, 'ro', label=f"Singularidad en $z = {sing}$")

# Agregar el centro del desarrollo (z0 = 2i)
ax.plot(z0.real, z0.imag, 'bo', label=r"Centro $z_0 = 2i$")

# Configuración del gráfico
ax.set_xlim(-3, 3)
ax.set_ylim(-1, 5)
ax.set_aspect('equal', 'box')
ax.axhline(0, color='black', linewidth=0.5, linestyle='--')
ax.axvline(0, color='black', linewidth=0.5, linestyle='--')
ax.set_title("Regiones de convergencia alrededor de $z_0 = 2i$", fontsize=14)
ax.set_xlabel("Re(z)", fontsize=12)
ax.set_ylabel("Im(z)", fontsize=12)
ax.legend(loc='upper right', fontsize=10)
plt.grid(alpha=0.3)

# Mostrar el gráfico
plt.show()