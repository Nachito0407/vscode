program encontrar_raiz
    implicit none

    real  a, b, tolerancia, fa, fb, medio, fmedio, raiz
    real  x, fx, error,f
    integer  iteraciones

    print *, 'Ingrese el valor de a (limite inferior del intervalo):'
    read *, a
    print *, 'Ingrese el valor de b (limite superior del intervalo):'
    read *, b
    print *, 'Ingrese la tolerancia deseada:'
    read *, tolerancia

    ! Verificar que la funcion cambie de signo en el intervalo
    fa = f(a)
    fb = f(b)
    if (fa * fb > 0) then
      print *, 'Error: La funcion no cambia de signo en el intervalo proporcionado.'
    stop
    end if

    ! Método de Bisección
    iteraciones = 0
    do
    medio = (a + b) / 2.0
    fmedio = f(medio)
    error = abs(b - a) / 2.0
    iteraciones = iteraciones + 1

    if (error < tolerancia .or. fmedio == 0.0) exit

      if (fa * fmedio < 0.0) then
        b = medio
        fb = fmedio
    else
        a = medio
        fa = fmedio
    end if
    end do

    raiz = medio
    print *, 'Metodo de Biseccion:'
    print *, 'Raiz:', raiz, 'Error:', error, 'Iteraciones:', iteraciones

    ! Solicitar al usuario que reinicie los valores para Régula Falsi
    print *, 'Ingrese el valor de a (límite inferior del intervalo) :'
    read *, a
    print *, 'Ingrese el valor de b (límite superior del intervalo) :'
    read *, b

    ! Verificar nuevamente el cambio de signo para Regula Falsi
    fa = f(a)
    fb = f(b)
    if (fa * fb > 0) then
      print *, 'Error: La funcion no cambia de signo en el intervalo proporcionado para Regula Falsi.'
    stop
    end if

    ! Método de Régula Falsi
    iteraciones = 0
    do
      x = a - fa * (b - a) / (fb - fa)
    fx = f(x)
    error = abs(b - a)
    iteraciones = iteraciones + 1

    if (error < tolerancia .or. fx == 0.0) exit

    if (fa * fx < 0.0) then
        b = x
        fb = fx
    else
        a = x
        fa = fx
    end if
    end do

    raiz = x
    print *, 'Metodo de Regula Falsi:'
    print *, 'Raiz:', raiz, 'Error:', error, 'Iteraciones:', iteraciones

end program encontrar_raiz

! Definicion de la funcion f(x)
function f(x)
    implicit none
    real  f
    real, intent(in) :: x

    f = 2.0 * x - 3.0
end function f
