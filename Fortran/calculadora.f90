Program calculadora
    Implicit none
    Real a,b,c,suma,resta,producto,potencia,division,discriminante,raiz1,raiz2,parteimaginaria,partereal
    Character*10 operacion

    Suma=0

    Resta=0

    producto=0

    potencia=0

    division=0

    discriminante=0

    Write(*,*) "ingrese la operacion a realizar"

    Read(*,*) operacion

    Select case (operacion)

        Case("suma")
        
        Write(*,*) "ingrese un valor a:"
        Read(*,*) a
        Write(*,*) "ingrese un valor b:"
        Read(*,*) b
        suma=a+b
        Write(*,*) "suma", suma

    Case("resta")
        Write(*,*) "ingrese un valor a:"
        Read(*,*) a
        Write(*,*) "ingrese un valor b:"
        Read(*,*) b
        resta=a-b
        Write(*,*) "resta", resta

    Case("producto")
        Write(*,*) "ingrese un valor a:"
        Read(*,*) a
        Write(*,*) "ingrese un valor b:"
        Read(*,*) b
        producto=a*b
        Write(*,*) "resultado del producto:", producto

    Case("potencia")
        Write(*,*) "ingrese un valor a:"
        Read(*,*) a
        Write(*,*) "ingrese un valor b:"
        Read(*,*) b
        potencia=a**b
        Write(*,*) "resultado del producto:", potencia

    Case("division")
        Write(*,*) "ingrese un valor a:"
        Read(*,*) a
        Write(*,*) "ingrese un valor b:"
        Read(*,*) b
        division=a/b
        Write(*,*) "resultado del la division:", division

    Case("raices")
        Write(*,*) "ingrese un valor a:"
        Read(*,*) a
        Write(*,*) "ingrese un valor b:"
        Read(*,*) b
        Write(*,*) "ingrese un valor c:"
        Read(*,*) c
        discriminante= (b**2) - 4*a*c
        if ( discriminante>0 ) then !para raices reales
            raiz1=(-b+sqrt(discriminante))/(2.0*a)
            raiz2=(-b-sqrt(discriminante))/(2.0*a)
            print*,'las raices son reales'
            print*,'Raiz1=',raiz1
            print*,'Raiz2=',raiz2
        else
            partereal=-b/(2.0*a)
            parteimaginaria=sqrt(-discriminante)/(2.0*a)
            print*,'raices complejas'
            print*,'Raiz1=',partereal,'+',parteimaginaria,'i'
            print*,'Raiz2=',partereal,'-',parteimaginaria,'i'
        end if

    Case default

        Write(*,*) "operacion no soportada"

    end select  
        
    end program calculadora