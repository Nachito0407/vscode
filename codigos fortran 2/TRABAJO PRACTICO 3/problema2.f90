program tres_n_mas_uno
    implicit none
    integer(8) n
    print *, "Ingrese un numero entero positivo: "
    read *, n

    do while (n/=1)
        if (n == 13) then
            print *, "Llegaste a 13, mala suerte"
            stop
        end if
    if (mod(n,2) == 0) then
        n = n/2
    else
        n= 3*n + 1
        end if
        print *, n
    end do
    print *, "Llegaste al 1"

end program tres_n_mas_uno