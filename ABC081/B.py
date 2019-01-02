N = int(input())
A = list(map(int,input().split(" ")))

for i in range(0,35):
	k = 2 << i
	B = list(map(lambda x:x%k,A))
	if B.count(0) != N:
		print(i)
		exit(0)
	