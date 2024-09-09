program ej_2_clases_guia5_1
    implicit none
    integer::iter
    real::xk,a,b,err,error,tolerancia,f

    error=tolerancia+1.0
    write(*,*)"Elija el intervalo donde cree que se encuentre la raiz"
    write(*,*)"a"
    read(*,*)a
    write(*,*)"b"
    read(*,*)b

    do while(error>tolerancia)
        xk=(a+b)/2.0
        if(f(a)*f(xk)<0) then
            b=xk
        else if(f(b)*f(xk)<0) then
            a=xk
        end if
    iter=iter+1
    error=abs(err(a,b)-xk)
    end do

    write(*,*)"La raiz aproximada es"
    print*,xk
    write(*,*)"El error es"
    print*,error
    write(*,*)"El numero de iteraciones es"
    print*,iter
end program ej_2_clases_guia5_1

function f(v)
    implicit none
    real::v,f
    f=2**(atan(v))+cos(v)
end function
function err(s,t)
    implicit none
    real::s,t,err
    err=(s+t)/2.0
end function