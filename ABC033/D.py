from math import pi
from math import atan2 #atan2(y,x) := arctan(y/x)
from bisect import bisect_right
N = int(input())
eps = 1e-9
x = [0.0]* N
y = [0.0]* N
rad = [0.0] * (2 * (N-1))
right = 0
obtuse = 0

for i in range(N):
	x[i],y[i] = map(float,input().split(" "))

for i in range(N):
	k = 0
	for j in range(N):
		if i == j:
			continue
		rad[k] = atan2((y[j] - y[i]),(x[j] - x[i]))
		if rad[k] < 0:
			rad[k] += (2 * pi)
		k += 1
	for j in range(N-1):
		rad[j + (N-1)] = rad[j] + (2 * pi)
	rad.sort()
	for j in range(N-1):
		A = bisect_right(rad,rad[j] + (pi/2.0) - eps)
		B = bisect_right(rad,rad[j] + (pi/2.0) + eps)
		C = bisect_right(rad,rad[j] + (pi) - eps)
		right += (B - A)
		obtuse += (C - B)

total = (N * (N-1) * (N-2)) // 6
print(str(total-right-obtuse) + " " + str(right) + " " + str(obtuse)) 
