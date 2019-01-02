N,x = map(int,input().split(" "))
a = list(map(int,input().split(" ")))

share = 0
rm = [0] * (N-1)
for i in range(N-1):
	rm[i] = max(0,(a[i]+a[i+1])-x)


for i in range(N-2):
	s = min([rm[i],rm[i+1],a[i+1]])
	share += s
	rm[i] -= s
	rm[i+1] -= s

print(share + sum(rm))
	

