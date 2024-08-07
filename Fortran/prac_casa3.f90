program raices_complejas
    implicit none
    complex :: a, b, c, discriminante, raiz1, raiz2
    complex, parameter :: i = (0.0, 1.0)
    complex :: sqrt_discriminante

    ! Leer los coeficientes a, b, c
    print *, 'Ingrese el coeficiente a (parte real, parte imaginaria): '
    read *, a
    print *, 'Ingrese el coeficiente b (parte real, parte imaginaria): '
    read *, b
    print *, 'Ingrese el coeficiente c (parte real, parte imaginaria): '
    read *, c

    ! Calcular el discriminante
    discriminante = b**2 - 4.0*a*c

    ! Calcular las raíces
    sqrt_discriminante = sqrt(discriminante)
    raiz1 = (-b + sqrt_discriminante) / (2.0*a)
    raiz2 = (-b - sqrt_discriminante) / (2.0*a)

    ! Imprimir las raíces
    print *, 'Las raíces del polinomio son:'
    print *, 'Raíz 1: ', raiz1
    print *, 'Raíz 2: ', raiz2

end program raices_complejas