#二次元累積和を用いる。

def query(x1,y1,x2,y2):
	""" (x2,y2) : 右上の点,(x1,y1) : 左下の点 """
	return arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1]

N , K = map(int,input().split(" "))
arr = [[0] * (4*K) for _ in range(4*K)]

for i in range(N):
	x,y,c = map(str,input().split(" "))
	# 2K * 2K の座標サイズに圧縮。
	x = int(x) % (2*K)
	y = int(y) % (2*K)

	# Whiteの情報をBlackに変換
	if c == 'W':
		x += K
		x %= (2*K)

	arr[x][y] += 1
	arr[x+2*K][y] += 1
	arr[x][y+2*K] += 1
	arr[x+2*K][y+2*K] += 1


#累積和をとる。
for i in range(4*K):
	for j in range(4*K-1):
		arr[i][j+1] += arr[i][j]

for j in range(4*K):
	for i in range(4*K-1):
		arr[i+1][j] += arr[i][j]

ans = 0
tmp = 0
for i in range(1,2*K+1):
	for j in range(1,2*K+1):
		tmp = 0
		tmp += query(i,j,i+K-1,j+K-1)
		tmp += query(i+K,j+K,i+2*K-1,j+2*K-1)
		ans = max(tmp,ans)

print(ans)














