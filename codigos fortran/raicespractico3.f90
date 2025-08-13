program raices
    implicit none
    real(8) discriminante,a,b,c,partereal,parteimaginaria,raiz1,raiz2
    print*,"ingrese b"
    read*,b
    print*,"ingrese a"
    read*,a
    print*,"ingrese c"
    read*,c

    discriminante= (b**2) - 4*a*c
    if ( discriminante>0 ) then !para raices reales
        raiz1=(-b+sqrt(discriminante))/(2.0*a)
        raiz2=(-b-sqrt(discriminante))/(2.0*a)
        print*,'las raices son reales'
        print*,'Raiz1=',raiz1
        print*,'Raiz2=',raiz2
    else
        partereal=-b/(2.0*a) !para raices complejas
        parteimaginaria=sqrt(-discriminante)/(2.0*a)
        print*,'raices complejas'
        print*,'Raiz1=',partereal,'+',parteimaginaria,'i'
        print*,'Raiz2=',partereal,'-',parteimaginaria,'i'
    end if

end program raices