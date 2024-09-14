program punto_fijo
    implicit none
    real f,x0,tolerancia,x1,g
    integer itermax,iter,i

    tolerancia=0.000000001

    itermax=30

    print*,'ingrese un valor de x'
    read*,x0

    do
        x1=f(x0)
        iter=iter+1
        if ( abs(x1-x0)>) then
            
        end if
    end do  
    
end program punto_fijo

function f(x)
    real x,f
    f=4*x**3-52*x**2+160*x-100
end function

function g(x)
    real g,x0
    g=