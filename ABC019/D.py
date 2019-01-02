N = int(input())
query = "? {0} {1}"
maxdis = -float('inf')
maxver = -1
for i in range(2,N+1):
	print(query.format(i,1))
	d = int(input())
	if d > maxdis:
		maxver = i
		maxdis = d

maxdis = -float('inf')
for i in range(1,N+1):
	if i == maxver:
		continue
	else:
		print(query.format(maxver,i))
		d = int(input())
		if maxdis < d:
			maxdis = d


print("! " + str(maxdis))
