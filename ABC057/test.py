def nClr(n,l,r):
	ans = 0
	pat = 1
	if l == 0:
		ans += 1
		l += 1

	for i in range(l-1):
		pat *= ((n-i)/(i+1))

	for i in range(l-1,r):
		pat *= ((n-i)/(i+1))
		ans +=  pat

	return int(ans)

print(nClr(4,0,4))