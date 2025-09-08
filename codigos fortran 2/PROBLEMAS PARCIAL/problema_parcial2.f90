Program SeleccionDirecta
implicit none
integer ,parameter :: n=9 
integer vector(n) ,i,j,eref ,jref ,aux ,iteraciones

vector = (/3,5,2,7,1,9,6,4,8/)
iteraciones = 0

do i=1,n-1 ! indice que identifica el pivote
    iteraciones = iteraciones + 1 
    eref = vector(i)
    jref = i
    do j=i+1,n ! recorre el subvector
        if (eref > vector(j)) then
            eref = vector(j)
            jref = j
    end if
end do
aux = vector(i)
vector(i) = vector(jref)
vector(jref) = aux

write(*,*) "Iteracion ", i, ": ", vector

end do

write(*,*) "------------------------------------"
write(*,*) "Vector ordenado = ", vector
write(*,*) "Cantidad de iteraciones = ", iteraciones

End Program SeleccionDirecta