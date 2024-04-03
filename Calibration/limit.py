from sympy import *

H = 15.75e-3  # in meters
D = 5.28e-3   # in meters
a = 4.37e-3   # in meters
c = 3.063     # in N/V

v1, v2, v3, v4, v5, v6 = symbols('v1 v2 v3 v4 v5 v6')
Fx, Fy, Fz = symbols('Fx Fy Fz')

Fx = ((a * c)/(2*sqrt(3)) - c * D) / H * v2 + ((a * c)/(2*sqrt(3)) - c * D) / H * v3 - ((a * c)/(sqrt(3)) + c * D) / H * v1 - ((a * c)/(2*sqrt(3)) - c * D) / H * v5 - ((a * c)/(2*sqrt(3)) - c * D) / H * v6 + ((a * c)/(sqrt(3)) + c * D) / H * v4
Fy = ((a * c)/2 * (v3 - v2 + v6 - v5)) / H
Fz = c * (v4 + v5 + v6 - v1 - v2 - v3)

A = Matrix(3, 6, lambda i, j: 0)

A[0, :] = Matrix([[Fx.coeff(v) for v in (v1, v2, v3, v4, v5, v6)]])
A[1, :] = Matrix([[Fy.coeff(v) for v in (v1, v2, v3, v4, v5, v6)]])
A[2, :] = Matrix([[Fz.coeff(v) for v in (v1, v2, v3, v4, v5, v6)]])

A_evalf = A.applyfunc(lambda x: x.evalf())

print(f"{A_evalf[0,:]}")
print(f"{A_evalf[1,:]}")
print(f"{A_evalf[2,:]}")