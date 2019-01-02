N = int(input())
A = list(map(int,input().split(" ")))
B = list(map(int,input().split(" ")))
C = list(map(int,input().split(" ")))

A.sort()
B.sort()
C.sort()
cnt = 0
for i in range(N):
	v = B[i]
	l = 0
	r = N
	while (l < r):
		mid = (l+r)//2
		if A[mid] < v:
			l = mid + 1
		else:
			r = mid - 1
	print(l,r)
	num1 = l+1
	l = 0
	r = N
	while (l < r):
		mid = (l+r)//2
		if C[mid] > v:
			r = mid - 1
		else:
			l = mid + 1
	num2 = 
	print(l,r)

	print(num1,num2)
	cnt += (num1 * num2)

print(cnt)


