program funcion_por_partes
    implicit none
    real x,f

    write(*,*) "ingrese x"
    read(*,*) x

    ! Verifica si el valor de x excede el limite
    if (abs(x) >= 100) then
        print *, 'El valor de x supera los límites permitidos (|x| >= 100).'
        stop
    endif

    if ( x<-1.d0 ) then
            f= x**2+1
        elseif(x<0.0)then
            f=2.0
        elseif(x<5.0)then
            f=(24*x/5)+2
        else
            f=x**2 + 1
    end if

    print *, 'El valor de f(x) es:', f

end program funcion_por_partes  