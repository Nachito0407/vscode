program ordena_y_desordena_aleatorio
    implicit none
    integer, parameter :: n = 10
    integer  i, j, temp
    integer  numeros(n)
    real  rand_val

    ! Ingresar los números manualmente
    print *, "Ingrese ", n , " numeros:"
    do i = 1, n
        read(*, *) numeros(i)
    end do

    ! Imprimir los números originales
    print *, "Numeros originales:"
    print *, numeros

    ! Ordenar los números usando ordenamiento burbuja
    do i = 1, n-1
        do j = i+1, n
            if (numeros(i) > numeros(j)) then
                temp = numeros(i)
                numeros(i) = numeros(j)
                numeros(j) = temp
            end if
        end do
    end do

    ! Imprimir los números ordenados
    print *, "Numeros ordenados:"
    print *, numeros

    ! Desordenar los números aleatoriamente
    do i = 1, n
        call random_number(rand_val)  ! Generar un número aleatorio entre 0 y 1
        j = int(rand_val * n) + 1     ! Convertir a un índice en el rango 1 a n
        if (i /= j) then              ! Evitar intercambio consigo mismo
            temp = numeros(i)
            numeros(i) = numeros(j)
            numeros(j) = temp
        end if
    end do

    ! Imprimir los números desordenados
    print *, "Numeros desordenados aleatoriamente:"
    print *, numeros

end program ordena_y_desordena_aleatorio
