PROGRAM INVERT
    IMPLICIT NONE
    REAL*8 Valor, Inverso
    PRINT *, "Ingrese un valor para invertir"
    Read (*,*) valor
    Inverso = 1.0/Valor
    PRINT *, "Valor", Valor, " Inverso", Inverso
    END PROGRAM INVERT