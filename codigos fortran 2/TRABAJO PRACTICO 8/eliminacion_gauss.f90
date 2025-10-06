program eliminacion_gaussiana
    implicit none
    integer , parameter :: n=4
    real(8) , dimension(n,n) :: a
    real(8) , dimension(n) :: b

    call leer_matriz_A(a,n)

    call leer_vector_b(b,n)

    call eliminacion_gauss(a,n,b)

    call imprimir_matriz(a,n)

end program eliminacion_gaussiana

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


subroutine leer_matriz_A(a, n)
    implicit none
    integer n
    real(8), dimension(n,n) :: a
    integer i
    
    open(10, file='datos_matA.txt')
    do i = 1, n
        read(10,*) A(i,:)
    end do
    close(10)
end subroutine leer_matriz_A

subroutine imprimir_matriz(a,n)
implicit none
    integer :: n, i
    real(8), dimension(n,n) :: A
    
    open(20, file='matriz_resultado.txt')
    do i = 1, n
        write(20,*) A(i,:)
    end do
    close(20)
end subroutine imprimir_matriz

subroutine leer_vector_b(b, n)
    implicit none
    integer :: n, i
    real(8), dimension(n) :: b
    
    open(11, file='datos_vecb.txt')
    do i = 1, n
        read(11,*) b(i)
    end do
    close(11)
end subroutine leer_vector_b
