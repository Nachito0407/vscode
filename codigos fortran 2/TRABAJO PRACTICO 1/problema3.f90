program volumen
    implicit none
    real vol ,r, pi
    pi=acos(-1.0)
    print*,'Ingrese el radio de la esfera:'
    read*, r
    vol=(4.0/3.0)*pi*r**3
    print*,'El volumen de la esfera es:', vol
end program volumen