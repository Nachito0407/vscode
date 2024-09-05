program volumen_esfera
    implicit none
    real radio, volumen
    real, parameter :: pi = 3.141592653589793
  
    ! Leer el radio
    print *, 'Ingrese el radio:'
    read *, radio
  
    ! Calcular el volumen de la esfera
    volumen = (4.0/3.0) * pi * radio**3
  
    ! Mostrar el resultado
    print *, 'El volumen de la esfera es: ', volumen
  
  end program volumen_esfera