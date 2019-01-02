def cn(num):
	m = 0
	for k in str(num):
		m += int(k)
	return m
lst = []
n = 10**6
for i in range(99999999999999,10**15,10000000000):
	lst.append((i/cn(i),i))

m = lst[-1][0]
print("[",end="")
for i in range(len(lst)-1,-1,-1):
	if lst[i][0] <= m:
		m = lst[i][0]
		print(lst[i][1],end=",")

print("]")