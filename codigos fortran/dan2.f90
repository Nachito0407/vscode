program ajustes_d_curvas
    implicit none
    integer, parameter :: n=2 !matriz 2x2
    integer, parameter :: h=8 !cantidad de datos en la tabla
    integer :: i, j, k
    real :: x(h), f(h), suma_x, suma_x2, suma_f, a(n,n), b(n), suma_f_por_x, m(n,n), dr, p(n)

    print*, "ingresar valores de tabla"
    print*, "ingresar los valores de x"
    do i = 1, h
        read*, x(i)
    end do
    print*, "ingresar los valores de la funcion F(x)"
    do i = 1, h
        read*, f(i)
    end do

    ! Inicialización de sumas
    suma_x = 0.0
    suma_x2 = 0.0
    suma_f = 0.0
    suma_f_por_x = 0.0

    ! Calcular sumas de x y f(x)
    do i = 1, h
        suma_x = suma_x + x(i)
        suma_x2 = suma_x2 + x(i)**2
        suma_f = suma_f + f(i)
        suma_f_por_x = suma_f_por_x + f(i) * x(i)
    end do

    print*, "suma de x = ", suma_x
    print*, "suma de x^2 = ", suma_x2
    print*, "suma de F(x) = ", suma_f
    print*, "suma de f*x =", suma_f_por_x

    ! Definir coeficientes de la matriz
    a(1,1) = suma_x2
    a(1,2) = suma_x
    a(2,1) = suma_x
    a(2,2) = real(n)  ! Usar real() para evitar errores de tipo
    b(1) = suma_f_por_x
    b(2) = suma_f

    ! Resolver sistema de ecuaciones mediante eliminación gaussiana

    ! Reducir la matriz
    do i = 1, n-1
        do j = i+1, n
            m(j,i) = a(j,i) / a(i,i)
            a(j,i) = 0.0
            b(j) = b(j) - (m(j,i) * b(i))
            do k = i+1, n
                a(j,k) = a(j,k) - (m(j,i) * a(i,k))
            end do
        end do
    end do

    ! Retro sustitución
    do i = n, 1, -1
        dr = 0.0
        do j = i+1, n
            dr = dr + a(i,j) * p(j)
        end do
        p(i) = (b(i) - dr) / a(i,i)
    end do

    write(*,*)"a =", p(1)
    write(*,*)"b =", p(2)
end program
