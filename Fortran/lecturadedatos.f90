program lecturadedatos
    implicit none
    real  v(100), suma_positivos, suma_negativos, promedio_negativo, promedio_positivo
    integer  i, cantidad_negativos, cantidad_positivos, ndato

    ! Inicializar variables
    suma_positivos = 0.0
    suma_negativos = 0.0
    promedio_negativo = 0.0
    promedio_positivo = 0.0
    cantidad_negativos = 0
    cantidad_positivos = 0

    open(11, file="datos.txt")
    read(11,*)
    read(11,*) ndato
    read(11,*)
    read(11,*)(v(i), i=1, ndato)

    do i = 1, ndato 
        if (v(i) > 0) then
            suma_positivos = suma_positivos + v(i)
            cantidad_positivos = cantidad_positivos + 1
        else if (v(i) < 0) then
            suma_negativos = suma_negativos + v(i)
            cantidad_negativos = cantidad_negativos + 1
        end if   
    end do

    ! Calcula los promedios
    if (cantidad_positivos > 0) then
        promedio_positivo = suma_positivos / cantidad_positivos
    else
        promedio_positivo = 0.0
    end if

    if (cantidad_negativos > 0) then
        promedio_negativo = suma_negativos / cantidad_negativos
    else
        promedio_negativo = 0.0
    end if

    ! Mostrar resultados
    print *, "Cantidad de elementos positivos:", cantidad_positivos
    print *, "Promedio de los elementos positivos:", promedio_positivo

    print *, "Cantidad de elementos negativos:", cantidad_negativos
    print *, "Promedio de los elementos negativos:", promedio_negativo

    close(11)

end program lecturadedatos
