program operaciones_basicas
implicit none
integer a, b , c , op1, op2, op3, op4 , op5
a=3
b=5
c=4

op1= a/b*c
op2= a*b/c
op3= 3*a**b
op4= b+a/c
op5= a/b + c

print*, 'la operacion 1 es:',op1

print*, 'la operacion 2 es:',op2

print*, 'la operacion 3 es:',op3

print*, 'la operacion 4 es:',op4

print*, 'la operacion 5 es:',op5

end program operaciones_basicas