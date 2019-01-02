N = int(input())
A = list(map(int,input().split(" ")))
over2 = []
num = {}

for length in A:
	if length in num:
		num.pop(length)
		over2.append(length)
	else:
		num[length] = 1


over2.sort()

if len(over2) >= 2:
	print(over2[-1]*over2[-2])
else:
	print(0)

