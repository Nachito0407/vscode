Program Escritura0rd
    implicit none
    integer, parameter :: n=3, m=4
    integer i, j
    real*8 a(n,m), v(m)

    v = (/1,2,3,4/)
    do i=1,n
        a(i,:) = v
    end do

    write(*,*) "a = "
    do i=1,n
        write(*,'(4F8.2)') (a(i,j), j=1,m)
    end do

End Program Escritura0rd
