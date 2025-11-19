import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

beta = 1.0

def f(t, T):
    return beta - T**4

t = np.linspace(0, 5, 500)

T0_vals = [-1, -0.5, 0, 0.5, 0.9]  # all within |T0| ≤ β^(1/4)=1

plt.figure(figsize=(6,4))

for T0 in T0_vals:
    sol = solve_ivp(f, [0,5], [T0], t_eval=t)
    plt.plot(sol.t, sol.y[0])

plt.axhline(beta**0.25, linestyle='--')
plt.axhline(-beta**0.25, linestyle='--')
plt.xlabel("t")
plt.ylabel("T(t)")
plt.title("Soluciones del ODE  T' = β - T⁴   (β=1)")
plt.grid(True)

plt.show()