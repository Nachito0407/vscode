program ajuste_lineal
    implicit none
    integer , parameter :: n=2
    integer , parameter :: t=8
    integer i , j 
    real(8) suma_x , suma_x2 , suma_f , suma_f_x , x(t) , f(t) , a(t,t) , b(t) , p(n)

    print*, "ingrese los valores de la tabla"
    print*, "ingrese los valores de x"
    read*, x
    print*, "ingrese los valores de la funcion F(x)"
    read*, f

    suma_x=0
    suma_x2=0
    suma_f=0
    suma_f_x=0

    do i=1,t
        suma_x = suma_x + x(i)
        suma_x2 = suma_x2 + x(i)**2
        suma_F = suma_F + F(i)
        suma_f_x= suma_f_x+ f(i)*x(i)
    end do
    print*, "suma de x = ", suma_x
    print*, "suma de x^2 = ", suma_x2
    print*, "suma de F(x) = ", suma_F
    print*, "suma de f*x =", suma_f_x

    a(1,1)=suma_x2
    a(1,2)=suma_x
    a(2,1)=suma_x
    a(2,2)=t
    b(1)=suma_f_x
    b(2)=suma_f

    do i=1,n
        write(*,*)(a(i,j),j=1,n)
    end do

    call eliminacion_gauss(a, n, b)
    call retrosustitucion(a, n, b, p)

    write(*,*)"a =",p(1)
    write(*,*)"b =",p(2)

end program ajuste_lineal


subroutine eliminacion_gauss(a ,n, b) 
    implicit none
    integer i , j , k , n
    real(8) :: a(n,n) , b(n)
    real(8) m 
    do i=1 , n-1
        do j=i+1 , n
            m= a(j,i)/a(i,i)
            a(j,i)= 0.0d0
            b(j)=b(j)-m*b(i)
            do k = i+1 , n
                a(j,k)= a(j,k) - m*a(i,k)
            end do
        end do
    end do
    end subroutine eliminacion_gauss

subroutine retrosustitucion(a,n,b,x)
    implicit none
    integer :: n, i, j
    real(8) :: a(n,n), b(n), x(n)
    real(8) :: suma
    
    x(n) = b(n)/a(n,n)
    
    do i = n-1, 1, -1
        suma = 0.0d0
        do j = i+1, n
            suma = suma + a(i,j)*x(j)
        end do
        x(i) = (b(i) - suma)/a(i,i)
    end do
end subroutine retrosustitucion