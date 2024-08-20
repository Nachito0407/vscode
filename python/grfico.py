import numpy as np
import matplotlib.pyplot as plt

# Given values
R = 5  # Ohms
L = 0.004  # Henrys

# Define time intervals
t1 = np.linspace(0, 2e-3, 100)
t2 = np.linspace(2e-3, 4e-3, 100)
t3 = np.linspace(4e-3, 6e-3, 100)
t4 = np.linspace(6e-3, 8e-3, 100)
t5 = np.linspace(8e-3, 10e-3, 100)

# Define current i(t) for each interval
i1 = 2500 * t1      # Linear increase from 0 to 5 A
i2 = 5 * np.ones_like(t2)  # Constant at 5 A
i3 = -5000 * (t3 - 4e-3) + 5  # Linear decrease from 5 A to -5 A
i4 = -5 * np.ones_like(t4)  # Constant at -5 A
i5 = 2500 * (t5 - 8e-3) - 5  # Linear increase from -5 A to 0 A

# Concatenate the time and current arrays
t = np.concatenate([t1, t2, t3, t4, t5])
i = np.concatenate([i1, i2, i3, i4, i5])

# Calculate v_R(t) = R * i(t)
v_R = R * i

# Calculate the derivative of i(t) to get di/dt
di_dt = np.gradient(i, t)

# Calculate v_L(t) = L * di(t)/dt
v_L = L * di_dt

# Plot the results
plt.figure(figsize=(14, 6))

plt.subplot(2, 1, 1)
plt.plot(t, v_R, label=r'$v_R(t)$')
plt.title('Voltage across the Resistor $v_R(t)$')
plt.xlabel('Time [s]')
plt.ylabel('Voltage [V]')
plt.grid(True)
plt.legend()

plt.subplot(2, 1, 2)
plt.plot(t, v_L, label=r'$v_L(t)$', color='red')
plt.title('Voltage across the Inductor $v_L(t)$')
plt.xlabel('Time [s]')
plt.ylabel('Voltage [V]')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()