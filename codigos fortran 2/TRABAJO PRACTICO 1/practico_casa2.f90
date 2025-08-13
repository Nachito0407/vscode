program datos
    implicit none
    integer dd , mm , yy
    character*16 nombre
    print *, 'Ingrese su fecha de nacimiento (dd mm yyyy):'
    print *, 'Ingrese su nombre:'
    read(*,*) dd, mm, yy
    read(*,*) nombre
    write(*,*) dd, mm, yy ,'Es la fecha de nacimiento de :', nombre
end program datos