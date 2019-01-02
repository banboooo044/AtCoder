n = int(input())
e = 1000001
r = [0]*e
for i in range(n):
	a,b = map(int,input().split(" "))
	r[a] += 1
	if b != (e-1):
		r[b+1] += (-1) 

ma = r[0]
for i in range(e-1):
	r[i+1] += r[i]
	ma = max(r[i+1],ma)
print(ma)