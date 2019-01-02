from scipy.linalg import lu
import numpy as np

A = np.array([[1,1,-1],
              [-2,0,1],
              [0,2,1]])
b = np.array([7, 6, 8])

A = np.array([[8,2,6,7],[16,7,7,22],[24,12,32,46],[32,17,59,105]])
P,L,U = lu(A)
print(P)
print(L)
print(U)