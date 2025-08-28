program aproximacion_log_de_x_con_error
    implicit none
    integer i , exponente 
    real*8 term , term_next , t , log_x , x , error
    print *, 'Ingrese el valor de x:'
    read *, x
    log_x = log(x)
    term = 0.0d0
    exponente = 0
    term_next = 0.0d0
    error = 1.d0
    t=(x-1.d0)/(x+1.d0) 
    do while (error > 1.0d-10)
        exponente = 2*i+1
        term= 2.d0*t**exponente/(2.d0*i+1.d0)
        term_next = term_next + term
        error = (log(x)-term_next)/log(x)
    end do

    print *, 'El valor de la aproximacion es: ', term_next , 'El valor del error es:' , error 
    print *, ' y el valor de log(x) es: ', log_x
    print *, 'El valor de x es: ', x
end program aproximacion_log_de_x_con_error