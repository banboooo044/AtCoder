N = int(input())
a = list(map(int,input().split(" ")))
b = list(map(int,input().split(" ")))

dif = sum(b) - sum(a)

if dif < 0:
	print("No")
	exit(0)

count = 0
for i in range(N):
	if (a[i] % 2) != (b[i] % 2):
		b[i] += 1
		count += 1
	
	if b[i] < a[i]:
		count += (a[i] - b[i])

if count > dif:
	print("No")
	exit(0)

if ((dif - count) % 2) == 0:
	print("Yes")
else:
	print("No")
