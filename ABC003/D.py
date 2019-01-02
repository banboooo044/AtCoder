R,C = map(int,input().split(" "))
X,Y = map(int,input().split(" "))
D,L = map(int,input().split(" "))

mod = 1000000007
def nCr(n,r):
	if n < 0 or r < 0 or n < r:
		return 0
	upper,lower = 1,1
	for i in range(r):
		upper *= (n-i)
		lower *= (r-i)
	return int(upper//lower)

def cal(x,y):
	if x < 0 or y < 0:
		return 0 # x < 0 ,y < 0 の場合コーナーケース
	return nCr(x*y,D) * nCr((x*y)-D,L)

seg_pat = (R - X + 1)*(C - Y + 1) # 区画X*Yがいくつ取れるか
pat = cal(X,Y) - ((cal(X-1,Y)+cal(X,Y-1))*2) + (cal(X-2,Y) + cal(X,Y-2) + cal(X-1,Y-1)*4) \
- ((cal(X-1,Y-2)+cal(X-2,Y-1))*2) + (cal(X-2,Y-2)) #包除原理

print((seg_pat*pat)%mod)
