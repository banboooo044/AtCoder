a,b = map(str,input().split(" "))
c = a + b
c = int(c)
for i in range(1000):
	if (i ** 2) == c:
		print("Yes")
		exit(0)


print("No")