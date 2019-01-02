N = int(input())
ans = float('inf')
for i in range(1,N):
	num = i
	j = N - num
	d = 0
	while num != 0:
		d += (num % 10)
		num //= 10
	while j != 0:
		d += (j % 10)
		j //= 10

	ans = min(d,ans)

print(ans)