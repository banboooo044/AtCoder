a = list(map(int,input().split(" ")))
a.sort()
ans = a[2] - a[1]
a[0] += ans
ans += ((a[2] - a[0])//2)
if (a[2] - a[0])%2 == 1:
	ans += 2

print(ans)