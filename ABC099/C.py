N = int(input())
ans = 0
ls = []
while N >= 6:
	ls.append((N%3))
	N //= 3

ls.reverse()
l = len(ls)
for i in range(l):
	print(i)
	print(ls[i],ls[i+1])
	if i % 2 == 1 and ls[i] != 0:
		if i == (l-1):
			ans += 3
		else:
			ans += min(ls[i],ls[i+1])
			tmp = ls[i]
			ls[i] = max(ls[i]-ls[i+1],0)
			if ls[i] > 0:
				ans += (ls[i]*3)

			ls[i+1] = max(ls[i+1]-tmp,0)

	elif i % 2 == 0:
		ans += ls[i]
	
print(ans)