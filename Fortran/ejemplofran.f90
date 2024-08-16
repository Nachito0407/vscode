program logaritmo
    implicit none
    integer::j,n
    real::x,i,suma,f,a,b
    suma=0
    i=0
    read(*,*)x,n
    do j=0,n,1
        a=1.0/(2.0i+1.0)
        b=((x-1.0)/(x+1.0))**(2.0i+1.0)
        f=2.0ab
        suma=suma+f
        i=i+1
    end do
    print,suma
    print,log(2.0)
    end program logaritmo