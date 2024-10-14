import matplotlib.pyplot as plt
import numpy as np

# Define the piecewise function psi(t)
def psi_t(t):
    return np.where((-np.pi <= t) & (t <= -np.pi/2), 0, np.sin(t))

# Time values
t_vals = np.linspace(-np.pi, np.pi, 400)

# Evaluate the piecewise function
psi_vals = psi_t(t_vals)

# Plot the piecewise function
plt.figure(figsize=(8, 4))
plt.plot(t_vals, psi_vals, label=r'$\psi(t)$', color='blue')
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.title('Piecewise Function $\psi(t)$')
plt.xlabel('t')
plt.ylabel(r'$\psi(t)$')
plt.grid(True)
plt.legend()
plt.show()
