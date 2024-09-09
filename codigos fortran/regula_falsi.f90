program ej_2_clases_guia5_2
    implicit none
    integer::i
    real::xk,a,b,error,err,tolerancia,f

    tolerancia=0.000001
    error=tolerancia+1.0
    i=0
    
    write(*,*)"Defina el intervalo donde cree que se encuentra la raÃz"
    write(*,*)"a"
    read(*,*)a
    write(*,*)"b"
    read(*,*)b

    do while(error>tolerancia)
        xk=a-(f(a)*(b-a))/(f(b)-f(a))
        if(f(a)*f(xk)<0) then
            b=xk
        else if(f(b)*f(xk)<0) then
            a=xk
        else if(f(xk)==0) then 
            exit
        end if
        error=abs(err(a,b)-xk)
        i=i+1
    end do

    write(*,*)"La raiz aproximada es"
    print*,xk
    write(*,*)"El error es"
    print*,error
    write(*,*)"El numero de iteraciones es"
    print*,i
end program ej_2_clases_guia5_2

function f(v)
    implicit none
    real::v,f
    f=2**(log(v)-sin(v))-1
end function

function err(s,t)
    implicit none
    real::err,s,t,f
    err=s-(f(s)*(s-t))/(f(s)-f(t))
end function