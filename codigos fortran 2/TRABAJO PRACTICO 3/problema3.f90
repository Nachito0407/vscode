program centro_de_masa
    implicit none
    real(8) x(100) , y(100) , m(100)
    integer i , ndatos 
    real(8) xcm , ycm , sum_masa , sum_xcm , sum_ycm

    open(10 , file='cg.txt')
    read(10 , *)
    read(10 , *) ndatos
    read(10, *)

    do i=1,ndatos
        read(10 , *) x(i) , y(i) , m(i)
    end do

    close(10)

    xcm=0.0d0
    ycm=0.0d0
    sum_masa=0.0d0
    sum_xcm=0.0d0
    sum_ycm=0.0d0

    do i=1,ndatos
        sum_masa= sum_masa+m(i)
        sum_xcm= sum_xcm+x(i)*m(i)
        sum_ycm= sum_ycm+y(i)*m(i)
        ycm= sum_ycm/sum_masa
        xcm= sum_xcm/sum_masa
    end do

    print *,'El centro de masa es: (',xcm,',',ycm,')'
    
end program centro_de_masa