program punto_fijo
    implicit none
    real(8) tolerancia
    real(4) f,x1,x0
    integer itermax,iter

    tolerancia=1.0d-9
    itermax=100000

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
        
        if (f(x0)==0)then
            print*,'raiz aproximada en:',x0
        end if

        if(iter==itermax)then
        print*,'el metodo no converge'
        end if
    end do
end program punto_fijo

function f(x)
    implicit none
    real x,f
    f=100 / (160 + 4*x**2 - 52*x)
end function