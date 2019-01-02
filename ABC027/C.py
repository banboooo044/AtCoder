N = int(input())
m = 1
num = 2
cnt = 0
minv = 1
maxv = 1
while m <= N:
	minv = (2 * minv) + 1 if cnt % 2 else 2 * minv
	maxv = 2 * maxv if cnt % 2 else (2 * maxv) + 1
	m += num
	num += num
	cnt += 1

if cnt % 2:
	if minv <= N:
		print("Takahashi")
	else:
		print("Aoki")
else:
	if maxv <= N:
		print("Aoki")
	else:
		print("Takahashi")