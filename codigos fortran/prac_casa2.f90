program fechaynombre
    implicit none
integer dd,mm,yy
!para poner el nombre si o si tengo que poner character*16 para poder poner varias letras
character*16 nombre
!hacer que pida el dia
print*,'ingrese_dd'
read*, dd
!hacer que pida el mes
print*,'ingrese_mm'
read*, mm
!hacer que pida el año
print*,'ingrese_yy'
read*, yy
!hacer que pida el nombre
print*,'ingrese_nombre'
read*,nombre
print*,dd,mm,yy,'es la fecha de nacimiento',' y el Nombre:',nombre    
end program fechaynombre