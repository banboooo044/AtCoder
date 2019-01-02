r,c = map(int,input().split(" "))
arr = []
for i in range(r):
	C = input()
	num = 0
	for j in range(c):
		if C[j] == '.':
			num += (1 << j)
	arr.append(num)

arr2 = arr[:]

for i in range(r):
	for j in range(c):
		if (arr2[i] >> j) & 1:
			count += 1
			arr2[i] - (1 << j)
	


