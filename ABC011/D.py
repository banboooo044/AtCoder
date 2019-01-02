N,D = map(int,input().split(" "))
X,Y = map(int,input().split(" "))

if X % D != 0 or Y % D != 0:
	print(0.0)
	exit(0)

def nCr(n,r):
	upper,lower = 1,1
	for i in range(r):
		upper *= (n-i)
		lower *= (r-i)
	return (upper//lower)

pattern = 0
X,Y = abs(X)//D,abs(Y)//D
#横移動の数を列挙。
for lr in range(X,N+1): 
	ud = N - lr
	if ud < Y:
		break

	if (lr - X)%2 == 1 or (ud - Y)%2 == 1: #ゴールに着かない
		continue

	x_re,y_re = (lr - X)//2,(ud - Y)//2    #元の位置に戻る余分な1手の数(左右,上下)

	pattern += (nCr(N,min(lr,ud))*nCr(lr,x_re)*nCr(ud,y_re))
	# nCr(N,min(lr,ud)) : N回の移動中lr回左右,ud回上下に移動する組み合わせ
	# nCr(lr,x_re) : lr回の左右移動のうち、何回ゴールと逆方向に動く移動の組み合わせ。
	# nCr(ud,y_re) : 上に同じ

print(pattern/(4**N))


