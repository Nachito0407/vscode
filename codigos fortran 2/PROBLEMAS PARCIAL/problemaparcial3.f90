program metodo_burbuja_mejorado
    implicit none
    integer, parameter :: n = 6
    integer vector(n) ,i,j, aux , iteraciones
    logical acceso
    print *, "Ingrese 6 numeros enteros:"

    do i = 1, n
        read *, vector(i)
    end do

    iteraciones=0
    print *, "Vector inicial:", vector

    do i=1 , n
        acceso=.false.
        do j=1 , n-i
            if (vector(j)<vector(j+1)) then
                aux=vector(j)
                vector(j)=vector(j+1)
                vector(j+1)=aux
                acceso=.true.
                write(*,*) vector
            end if
            
        end do
        if (acceso) iteraciones = iteraciones + 1 
        if (.not. acceso) exit
    end do

    print *, "Cantidad de recorridas con intercambio:", iteraciones
    write(*,*) "Vector ordenado:", vector


end program metodo_burbuja_mejorado