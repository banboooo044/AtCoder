N = int(input())
a = list(map(int,input().split(" ")))

MAX = max(a)
MIN = min(a)

count = 0
ans = []

def showans():
	global count
	global ans
	print(count)
	for i,j in ans:
		print(str(i) + " " + str(j))


def allplus():
	global count
	global ans
	for i in range(N-1):
		if a[i] > a[i+1]:
			a[i+1] += a[i]
			count += 1
			ans.append((i+1,i+2))

			

def allminas():
	global count
	global ans
	for i in range(N-1,0,-1):
		if a[i] < a[i-1]:
			a[i-1] += a[i]
			count += 1
			ans.append((i+1,i))


if abs(MAX) >= abs(MIN) and MAX > 0:
	ind = a.index(MAX)
	for i in range(N):
		if a[i] < 0:
			while a[i] < 0:
				a[i] += MAX
				count += 1
				ans.append((ind+1,i+1))

	allplus()
	showans()
	exit(0)

elif abs(MIN) > abs(MAX) and MIN < 0:
	ind = a.index(MIN)
	for i in range(N):
		if a[i] > 0:
			while a[i] > 0:
				a[i] += MIN
				count += 1
				ans.append((ind+1,i+1))

	allminas()
	showans()
	exit(0)

elif MAX <= 0:
	allminas()
	showans()

elif MIN >=  0:
	allplus()
	showans()