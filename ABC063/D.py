N,A,B = map(int,input().split(" "))
mons = []
for i in range(N):
	h = int(input())
	mons.append(h)

minv = min(mons)
times = minv // B
if (minv % B != 0):
	times += 1
mons = list(map(lambda x:x - B * times,mons))

for i in range(times):
	maxv = max(mons)

count = 0
while True:
	maxv = max(mons)
	if maxv <= 0:
		break


	mons[mons.index(maxv)] -= (A - B)
	mons = list(map(lambda x:x - B,mons))
	count += 1

print(count)

