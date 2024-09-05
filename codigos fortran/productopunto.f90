program productopunto
    implicit none
    integer ,parameter :: n=5
    real(8) vector1(n),vector2(n), dotp1,norma_a,norma_b,dotp2
    integer i

    vector1=(/1.0d0,2.0d0,3.0d0,4.0d0,5.0d0/)
    vector2=(/6.0d0,7.0d0,8.0d0,9.0d0,10.0d0/)

    dotp1=0.d0
    dotp2=0.d0
    norma_a=0.d0
    norma_b=0.d0

    do i = 1, n
        dotp2=dotp2+vector1(i)*vector2(i)
    end do

        dotp1=dot_product(vector1,vector2)

        norma_a =sqrt(dot_product(vector1,vector1))
        norma_b =sqrt(dot_product(vector2,vector2))

        write(*,*) "dotp2 (calculado manualmente) =", dotp2
        write(*,*) "dotp1 (usando dot_product) =", dotp1
        write(*,*) "norma_a=",norma_a
        write(*,*) "norma_b=",norma_b
end program productopunto