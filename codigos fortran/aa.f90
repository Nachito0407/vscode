Module Data
    Implicit none
    Integer, parameter :: n=4     !Dim. Matrix
    Real(8) a(n,n), b(n), x(n)
    Integer :: i,j,k
    Real(8) m,Prod
    Real(8) auxi,aux(n)
End Module

program Eliminacion_gaussiana
    Use Data
    Call lecdat
    Call triangulacion
    call retrosustitucion
    Call escdat
end program Eliminacion_gaussiana

subroutine pivoteo_parcial(l)
    Use Data
    Integer :: l
    Do j=l+1,n
        If (ABS(a(l,l))<ABS(a(j,l))) then 
            Do k=1, n
            aux(k)=a(l,k) 
            a(l,k)=a(j,k) 
            a(j,k)=aux(k)
            End do
            auxi=b(l)
            b(l)=b(j)
            b(j)=auxi
        End if
        End do
end subroutine pivoteo_parcial

subroutine retrosustitucion
    Use Data
do i=n, 1, -1
    Prod=0.d0
    do j = i+1, n
        Prod = Prod + a(i,j)*x(j)
    end do
    x(i)=(b(i)-Prod)/a(i,i)
end do
Print*,'Las soluciones son'
Do i=1,n
Print*,'x',i,x(i)
End do
end subroutine retrosustitucion


subroutine triangulacion
Use data
Do i=1,n-1
    call pivoteo_parcial(i)
    Do j=i+1,n
        m=a(j,i)/a(i,i)
        a(j,i)=0
        b(j)=b(j)-m*b(i)
        Do k=i+1,n
            a(j,k)=a(j,k)-m*a(i,k)
        end do
    end do
end do
end subroutine triangulacion

subroutine lecdat
Use Data
Open(1,File='Data.txt')
Read(1,*) !Matrix
Do i=1,n
Read(1,*)(a(i,j),j=1,n)
End do
Read(1,*) !Ind. terms
Read(1,*)(b(i),i=1,n)
end subroutine lecdat

subroutine escdat
Use Data
Open(1,File='Data2.txt')
write(1,*) "Matriz resultante"
Do i=1,n
Write(1,*)(a(i,j),j=1,n)
End do
Write(1,*) "Resultados"
Write(1,*)(b(i),i=1,n)
end subroutine escdat