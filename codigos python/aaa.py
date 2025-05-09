import numpy as np
import matplotlib.pyplot as plt
import control as ctl

# Defino H(s)=3 s^2/((s+1.4)^2 (s+3))
num = [3, 0, 0]
den = np.polymul([1, 2*1.4, 1.4**2], [1, 3])
H = ctl.TransferFunction(num, den)

# Ploteo Bode
mag, phase, omega = ctl.bode(H,
                            omega=np.logspace(-1, 2, 500),
                            dB=True, plot=False)  # Cambiado Plot a plot

plt.figure()
plt.semilogx(omega, 20*np.log10(mag))
plt.axvline(1.4, color='gray', ls='--')
plt.axvline(3.0, color='gray', ls='--')
plt.title('Diagrama de Bode (magnitud) – parte c)')
plt.xlabel('ω (rad/s)')
plt.ylabel('|H(jω)| (dB)')
plt.grid(which='both', ls=':')
plt.show()