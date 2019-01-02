#漸化式 解法はokだが遅いのでc++で書けば通ると思われる。

import numpy as np
from math import log2 
MASK = (1 << 35) - 1


def multi_xor(mat1,mat2):
	#mat1 * mat2をxorとand演算で置き換える

	mat1 = np.array(mat1)
	mat2 = np.array(mat2).T

	mat1_l = mat1.shape[0]
	mat2_l = mat2.shape[1]

	retmat = [[0]*(mat2_l) for _ in range(mat1_l)] 

	for row in range(mat2_l):
		tmp = np.bitwise_and(mat1, mat2[row])
		for line in range(mat1_l):
			result = 0
			for l in tmp[line]:
				result = result ^ l
			retmat[line][row] = result
				

	return retmat

def multi_last(mat1,mat2):

	mat1 = np.array(mat1)
	mat2 = np.array(mat2)

	mat1_l = mat1.shape[0]
	mat2_l = mat2.shape[0]

	retmat = [[0]*(mat2_l) for _ in range(mat1_l)] 

	for row in range(mat2_l):
		tmp = np.bitwise_and(mat1, mat2[row])
		for line in range(mat1_l):
			result = 0
			for l in tmp[line]:
				result = result ^ l
			retmat[line][row] = result
				

	return retmat



K,M = map(int,input().split(" "))
A = list(map(int,input().split(" ")))
C = list(map(int,input().split(" ")))
index = M - K

if index <= 0:
	print(A[M-1])
	exit(0)

f = [C]
f_add = [[0]*(K) for i in range(K-1)]
for i in range(K-1):
	f_add[i][i] = MASK

f.extend(f_add)
f_list = [f]

num = 2
while num <= index:
	f = multi_xor(f,f)
	f_list.append(f)
	num += num


maxiter = int(log2(num))
repmat = np.eye(K,dtype=int) * int(MASK)
repmat = repmat.tolist()

for j in range(maxiter):
	if (index >> j) & 1:
		repmat = multi_xor(f_list[j],repmat)

A.reverse()
ans = multi_last(repmat,[A])

print(ans[0][0])



