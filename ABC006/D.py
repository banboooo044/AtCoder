N = int(input())
C = [0] * N

for i in range(N):
	C[i] = int(input())

i = 0
count = 0

while True:
	print(C[])

	if (i == N - 1):
		break

	if ((C[i] != i+1)) and (C[i+1] != C[i] + 1):
		if C[i] == 1:
			C.pop(i)
			C.insert(0,1)
			count += 1

		else:
			print(C)
			ind = C.index(C[i]-1)

			if ind == i-1:
				pass

			else:
				C.insert(ind+1,C[i])

				if ind > i:
					C.pop(i)
					i -= 1
					count += 1

				else:
					C.pop(i+1)
					count += 1
	
	i += 1




print(C)
print(count)





			


