import math
a = math.factorial(n) / math.factorial(r) / math.factorial(n-r)
N = int(input())
A = list(map(int,input().split(" ")))
dic = {0:1,A[0]:1}
for i in range(N-1):
	A[i+1] += A[i]
	if A[i+1] in dic:
		dic[A[i+1]] += 1
	else:
		dic[A[i+1]] = 1
cnt = 0
for val in dic.values():
	if val >= 2:
		 cnt += comb(val,2)

print(int(cnt))