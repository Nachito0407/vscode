program contenedor
    implicit none
    real(8) x0,xk,tol,error,g
    integer(8) iteracion,max_iteraciones

    print*,'ingrese un valor de x'
    read*,x0
    
    tol=1e-9
    error=1.0
    iteracion=0
    max_iteraciones=1001
    do while(error>tol.and.iteracion<max_iteraciones)
        xk=g(x0)
        error=abs(xk-x0)
        x0=xk
        iteracion=iteracion+1
    end do

    if(error<=tol)then
        print*,'convergio a:',xk,'en',iteracion,'iteraciones'
    else
        print*,'no se convergio en',iteracion,'iteraciones'
    end if       
end program contenedor
function g(x)
    real(8) x,g
g=100 / (160 + 4*x**2 - 52*x)
end function