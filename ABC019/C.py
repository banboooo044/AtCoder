N = int(input())
nmax = 100001
a = list(map(int,input().split(" ")))
dic = {}
a.sort()

cnt = 0
maxv = a[-1]
for i in range(N):
	if not a[i] in dic:
		cnt += 1
		p = a[i] + a[i]
		while p <= maxv:
			if not p in dic:
				dic[p] = 1
			p += p

print(cnt)
