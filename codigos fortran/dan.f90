program ajustes_d_curvas
    implicit none
    integer, parameter:: n=2 !matriz 2x2
    integer, parameter:: h=8 !cantidad de datos en la tabla
    integer i,j,k
    real x(h), f(h), suma_x, suma_x2, suma_f, a(h,h), b(h), suma_f_por_x, m(n,n), dr,p(n)

    print*, "ingresar valores de tabla"
    print*, "ingresar los valores de x"
    read*, x
    print*, "ingresar los valores de la funcion F(x)"
    read*, f


    !hacer suma de los x y f(x)
    suma_x=0
    suma_x2=0
    suma_f=0
    suma_f_por_x=0
    do i=1,h
        suma_x = suma_x + x(i)
        suma_x2 = suma_x2 + x(i)**2
        suma_F = suma_F + F(i)
        suma_F_por_x= suma_F_por_x+ f(i)*x(i)
    end do
    print*, "suma de x = ", suma_x
    print*, "suma de x^2 = ", suma_x2
    print*, "suma de F(x) = ", suma_F
    print*, "suma de f*x =", suma_F_por_x

    !se defeinen los coeficientes de la matriz
    a(1,1)=suma_x2
    a(1,2)=suma_x
    a(2,1)=suma_x
    a(2,2)=n
    b(1)=suma_F_por_x
    b(2)=suma_F


    !resolver sistema de ecuaciones------------------------------------------------------------------------------

    !reduce matriz
    do i=1,n-1
        do j=i+1,n
            m(j,i)=a(j,i)/a(i,i)
            a(j,i)=0
            b(j)=b(j)-(m(j,i)*b(i))
            do k=i+1,n
                a(j,k)=a(j,k)-(m(j,i)*a(i,k))
            end do
        end do
    end do

    !hace la retro sustitucion 
    do i=n,1,-1
        dr=0
        do j=i+1,n
            dr=dr+a(i,j)*p(j)
        end do
        p(i)=(b(i)-dr)/a(i,i)
    end do

    write(*,*)"a =",p(1)
    write(*,*)"b =",p(2)
end program
    