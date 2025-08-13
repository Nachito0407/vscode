program raices_segundo_orden
    implicit none
    complex a, b, c, discriminante, raiz1, raiz2
    complex sqrt_discriminante

    print *, 'Ingrese el coeficiente a:'
    read *, a
    print *, 'Ingrese el coeficiente b:'
    read *, b
    print *, 'Ingrese el coeficiente c:'
    read *, c

    discriminante = b**2 - 4.0*a*c
    sqrt_discriminante = sqrt(discriminante)
    raiz1 = (-b + sqrt_discriminante) / (2.0*a)
    raiz2 = (-b - sqrt_discriminante) / (2.0*a)
    print *, 'Las raices son:'
    print *, 'Raiz 1: ', raiz1
    print *, 'Raiz 2: ', raiz2
    
end program raices_segundo_orden
