Program main
Implicit none
Integer i
i = 2.d0**31 -1
Write (*,*) i+1 !da -2147483648 por que no le da el rango de un entero
End Program