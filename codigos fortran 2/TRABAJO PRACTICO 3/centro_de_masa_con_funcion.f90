program centro_de_masa_con_funcion
    implicit none
        real(8) x(100) , y(100) , m(100) , cmx
    integer i , ndatos
    
    open(10 , file='cg.txt')
    read(10 , *)
    read(10 , *) ndatos
    read(10, *)

    do i=1,ndatos
        read(10 , *) x(i) , y(i) , m(i)
    end do

    close(10)

    print * , 'el centro de masa en x es: ' , cmx(x , m , ndatos)
    print * , 'el centro de masa en y es: ' , cmx(y , m , ndatos)

end program centro_de_masa_con_funcion

function cmx(x, m , ndatos)

    implicit none
    integer ndatos , i
    real(8) x(100) , m(100) ,cmx 
    real(8) sum_masa , sum_xcm
    sum_masa=0.0d0
    sum_xcm=0.0d0
    do i = 1, ndatos
        sum_masa= sum_masa+m(i)
        sum_xcm= sum_xcm+x(i)*m(i)
    end do
    cmx= sum_xcm/sum_masa
end function cmx