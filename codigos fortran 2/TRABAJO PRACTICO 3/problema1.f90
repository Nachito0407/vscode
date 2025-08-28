program raices_sin_complejos
    implicit none
    real(8) a, c, b , raiz1, raiz2, discriminante, parte_real, parte_imaginaria

    print *, 'ingrese los valores de a , b y c'

    read *, a, b ,c

    discriminante = b**2 - 4.0d0*a*c
    if (discriminante < 0.0d0) then
        print *, 'las raices son complejas'
        parte_real = -b / (2.0d0*a)
        parte_imaginaria = sqrt(-discriminante) / (2.0d0*a)
        print *, 'raiz 1 = ', parte_real, ' + ','i',parte_imaginaria
        print *, 'raiz 2 = ', parte_real, ' - ','i',parte_imaginaria
    else
        raiz1 = (-b + sqrt(discriminante)) / (2.0d0*a)
        raiz2 = (-b - sqrt(discriminante)) / (2.0d0*a)
        print *, 'raiz 1 = ', raiz1
        print *, 'raiz 2 = ', raiz2
    end if

end program raices_sin_complejos