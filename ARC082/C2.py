#C問題 together

N = int(input())
a = list(map(int,input().split(" ")))

minval = min(a)
maxval = max(a)

a2 = []

ans = []

for j in a:
	for i in [-1,0,1]:
		a2.append(i+j)

for i in range(minval-1,maxval+2):
	ans.append(a2.count(i)) 

print(max(ans))


