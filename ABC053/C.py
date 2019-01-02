x = int(input())
ans = 0


ans += 2*(x//11)
if x % 11 > 6:
	ans += 2
elif x % 11 > 0:
	ans += 1

print(ans)