program sumador
    implicit none
    real x
    !al poner read no asume el valor de la variable
    read*,x
    !pongo cualquier valor para sumar a x ya que la variable es real
    x=x+3.2
    print*,x
end program sumador