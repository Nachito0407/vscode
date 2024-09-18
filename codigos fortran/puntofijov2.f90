program caja_de_chapa
    implicit none
    real(8) tolerancia,x,error,x_anterior,i
    print*, "ingrese valor inicial"
    read*, x
    print*, "ingrese valor de la tolerancia"
    read*, tolerancia
    
    error=1
    i=0
    
    do while (error>tolerancia)
        x_anterior=x
        x=(4*(x**3)-52*(x**2)-100)/(-160)
        error=abs(x-x_anterior)
        i=i+1
    end do
    print*, "iteraciones : ", i
    print*, "valor de la raiz : ",x
    print*, "error : ", error
    
    end program
    