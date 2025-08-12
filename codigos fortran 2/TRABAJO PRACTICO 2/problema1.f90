program contador1
    implicit none
    integer i, cont
    cont=0
    do i=2 , 7 ,3
        cont=cont+1
    end do

    print*, i , cont
end program contador1