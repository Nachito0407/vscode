program cosenos_directores
implicit none
real(8) ex, ey, ang , pi , alf_grad
print*,' Ingrese el angulo en grados'
read*, alf_grad
pi=dacos(-1.d0)
ang=alf_grad*pi/180.d0
ex=dcos(ang)
ey=dsin(ang)
print*,'El coseno del angulo es: ', ex
print*,'El seno del angulo es: ', ey
end program