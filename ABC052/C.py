dissembly = {}
def factoring(N):
	from math import sqrt
	global dissembly
	search_maxval = sqrt(N) + 1
	i = 2
	while True:
		if N == 1 or i == search_maxval:
			break

		if N % i == 0:
			if i in dissembly:
				dissembly[i] += 1
			else:
				dissembly[i] = 1

			N /= i

		else:
			i += 1


n = int(input())
ans = 1
for i in range(2,n+1):
	factoring(i)


for val in dissembly.values():
	ans *= (val+1)
	ans %= ((10 ** 9) + 7)

print(ans)
