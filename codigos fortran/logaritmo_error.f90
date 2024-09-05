program logaritmo_con_error
    implicit none
    integer n
    real(8) x, lnX, term, tolerancia, error, LOGX

    print*,"ingrese el valor de x"
    read*, x

!defino el logaritmo que tiene fortran
    LOGX=log(x)

    !inicio las variables
    n=0
    lnX=0
    term=(x-1)/(x+1)
    tolerancia= 1.0e-8 !supongo que ese error es suficiente

    !inicio el bucle
        do
            n=n+1
            lnX= lnX +(2.0/(2*n-1))*term**(2*n-1)
            error= abs((LOGX-lnX)/LOGX)

            if ( error<=tolerancia ) exit
        end do

    print*, 'Aproximacion de lnX con ', n, ' terminos es: ',lnX
    print*, 'el LOGX es :',LOGX
    print*, 'el error es:', error
end program logaritmo_con_error