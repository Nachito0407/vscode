program aproximacion_log
    implicit none
    integer n , i
    real*8 term , ln_2 ,term_next
    ln_2=LOG(2.d0)
    print *, 'Ingrese el valor de n:'
    read *, n
    term = 0.d0
    term_next = 0.d0
    i=0
    do i = 1 , n
        term = ((-1.d0)**(i-1.d0))
        term_next = term/i +  term_next
    end do

    print *, 'El valor de la aproximacion es:', term_next , ln_2
end program aproximacion_log