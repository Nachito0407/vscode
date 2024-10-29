import numpy as np
from scipy.integrate import quad

# Definimos la parametrización de la curva y la función a integrar
def integrand(t):
    # Parámetros de la línea recta entre 1 + i y 9 + 3i
    z = 1 + 1j + t * (8 + 2j)
    dz_dt = 8 + 2j

    # Función a integrar: e^z * sin(e^z) * dz/dt
    func_value = np.exp(z) * np.sin(np.exp(z)) * dz_dt
    return func_value.real, func_value.imag

# Calculamos la parte real e imaginaria por separado
real_integral, _ = quad(lambda t: integrand(t)[0], 0, 1)
imag_integral, _ = quad(lambda t: integrand(t)[1], 0, 1)

# Resultado complejo de la integral
integral_result = real_integral + 1j * imag_integral
integral_result
