N,D = map(int,input().split(" "))
X = list(map(int,input().split(" ")))

far_D = [0]*N
acc = [0]*N

#各都市に対する(右にD以上離れている都市数)を計算
for i in range(N):
	#二分探索
	lb = i
	ub = (N-1)
	bound = (N-1)
	while lb <= ub:
		mid = (lb + ub) //2
		if X[mid] - X[i] <= D:
			lb = mid + 1
			bound = mid
		else:
			ub = mid - 1

	#X_boundはギリギリD以内
	far_D[i] = (N - 1 - bound) #Dより離れてる数

	#累積和
	if i != 0:
		acc[i] = acc[i-1] + far_D[i]
	else:
		acc[0] = far_D[0]

pattern = 0
for i in range(N):
	# 1
	if far_D[i] >= 2:
		pattern += (far_D[i] * (far_D[i]-1) // 2)
	# 2
	bound = (N - 1 - far_D[i]) #ギリギリD以内
	pattern += (acc[bound] - acc[i])

	# 3
	if bound - i >= 2:
		pattern += ((bound-i)*(bound-i-1)//2)

total = (N*(N-1)*(N-2)//6)
print(total - pattern)
