program intercambio_de_variable 
    implicit none
    integer a,b,aux
    a=2
    b=3
    !hago que la variable aux sea igual a (a)
    aux=a
    !hago que a sea igual a (a)
    a=b
    !hago que aux sea igual a b
    b=aux
    print*,'nuevo valor de a=',a,'nuevo valor de b=',b
end program intercambio_de_variable