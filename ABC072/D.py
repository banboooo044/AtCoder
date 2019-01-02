N = int(input())
p = list(map(int,input().split(" ")))
order = list(range(1,N+1))

i = 0
ans = 0

while i < (N-1):
	if p[i] == order[i]:
		p[i] = -1
		if p[i+1] == order[i+1]:
			p[i+1] = -1
			ans += 1
			i += 1
		else:
			ans += 1

	i += 1

if p[N-1] == order[N-1]:
	ans += 1

print(ans)

