Program parcial1
    Implicit none
    Integer,parameter:: n_fil=4, n_col=4
    Integer:: JR(n_fil*n_col), JC(n_fil*n_col), cont
    Real(8):: matriz(n_fil,n_col)
    Real(8):: AA(n_fil*n_col)

    Call matrix_reader("matriz_p1.txt",n_fil,n_col,matriz)
    Call reductor_matricial(matriz,n_fil,n_col,AA,JR,JC,cont)
    Print*, "Encontre", cont, " valores distintos de 0"
    Call vector_printer("AA",AA,cont)
    Call vector_printer_integer("JR",JR,cont)
    Call vector_printer_integer("JC",JC,cont)

End program parcial1

Subroutine Matrix_reader(nombre_arch,n_fil,n_col,matriz)
    Implicit none
    Integer:: i, j
    Integer,intent(in):: n_fil, n_col
    Character(len=*), Intent(in):: nombre_arch
    Real(8),intent(out):: matriz(n_fil,n_col)
    Open(10,file=nombre_arch)
    Read(10,*) !crap
    Read(10,*) !n_fil, n_col  
    Read(10,*) !crap
    Do i=1, n_fil
        Read(10,*) (matriz(i,j), j=1, n_col)
    End do
    Close (10)
End subroutine matrix_reader

Subroutine vector_printer (nombre,vector,n)
    Implicit none
    Character(len=*),intent(in):: nombre
    Integer,intent(in):: n
    Real(8),intent(in):: vector(n)
    Integer::i

    Print*, "El vector ", nombre, " es:"
    Print*, (vector(i), i=1,n)
End subroutine vector_printer

Subroutine vector_printer_integer (nombre,vector,n)
    Implicit none
    Character(len=*),intent(in):: nombre
    Integer,intent(in):: n, vector(n)
    Integer::i

    Print*, "El vector ", nombre, " es:"
    Print*, (vector(i), i=1,n)
End subroutine vector_printer_integer

Subroutine reductor_matricial (matriz,n_fil,n_col,AA,JR,JC,cant_val)
    Implicit none
    Integer,intent(in):: n_fil, n_col
    Real(8),intent(in):: matriz(n_fil,n_col)
    Integer,intent(out):: JR(n_fil*n_col), JC(n_fil*n_col),cant_val
    Real(8),intent(out):: AA(n_fil*n_col)
    Integer:: i, j, cont=1

    Do i=1, n_fil
        Do j=1, n_col
            If (matriz(i,j) /= 0.d0) then
                AA(cont)= matriz(i,j)
                JR(cont)= i
                JC(cont)= j 
                cont= cont + 1
            End if
        End do
    End do
    cant_val= cont-1 !Indico la cantidad de valores no nulos que encontre
End subroutine reductor_matricial