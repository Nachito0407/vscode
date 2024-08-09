program test
    implicit none
    real a,b,c
    !----------------------------------------------------
    print*,'ingrese los valores de a y b'
    read(*,*) a,b
    c=((a+b)**2-2.0*a*b-b**2)/a**2
    write(*,*) c
    print*,c
    !----------------------------------------------------
end program test
