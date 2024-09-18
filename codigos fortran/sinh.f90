program problema1
    implicit NONE
    integer i, n, fact, signo, k, par_fact
    real(8) x, serievieja, serienueva, error, tolerancia
    print*, "ingrese un numero"
    read*, x
    if (abs(x) < 1) then
    
        print*, "ok"
    else
        print*, "usted eligio valores fuera del rango permitido"
        stop
    end if
    k=0
    fact=1
    par_fact=1
    serievieja=x
    serienueva=0.d0
    tolerancia=1e-5
    error=tolerancia+1.d0
    
    do while (error>tolerancia )
        if( k > 100) then
        print*, "usted supero la cantidad de terminos"
        stop
        end if
    
    k=k+1
    
    fact=1
    do i=1, k
        fact=fact*i
    end do
    
    par_fact=1
    do i=1, 2*k
        par_fact=par_fact*i
    end do
    signo=(-1)**k
    
    
    serienueva=serievieja+x**(2.d0*k+1)*signo*par_fact/(4.d0**k*fact**2*(2.d0*k+1.d0))
    
    
    
    error=abs((serienueva-serievieja)/(0.5*(serienueva+serievieja))) 
    
    serievieja=serienueva 
    
    
    end do
    print*, "la serie es", serienueva
    print*, "cantidad de iteraciones", k
    end program