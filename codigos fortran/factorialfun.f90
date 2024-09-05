program factorial
    implicit none
    integer func,n,resultado

    print*, "ingrese un numero para obtener su factorial"

    read*,n

    resultado=func(n)

    print*,"el resultado es:",resultado

end program factorial

function func(n) result(fact)
    integer, intent(in) :: n
    integer fact,i

    fact=1
    
        do i = 1, n
            fact=fact*i
        end do
    
    end function func
