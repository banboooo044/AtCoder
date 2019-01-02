X = int(input())

sumval = 0
for i in range(1,X+1):
	sumval += i
	if sumval >= X:
		ans = i
		break

print(ans)
