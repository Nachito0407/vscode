program invert
    implicit none
    REAL*8 Valor, Inverso
    PRINT *, "Ingrese un valor para invertir"
    READ (*,*) Valor
    Inverso = 1.0/Valor
    PRINT *, "Valor", Valor, " Inverso", Inverso
end program invert