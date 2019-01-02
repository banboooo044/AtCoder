H,W = map(int,input().split(" "))
N,M = map(int,input().split(" "))

newh = min(N*2-1,H)
neww = min(M*2-1,W)
moveh = newh - N + 1
movew = neww - M + 1
imos = [[0]*(neww) for _ in range(newh)]
for i in range(N):
	S = input()
	for j in range(M):
		if S[j] == '#':
			imos[i][j] += 1
			if i + moveh < newh:
				imos[i+moveh][j] -= 1
			if j + movew < neww:
				imos[i][j+movew] -= 1
			if i + moveh < newh and j + movew < neww:
				imos[i+moveh][j+movew] += 1

pat = 0
for i in range(newh):
	for j in range(neww-1):
		imos[i][j+1] += imos[i][j]

for i in range(newh-1):
	for j in range(neww):
		imos[i+1][j] += imos[i][j]

for i in range(newh):
	for j in range(neww):
		if imos[i][j] != 0:
			pat += 1

if neww < W:
	for i in range(newh):
		if i == (N-1):
			continue
		if imos[i][M-1] != 0:
			pat += (W - 2*M + 1)

if newh < H:
	for i in range(neww):
		if i == (M-1):
			continue
		if imos[N-1][i] != 0:
			pat += (H - 2*N + 1)

if imos[N-1][M-1] != 0:
	if neww < H and newh < W:
		pat += ((H - 2*N + 2)*(W - 2*M + 2)-1)
	elif neww < W:
		pat += (W - 2*M + 1)
	elif newh < H:
		pat += (H - 2*N + 1)

print(pat)