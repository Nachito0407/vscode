program multiplicacion_matrices
    implicit none
    integer, parameter :: MAX = 100
    integer  filasA, colsA, filasB, colsB
    real :: A(MAX,MAX), B(MAX,MAX), C(MAX,MAX)

    call leer_matriz('A', A, filasA, colsA)
    call leer_matriz('B', B, filasB, colsB)
    call multiplicar_matrices(A, B, C, filasA, colsA, filasB, colsB)
    call imprimir_matriz(C, filasA, colsB)

end program multiplicacion_matrices


subroutine leer_matriz(nombre, M, filas, cols)

    implicit none
    character(len=*), intent(in) :: nombre
    integer, intent(out) :: filas, cols
    real, intent(out) :: M(100,100)
    integer :: i, j

    print *, 'Ingrese el numero de filas de la matriz ', nombre, ':'
    read *, filas
    print *, 'Ingrese el numero de columnas de la matriz ', nombre, ':'
    read *, cols

    print *, 'Ingrese los elementos de la matriz ', nombre, ':'
    do i = 1, filas
        do j = 1, cols
            read *, M(i,j)
        end do
    end do
end subroutine leer_matriz


subroutine multiplicar_matrices(A, B, C, fA, cA, fB, cB)
    implicit none
    real :: A(100,100), B(100,100)
    real :: C(100,100)
    integer  fA, cA, fB, cB
    integer  i, j, k

    if (cA /= fB) then
        print *, 'No se pueden multiplicar las matrices: columnas de A no coinciden con filas de B.'
        stop
    end if

    C = 0.0

    do i = 1, fA
        do j = 1, cB
            do k = 1, cA
                C(i,j) = C(i,j) + A(i,k)*B(k,j)
            end do
        end do
    end do
end subroutine multiplicar_matrices


subroutine imprimir_matriz(M, filas, cols)
    implicit none
    real :: M(100,100)
    integer  filas, cols
    integer  i, j

    print *, 'Resultado de la multiplicacion:'
    do i = 1, filas
        do j = 1, cols
            write(*,'(F10.3)') M(i,j)   
        end do
        print *, 'salto de linea'
    end do
end subroutine imprimir_matriz
