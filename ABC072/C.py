N = int(input())
A = list(map(int,input().split(" ")))
B = {}

for center in A:
	for num in [center-1,center,center+1]:
		if num in B:
			B[num] += 1
		else:
			B[num] = 1

print(max(B.values()))