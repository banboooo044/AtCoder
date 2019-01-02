N = int(input())
a = list(map(int,input().split(" ")))

cnt = 0
for i in range(N):
	while (a[i]) % 2 == 0:
		cnt += 1
		a[i] //= 2

print(cnt)