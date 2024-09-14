program bisecccionv2
    implicit none
    real f,fpm,a,b,tolerancia,pm
    integer i , imax

    print*,'ingrese el interavalo inferior a'
    read*, a
    print*,'ingrese el interavalo inferior b'
    read*, b
    
    imax= 50
    tolerancia=0.000000001

    if ( f(a)*f(b)>0 ) then
        write(*,*) 'no hay raiz en el intervalo'
        stop
    end if

    i=0

    do
        i=i+1
        pm= fpm(a,b)

        if (f(a)*f(pm)<0) then
            b=pm
        else
            a=pm
        end if

        if (f(pm)==0) then
            write(*,*) 'raiz en:',pm
            exit

        end if

        if ((b-a)/2.0<tolerancia) then
            write(*,*) 'tolerancia alcanzada'
            exit
        end if

        if (i==imax)then
            write(*,*) 'numero maximo de iteracciones'
            exit 
        end if

    end do
end program 

function f(x) 
    real x
    f=4*x**3-52*x**2+160*x-100
end function

function fpm(a,b)

    real a,b
    fpm=(a+b)/2.0
    end function