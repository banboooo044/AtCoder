N = int(input())
a = list(map(int,input().split(" ")))

zero = 0
two = 0
four = 0

for i in a:
	if i % 2 == 0:
		if i % 4 == 0:
			four += 1
		else:
			two += 1
	else:
		zero += 1

four -= zero
if four >= 0 or (two == 0 and four == (-1)):
	print("Yes")
else:
	print("No")
