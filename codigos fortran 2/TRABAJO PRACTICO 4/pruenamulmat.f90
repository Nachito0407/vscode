program mulmat
    implicit none
    integer :: n
    real, allocatable :: A(:,:), B(:,:), C(:,:)
    character(len=100) :: archivoA, archivoB

    print *, 'Ingrese el tamaño de la matriz n:'
    read *, n

    allocate(A(n,n), B(n,n), C(n,n))

    print *, 'Ingrese el nombre del archivo de la matriz A:'
    read *, archivoA
    print *, 'Ingrese el nombre del archivo de la matriz B:'
    read *, archivoB

    call leer_matriz(archivoA, A, n)
    call leer_matriz(archivoB, B, n)
    call mul_mat(A, B, C, n)

    print *, 'La matriz resultado C es:'
    call imprimir_matriz(C, n)

    deallocate(A, B, C)
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

subroutine leer_matriz(nombre_archivo, M, n)
    implicit none
    character(len=*), intent(in) :: nombre_archivo
    integer, intent(in) :: n
    real, dimension(n,n), intent(out) :: M
    integer :: i, j
    open(unit=10, file=nombre_archivo, status='old')
    do i = 1, n
        read(10, *) (M(i,j), j=1,n)
    end do
    close(10)
end subroutine leer_matriz

subroutine imprimir_matriz(M, n)
    implicit none
    integer, intent(in) :: n
    real, dimension(n,n), intent(in) :: M
    integer :: i, j
    do i = 1, n
        write(*,*) (M(i,j), j=1,n)
    end do
end subroutine imprimir_matriz