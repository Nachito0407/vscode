program calculopi
    implicit none
    integer nimpar , i
    real(8) signo , term , tolerancia , error , pi_a

    tolerancia= 1.d-5
    error= tolerancia + 1.d0
    pi_a= 0.d0
    i= 0

    do while (error > tolerancia)
        nimpar= 2*i + 1 !nro impar
        signo= (-1)**i !signo
        term= 4.d0 * signo / nimpar 
        pi_a= pi_a + term !aporte a pi
        error= abs(term) !error
        i= i+1 !nro de terminos de la serie
    end do

    write(*,*) "pi_a=" , pi_a
    write(*,*) "terminos=" , i

end program calculopi