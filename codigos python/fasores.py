import matplotlib.pyplot as plt
import numpy as np

# Datos calculados en el paso anterior
# Formato: (Magnitud, Ángulo en grados)
v_r1 = (54, 60)
v_l1 = (12.57, 150)
v_a = (4.73, 15.73)

# Función para convertir polar a cartesiano
def pol2cart(mag, ang_deg):
    ang_rad = np.deg2rad(ang_deg)
    return mag * np.cos(ang_rad), mag * np.sin(ang_rad)

# Calcular componentes (dx, dy)
dx_r1, dy_r1 = pol2cart(*v_r1)
dx_l1, dy_l1 = pol2cart(*v_l1)
dx_a, dy_a = pol2cart(*v_a)

# Calcular la resultante (V_total)
dx_total = dx_r1 + dx_l1 + dx_a
dy_total = dy_r1 + dy_l1 + dy_a

# Configuración del gráfico
fig, ax = plt.subplots(figsize=(8, 8))

# Dibujar vectores usando 'quiver' simulado con arrow para mejor control "cabeza-cola"
# 1. V_R1 (Desde el origen)
ax.arrow(0, 0, dx_r1, dy_r1, head_width=2, head_length=3, fc='blue', ec='blue', label='$V_{R1}$ (54V, 60°)', length_includes_head=True)

# 2. V_L1 (Desde la punta de V_R1)
ax.arrow(dx_r1, dy_r1, dx_l1, dy_l1, head_width=2, head_length=3, fc='green', ec='green', label='$V_{L1}$ (12.57V, 150°)', length_includes_head=True)

# 3. V_A (Desde la punta de V_L1)
ax.arrow(dx_r1 + dx_l1, dy_r1 + dy_l1, dx_a, dy_a, head_width=2, head_length=3, fc='orange', ec='orange', label='$V_{A}$ (4.73V, 15.7°)', length_includes_head=True)

# 4. V_Total (Resultante desde el origen)
ax.arrow(0, 0, dx_total, dy_total, head_width=2, head_length=3, fc='red', ec='red', linestyle='--', linewidth=2, label='$V_{Fuente}$ (Resultante)', length_includes_head=True)

# Ajustes visuales
ax.set_xlim(-10, 70)
ax.set_ylim(0, 80)
ax.set_aspect('equal')
ax.grid(True, linestyle=':', alpha=0.6)
ax.axhline(0, color='black', linewidth=1)
ax.axvline(0, color='black', linewidth=1)
ax.set_xlabel('Real (V)')
ax.set_ylabel('Imaginario (jV)')
ax.set_title('Diagrama Fasorial de Tensiones (Suma Vectorial)')
ax.legend(loc='upper left')

plt.show()