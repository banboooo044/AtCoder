from math import sqrt
N = int(input())

div = 1
max_v = int(sqrt(N))
for num in range(max_v,1,(-1)):
	if N % num == 0:
		div = num
		break

#print(div)
print(max(len(str(div)),len(str(N//div))))