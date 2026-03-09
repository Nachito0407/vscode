import matplotlib.pyplot as plt
import numpy as np

# Datos calculados en el inciso c
# Formato: (Magnitud en Amperios, Ángulo en grados)
i_r2 = (0.143, 15.73)   # Corriente en la resistencia R2
i_c1 = (0.140, 105.73)  # Corriente en el capacitor C1

# Función auxiliar polar -> cartesiano
def pol2cart(mag, ang_deg):
    ang_rad = np.deg2rad(ang_deg)
    return mag * np.cos(ang_rad), mag * np.sin(ang_rad)

# Calcular componentes
dx_r2, dy_r2 = pol2cart(*i_r2)
dx_c1, dy_c1 = pol2cart(*i_c1)

# Resultante (debe dar aprox 0.2 a 60 grados)
dx_total = dx_r2 + dx_c1
dy_total = dy_r2 + dy_c1

# Configuración del gráfico
fig, ax = plt.subplots(figsize=(8, 8))

# 1. I_R2 (Desde el origen)
ax.arrow(0, 0, dx_r2, dy_r2, head_width=0.005, head_length=0.01, 
            fc='blue', ec='blue', label='$I_{R2}$ (0.143A, 15.7°)', length_includes_head=True)

# 2. I_C1 (Desde la punta de I_R2 para mostrar la suma vectorial)
ax.arrow(dx_r2, dy_r2, dx_c1, dy_c1, head_width=0.005, head_length=0.01, 
            fc='green', ec='green', label='$I_{C1}$ (0.140A, 105.7°)', length_includes_head=True)

# 3. I_Total (Resultante desde el origen)
ax.arrow(0, 0, dx_total, dy_total, head_width=0.005, head_length=0.01, 
            fc='red', ec='red', linestyle='--', linewidth=2, 
            label='$I_{Total}$ (0.2A, 60°)', length_includes_head=True)

# Ajustes visuales
limit = 0.25
ax.set_xlim(-0.05, limit)
ax.set_ylim(-0.05, limit)
ax.set_aspect('equal')
ax.grid(True, linestyle=':', alpha=0.6)
ax.axhline(0, color='black', linewidth=1)
ax.axvline(0, color='black', linewidth=1)

# Etiquetas
ax.set_xlabel('Real (A)')
ax.set_ylabel('Imaginario (jA)')
ax.set_title('Diagrama Fasorial de Corrientes en el Nodo A')
ax.legend(loc='upper left')

# Anotación del ángulo recto
ax.text(0.12, 0.08, '90° de desfasaje\nentre R y C', fontsize=9, color='darkgreen')

plt.show()