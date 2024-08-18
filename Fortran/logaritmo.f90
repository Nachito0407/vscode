program logaritmo_x
    implicit none
    real(8)  x, lnX, constante, term
    integer  j, n

    n = 10000

    print*, "Ingrese valor de x"
    read*,  x

    ! Inicializar ln(x)
    lnX = 0.0d0

    ! Loop para sumar terminos del ln(x)
    do j = 0, n
        constante = 1.0d0 / (2 * j + 1)
        term = ((x - 1) / (x + 1)) ** (2 * j + 1)
        lnX = lnX + constante * term
    end do

    lnX = 2.0d0 * lnX

    write(*,*) "X =", x, "ln(X) =", lnX
end program
