program name
    implicit none
    integer aux,i,n,j
    integer v(4)
    logical access

    v=(/7,2,3,5/)
    n=4
    do i =1,n-1
        access = .false.
        do j =1,n-i
            print *, 'Valor de i =', i, ', Valor de j =', j
            
        if (v(j) > v(j +1))then
        access = .true.
        aux = v(j)
        v(j) = v(j +1)
        v(j +1) = aux
        end if
        end do
        if (.not. access) exit
        end do
        print *, 'Arreglo ordenado:', v
        
end program name