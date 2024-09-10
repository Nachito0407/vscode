program rectas
    implicit none
    real x1, x2, x3, x4, y1, y2, y3, y4, m1, m2, b1, b2, inter_y, inter_x, denominador
    integer cuadrante

    print*, 'Ingrese los puntos x1, y1:'
    read*, x1, y1
    print*, 'Ingrese los puntos x2, y2:'
    read*, x2, y2
    print*, 'Ingrese los puntos x3, y3:'
    read*, x3, y3
    print*, 'Ingrese los puntos x4, y4:'
    read*, x4, y4

    if (x2 - x1 == 0) then
        print*, 'La recta 1 es vertical'
    else
        m1 = (y2 - y1) / (x2 - x1)
    end if

    if (x4 - x3 == 0) then
        print*, 'La recta 2 es vertical'
    else
        m2 = (y4 - y3) / (x4 - x3)
    end if

    if (m1 == m2) then
        print*, 'Las rectas son paralelas'
    else
        b1 = y1 - m1 * x1
        b2 = y3 - m2 * x3
        denominador = m1 - m2
        if (denominador /= 0.0) then
            inter_x = (b2 - b1) / denominador
            inter_y = m1 * inter_x + b1
            print*, 'El punto de interseccion es: (', inter_x, ',', inter_y, ')'
            
            if (inter_x > 0 .and. inter_y > 0) then
                cuadrante = 1
            elseif (inter_x < 0 .and. inter_y > 0) then
                cuadrante = 2
            elseif (inter_x < 0 .and. inter_y < 0) then
                cuadrante = 3
            elseif (inter_x > 0 .and. inter_y < 0) then
                cuadrante = 4
            else
                cuadrante = 0
            end if

            if (inter_x == 0 .and. inter_y == 0) then
                print*, 'El punto está en el origen.'
            elseif (inter_x == 0) then
                print*, 'El punto está en el eje Y.'
            elseif (inter_y == 0) then
                print*, 'El punto está en el eje X.'
            else
                print*, 'La interseccion está en el cuadrante:', cuadrante
            end if
        end if
    end if
end program rectas