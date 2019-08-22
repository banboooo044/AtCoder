# D:派閥

N,M = map(int,input().split(" "))

rel = {}
count = 1
prev_count = 1

#辞書の初期化
for i in range(1,N+1):
	rel[i] = i

for i in range(M):
	x,y = map(int,input().split(" "))
	if x < y:
		if x < rel[y]:
			rel[y] = x
		else:
			pass
	else:
		if y < rel[x]:
			rel[x] = y
		else:
			pass

for i in range(1,N+1):
	for j in range(i+1,N+1):
		if rel[j] == i:
			count += 1

	if prev_count < count:
		prev_count = count

	count = 1

print(prev_count)

#完全グラフの頂点の個数を数える問題

#グラフで繋がってることを確認したい場合は rel[x] <-> rel[y] の中身をそのまま入れ替える手法 + while(j != rel[move])でいける。
#使ったものを0で初期化していくとより効率的か。

