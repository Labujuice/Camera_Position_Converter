from sympy import Symbol
import numpy


cos_att_x = Symbol('cos(att_x)')
cos_att_y = Symbol('cos(att_y)')
cos_att_z = Symbol('cos(att_z)')

sin_att_x = Symbol('sin(att_x)')
sin_att_y = Symbol('sin(att_y)')
sin_att_z = Symbol('sin(att_z)')

rotate_z = numpy.array([
    [cos_att_z, sin_att_z, 0],
    [-sin_att_z, cos_att_z, 0],
    [0, 0, 1]
])

rotate_y = numpy.array([
    [cos_att_y, 0, -sin_att_y],
    [0, 1, 0],
    [sin_att_y, 0, cos_att_y]
])

rotate_x = numpy.array([
    [1, 0, 0],
    [0, cos_att_x, sin_att_x],
    [0, -sin_att_x, cos_att_x]
])

#print(rotate_z)

#print(rotate_y)

#print(rotate_x)

DCM_i2b = rotate_x.dot(rotate_y).dot(rotate_z)

print("M11 = ", DCM_i2b[0,0], ";")
print("M12 = ", DCM_i2b[0,1], ";")
print("M13 = ", DCM_i2b[0,2], ";")
print("M21 = ", DCM_i2b[1,0], ";")
print("M22 = ", DCM_i2b[1,1], ";")
print("M23 = ", DCM_i2b[1,2], ";")
print("M31 = ", DCM_i2b[2,0], ";")
print("M32 = ", DCM_i2b[2,1], ";")
print("M33 = ", DCM_i2b[2,2], ";")