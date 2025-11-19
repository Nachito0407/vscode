program sistema1
    implicit none
    
end program sistema1


subroutine eliminacion_gauss(a ,n, b) 
    implicit none
    integer i , j , k , n
    real(8) :: a(n,n) , b(n)
    real(8) m 
    do i=1 , n-1
        do j=i+1 , n
            m= a(j,i)/a(i,i)
            a(j,i)= 0.0d0
            b(j)=b(j)-m*b(i)
            do k = i+1 , n
                a(j,k)= a(j,k) - m*a(i,k)
            end do
        end do
    end do
    end subroutine eliminacion_gauss

subroutine retrosustitucion(a,n,b,x)
    implicit none
    integer :: n, i, j
    real(8) :: a(n,n), b(n), x(n)
    real(8) :: suma
    
    x(n) = b(n)/a(n,n)
    
    do i = n-1, 1, -1
        suma = 0.0d0
        do j = i+1, n
            suma = suma + a(i,j)*x(j)
        end do
        x(i) = (b(i) - suma)/a(i,i)
    end do
end subroutine retrosustitucion

subroutine pivoteo_trivial(a,n,b)
    implicit none
    integer :: n, i, j, k
    real(8) :: a(n,n), b(n)
    real(8), dimension(n) :: temp_f
    real(8) :: temp_b
    
    do i = 1, n-1
        k = i
        do j = i+1, n
            if (abs(a(j,i)) > abs(a(k,i))) then
                k = j
            end if
        end do
        
        if (k /= i) then
            temp_f = a(i,:)
            a(i,:) = a(k,:)
            a(k,:) = temp_f
            
            temp_b = b(i)
            b(i) = b(k)
            b(k) = temp_b
        end if
    end do
end subroutine pivoteo_trivial

subroutine fun(x, n , f)
    implicit none
    integer n
    real(8) :: x(n) , f(n)
    
    f(1)= x(1)**3 + x(2) - 1
    f(2)= x(2)**3 - x(1) + 1
end subroutine fun

subroutine jaco(x , n ,j)
    implicit none
    integer n , i
    real  h
    real(8) :: J(n,n)
    real(8) :: df1(n) , df2(n) , e(n) , x(n) 

    n=2
    h=0.01
    e=0.d0
    do i=1 , n
        e(i)=1
        call fun(x+e*h , n , df1)
        call fun(x-e*h , n , df2)
        J(:,i)=(df1-df2)/2*h
        e(i)=0
    end do
end subroutine jaco