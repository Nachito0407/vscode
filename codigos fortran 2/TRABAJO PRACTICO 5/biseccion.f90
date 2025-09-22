program biseccion
    implicit none
    real(8), external :: fun, calcular_error
    real(8) :: a, b, raiz, tolerancia, valor_error
    integer :: max_iter, iter

    ! Inicialización de variables
    tolerancia = 1.0D-6
    max_iter = 100
    valor_error = tolerancia + 1.0D0

    print*, 'Ingrese el valor de a:'
    read*, a
    print*, 'Ingrese el valor de b:'
    read*, b

    call bisec(a, b, tolerancia, max_iter, raiz, valor_error, iter)

    print*, "Raiz encontrada:", raiz
    print*, "Error:", valor_error
    print*, "Iteraciones:", iter

end program biseccion

function fun(x)
    implicit none
    real(8) :: fun, x
    fun = x**2 - 1.0d0
end function

function calcular_error(valor1, valor2)
    implicit none
    real(8) :: calcular_error, valor1, valor2
    calcular_error = abs(valor1 - valor2)
end function

subroutine bisec(a, b, tolerancia, max_iter, raiz, error, iter)
    implicit none
    real(8) :: raiz, a, b 
    real(8) :: tolerancia, error, fb, fa, c, fc
    integer :: max_iter, iter
    real(8), external :: fun, calcular_error

    fa = fun(a)
    fb = fun(b)

    if (fa * fb > 0.0d0) then
        print*, "Error: No hay cambio de signo en el intervalo"
        stop
    end if

    iter = 0
    error = calcular_error(b, a)

    do while (error > tolerancia .and. iter < max_iter)
        c = (a + b) / 2.0d0
        fc = fun(c)

        if (fc * fa < 0) then
            b = c
            fb = fc
        else
            a = c
            fa = fc
        end if

        error = calcular_error(b, a)
        iter = iter + 1
        raiz = c
    end do
end subroutine