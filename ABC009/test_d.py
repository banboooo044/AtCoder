import random
import string
import subprocess
from itertools import count
import numpy as np
from math import log2 
MASK = (1 << 35) - 1

K = random.randint(1,10)
M = random.randint(1,10)
A = []
C = []

filename = "./result"

with open(filename,'w') as fileObj:
	fileObj.write(str(K) + " " + str(M) + "\n")
	print(str(K) + " " + str(M))

	for i in range(K):
		a = random.randint(1,10)
		fileObj.write(str(a) + " ")
		print(str(a) + " ",end="")
		A.append(a)
	fileObj.write("\n")
	print()

	for j in range(K):
		c = random.randint(1,10)
		print(str(c) + " ",end="")
		fileObj.write(str(c) + " ")
		C.append(c)
	print()
	fileObj.write("\n")

cp = subprocess.Popen(["cat",filename],stdout=subprocess.PIPE)
execute = subprocess.Popen("./a.out",shell=True,stdin=cp.stdout,stdout=subprocess.PIPE)
output = execute.stdout

for line in output:
	ans2 = line.decode('ascii')

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

index = M - K

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

if 
ans2 = int(list(ans2)[0])
print("正解",ans2)
print("回答",ans[0][0])

if ans[0][0] == ans2:
	print("OK")
else:
	print("NO")

