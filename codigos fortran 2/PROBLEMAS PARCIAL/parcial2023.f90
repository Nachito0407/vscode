program problemas_parcial
    implicit none
    integer, parameter :: n = 5
    integer i
    real :: a(n), b(n) ,d(n) , c(3)
    real :: m(n,n)
    real :: productopunto
    real producto_punto

    print *, "ingrese los elementos 5 elementos del vector a:"
    read(*,*) a

    print *, "ingrese los elementos 5 elementos del vector b:"
    read(*,*) b

    print*, "ingtrese los elementos de la matriz 5x5 fila por fila:"
    do i = 1, n
        read(*,*) m(i,:)
    end do

    productopunto = producto_punto(a,b,n)
    print *, "El producto punto de los vectores a y b es: ", productopunto

    if(n==3) then
        call    producto_vectorial (a,b,c)
        print *, "El producto vectorial de los vectores a y b es: ", c
    else
        print*, "el producto vectorial no esta definido para esa dimension"
    end if

    call producto_matriz_vector(m,a,d,n)
    print *, "el producto de la matriz m por el vector a es: ", d

    call producto_matriz_vector(m,b,d,n)
    print *, "el producto de la matriz m por el vector b es: ", d

end program problemas_parcial

real function producto_punto(x,y,n)
    implicit none
    integer  n
    real :: x(n), y(n)
    integer i
    producto_punto = 0.0
    do i = 1 , n
        producto_punto = producto_punto + x(i) * y(i)
    end do
end function producto_punto

subroutine producto_vectorial(x,y,z)
    implicit none
    real x(3) , y(3) , z(3)
    z(1) = x(2)*y(3) - x(3)*y(2)
    z(2) = x(3)*y(1) - x(1)*y(3)
    z(3) = x(1)*y(2) - x(2)*y(1)
end subroutine producto_vectorial

subroutine producto_matriz_vector(m,u,v,n)
    implicit none
    integer n , i , j
    real m(n,n) , v(n) , u(n)

    v=0.0
    do i=1 ,  n
        do j=1 , n
            v(i)= v(i) + m(i,j)*u(j)
        end do
    end do
end subroutine producto_matriz_vector