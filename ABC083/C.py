X,Y = map(int,input().split(" "))

i = 1
while True:
	if (X * (1 << i)) > Y:
		break
	else:
		i += 1

print(i)