program polinomio_de_lagrange
    implicit none
    integer, parameter :: MAX_PUNTOS = 100
    real :: x(MAX_PUNTOS), y(MAX_PUNTOS)
    integer n , i
    real x_eval , resultado , l_x

    integer

    write(*,*) 'Ingrese el valor de x:'
    read(*,*) x_eval
end program polinomio_de_lagrange

function l_x(x_eval , x , n , i )
implicit none
integer, parameter :: MAX_PUNTOS = 100
real, dimension(MAX_PUNTOS) :: x
integer n, i , j
real x_eval , li

li= 1.d0


do j=1 , n
        if(j/=i) then
            li= li * (x-x(j))/(x(i)-x(j))
    end if
end do
    end function l_x

subroutine datos()
implicit none


    end subroutine