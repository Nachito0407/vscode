import numpy as np
import matplotlib.pyplot as plt

def roots_for_K(K):
    coef = [1.0, 3.6, K, 0.2*K]
    return np.roots(coef)

# --- Barrido de K ---
K_values = np.concatenate((np.linspace(0,10,301), np.linspace(10.1,500,400)))
roots_list = [roots_for_K(K) for K in K_values]

plt.figure(figsize=(9,6))

# Trayectorias de raíces
for rset in roots_list:
    plt.plot([r.real for r in rset],
                [r.imag for r in rset], alpha=0.02)

# Nube de puntos
plt.plot([r.real for rset in roots_list for r in rset],
            [r.imag for rset in roots_list for r in rset], '.', markersize=2)

# Polos y ceros en lazo abierto
poles = [0.0, 0.0, -3.6]
zeros = [-0.2]
plt.scatter(poles, [0,0,0], marker='x', s=100, label="Polos")
plt.scatter(zeros, [0], marker='o', s=100, label="Ceros")

# Asintotas
n, m = 3, 1
centroid = (sum(poles) - sum(zeros)) / (n-m)
angles = [(2*k + 1)*180/(n-m) for k in range(n-m)]
length = 10  # Longitud de las asíntotas

for angle in angles:
    dx = length * np.cos(np.radians(angle))
    dy = length * np.sin(np.radians(angle))
    plt.plot([centroid, centroid + dx], [0, dy], 
                '--', color='orange', linewidth=0.8)

plt.title("Lugar de raíces: G(s)=K(s+0.2)/(s^2(s+3.6)), H(s)=1")
plt.xlabel("Re(s)")
plt.ylabel("Im(s)")
plt.grid(True)
plt.legend()
plt.xlim(-8, 2)
plt.ylim(-7, 7)

plt.show()