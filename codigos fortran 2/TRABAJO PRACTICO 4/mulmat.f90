program mulmat
    implicit none
    integer, parameter :: n = 5
    real, dimension(n,n) :: A, B, C

    call leer_matriz_A(A, n)
    call leer_matriz_B(B, n)
    
    call mul_mat(A, B, C, n)
    
    call imprimir_matriz(C, n)


end program mulmat

subroutine mul_mat(A, B, C, n)
    implicit none
    integer n 
    real, dimension(n,n) :: A, B, C
    integer :: i, j, k
    C = 0.0
    do i = 1, n
        do j = 1, n
            do k = 1, n
                C(i,j) = C(i,j) + A(i,k) * B(k,j)
            end do
        end do
    end do
end subroutine mul_mat

subroutine leer_matriz_A(A, n)
    implicit none
    integer n
    real, dimension(n,n) :: A
    integer i
    
    open(10, file='datos_mulmatA.txt')
    do i = 1, n
        read(10,*) A(i,:)
    end do
    close(10)
end subroutine leer_matriz_A

subroutine leer_matriz_B(B, n)
    implicit none
    integer n
    real, dimension(n,n) :: B
    integer i
    
    open(11, file='datos_mulmatB.txt')
    do i = 1, n
        read(11,*) B(i,:)  
    end do
    close(11)
end subroutine leer_matriz_B

subroutine imprimir_matriz(C, n)
    implicit none
    integer n
    real, dimension(n,n) :: C
    integer i
    print *, 'La matriz resultante es:'
    do i = 1, n
        write(*,*) C(i,:)
    end do
end subroutine imprimir_matriz