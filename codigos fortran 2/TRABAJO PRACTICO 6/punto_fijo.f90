program punto_fijo_1
implicit none
real(8)  x0, tol
integer  max_iter

tol = 1.0d-6
max_iter = 100
x0 = 0.5d0   

    print *, "Iteracion de punto fijo para g(x) = 4/(x+1)"
call punto_fijo(x0, tol, max_iter)

contains


real(8) function g(x)
    real(8) x
    g = 4.0d0 / (x + 1.0d0)
end function g


subroutine punto_fijo(x0, tol, max_iter)
    implicit none
    real(8) x0, tol
    integer max_iter
    real(8)  x, x_next
    integer  i

    x = x0
    print *, "x0 = ", x

    do i = 1, max_iter
        x_next = g(x)
        print*, i, x_next
        if (abs(x_next - x) < tol) then
            print *, " No converge en: ", i, " iteraciones"
            print *, "Raiz aproximada = ", x_next
            return
        end if
        x = x_next
    end do

    print *, "No converge en: ", max_iter, " iteraciones"
    end subroutine punto_fijo

end program punto_fijo_1