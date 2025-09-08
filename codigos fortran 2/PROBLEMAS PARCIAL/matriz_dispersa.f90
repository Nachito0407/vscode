program matriz_dispersa
    implicit none
    integer, parameter :: nmax = 10, mmax = 10
    integer  n, m
    integer  i, j, k, nnz
    real  A(nmax,mmax)
    real  AA(nmax*mmax)
    integer  JR(nmax*mmax), JC(nmax*mmax)

    print *, "Ingrese el numero de filas con un maximo de 10:"
    read *, n
    print *, "Ingrese el numero de columnas con un maximo de 10:"
    read *, m

    do i = 1, n
        do j = 1, m
            A(i,j) = 0.0
        end do
    end do

    print *, "Ingrese la matriz A (", n, "x", m, "):"
    do i = 1, n
        do j = 1, m
            read *, A(i,j)
        end do
    end do

    nnz = 0
    do i = 1, n
        do j = 1, m
            if (A(i,j) /= 0.0) then
                nnz = nnz + 1
                AA(nnz) = A(i,j)
                JR(nnz) = i
                JC(nnz) = j
            end if
        end do
    end do

    print *, "cantidad de elementos no nulos: ", nnz
    print *, "AA = ", (AA(k), k=1,nnz)
    print *, "JR = ", (JR(k), k=1,nnz)
    print *, "JC = ", (JC(k), k=1,nnz)

end program matriz_dispersa