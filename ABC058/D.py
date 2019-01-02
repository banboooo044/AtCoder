n,m = map(int,input().split(" "))
X = list(map(int,input().split(" ")))
Y = list(map(int,input().split(" ")))
mod = (10 ** 9) + 7

sum_x = sum_y = 0

l = 0
r = (n-1)

while l < r:
	sum_x += ((r-l) * abs(X[r] - X[l]))
	r -= 1
	l += 1

l = 0
r = (m-1)
while l < r:
	sum_y += ((r-l) * abs(Y[r] - Y[l]))
	r -= 1
	l += 1

print((sum_x*sum_y) % mod)
