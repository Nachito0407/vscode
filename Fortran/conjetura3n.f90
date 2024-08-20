program conjetura3n1
    implicit none
    integer n
    print*,'ingrese un entero n'
    read*,n
    do while(n/=1)
        if ( n==13 ) then
            print*,'llegaste a 13 mala suerte'
            stop
        end if
        if ( mod(n,2)==0 ) then
            n=n/2
        else
            n=3*n+1
        end if
        print*,n
    end do
    print*, 'llegaste al 1'
end program conjetura3n1