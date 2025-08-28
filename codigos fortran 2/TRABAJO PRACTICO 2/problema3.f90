program factorial
implicit none
    integer i , fact, n
    print *, "Ingrese un numero"
    read *, n
    fact = 1
    do i = 2, n
        fact = fact * i
    end do
    print *, "El factorial es ", fact
    
end program factorial