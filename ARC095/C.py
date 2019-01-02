N = int(input())
X = list(map(int,input().split(" ")))
X2 = X[:]
X2.sort()
mid = (N-1)//2
l = X2[mid]
r = X2[mid+1]
for i in range(N):
	if X[i] <= l:
		print(r)
	else:
		print(l)
