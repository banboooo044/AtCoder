N = int(input())
a = list(map(int,input().split(" ")))
l = (-1)
r = 0
cnt = 0
while True:
	while r < N and a[r-1] < a[r]:
		r += 1

	cnt += (r - l)
	if r >= (N):
		break

	if l == r:
		
	l += 1