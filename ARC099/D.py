K = int(input())
cnt = 0
b = 1
ans = 1
nine = 0
while cnt < K:
	print(ans)
	cnt += 1


	if str(ans)[0] ==  '9':
		b *= 10
	ans += (b)
[]