program encontrar_raiz
    implicit none

    real a_bis, b_bis, a_rf, b_rf, tolerancia_bis, tolerancia_rf,f
    real fa, fb, medio, fmedio, raiz
    real  x, fx, error
    integer  iteraciones

    print *, 'Metodo de Biseccion:'
    print *, 'Ingrese el valor de a (limite inferior del intervalo):'
    read *, a_bis
    print *, 'Ingrese el valor de b (limite superior del intervalo):'
    read *, b_bis
    print *, 'Ingrese la tolerancia deseada:'
    read *, tolerancia_bis

    ! Verificar que la funcion cambie de signo en el intervalo para Biseccion
    fa = f(a_bis)
    fb = f(b_bis)
    if (fa * fb > 0) then
      print *, 'Error: La funcion no cambia de signo en el intervalo proporcionado para Biseccion.'
    stop
    end if

    ! Metodo de Biseccion
    iteraciones = 0
    do
    medio = (a_bis + b_bis) / 2.0
    fmedio = f(medio)
    error = abs(b_bis - a_bis) / 2.0
    iteraciones = iteraciones + 1

    if (error < tolerancia_bis .or. fmedio == 0.0) exit

      if (fa * fmedio < 0.0) then
        b_bis = medio
        fb = fmedio
    else
        a_bis = medio
        fa = fmedio
    end if
    end do

    raiz = medio
    print *, 'Metodo de Biseccion:'
    print *, 'Raíz:', raiz, 'Error:', error, 'Iteraciones:', iteraciones

    print *, 'Método de Régula Falsi:'
    print *, 'Ingrese el valor de a (limite inferior del intervalo):'
    read *, a_rf
    print *, 'Ingrese el valor de b (limite superior del intervalo):'
    read *, b_rf
    print *, 'Ingrese la tolerancia deseada:'
    read *, tolerancia_rf

    ! Verificar que la función cambie de signo en el intervalo para Regula Falsi
    fa = f(a_rf)
    fb = f(b_rf)
    if (fa * fb > 0) then
      print *, 'Error: La funcion no cambia de signo en el intervalo proporcionado para Regula Falsi.'
    stop
    end if

    ! Metodo de Regula Falsi
    iteraciones = 0
    do
      x = a_rf - fa * (b_rf - a_rf) / (fb - fa)
    fx = f(x)
    error = abs(b_rf - a_rf)
    iteraciones = iteraciones + 1

    if (error < tolerancia_rf .or. fx == 0.0) exit

      if (fa * fx < 0.0) then
        b_rf = x
        fb = fx
    else
        a_rf = x
        fa = fx
    end if
    end do

    raiz = x
    print *, 'Metodo de Regula Falsi:'
    print *, 'Raiz:', raiz, 'Error:', error, 'Iteraciones:', iteraciones

end program encontrar_raiz

! Declaracion de la funcion f(x) = 2x - 3 
real function f(x)
    implicit none
    real, intent(in) :: x
    f=2**(log(x)-sin(x))-1
end function f