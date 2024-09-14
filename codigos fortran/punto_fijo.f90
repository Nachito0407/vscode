program punto_fijo
    implicit none
    real(8) tolerancia
    real(4) f,x1,x0
    integer itermax,iter

    tolerancia=1.0d-9
    itermax=1000

    print*,'ingrese un valor de x'
    read*,x0

    do iter=1 , itermax

        x1=f(x0)
        if (abs((x1-x0)/x1)<tolerancia) then
            print*,'la raiz aproximada es:',x1
            print*,'numero de iteraciones:',iter
            exit
        end if
    x0=x1

    end do  
    
    if(iter==itermax)then
        print*,'el metodo no converge'
    end if

end program punto_fijo

function f(x)
    real x,f
    f=(4*x**3-52*x**2+161*x-100)/(-1000)
end function