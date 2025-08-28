program aproximacion_log_de_x
    implicit none
    integer i , n , exponente 
    real*8 term , term_next , t , log_x , x
    print *, 'Ingrese el valor de x:'
    read *, x
    print *, 'Ingrese el valor de n:'
    read *, n
    log_x = log(x)
    term = 0.0d0
    exponente = 0
    term_next = 0.0d0
    t=(x-1)/(x+1) 
    do i = 0, n
        exponente = 2*i+1
        term= 2.d0*t**exponente/(2.d0*i+1.d0)
        term_next = term_next + term
    end do

    print *, 'El valor de la aproximacion es: ', term_next , ' y el valor de log(x) es: ', log_x
end program aproximacion_log_de_x