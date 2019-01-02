N = int(input())
point = 0
not10 = float('inf')
for i in range(N):
	s = int(input())
	point += s
	if s % 10 != 0:
		not10 = min(not10,s)


if point % 10 == 0:
	if not10 != float('inf'):
		point -= not10
	else:
		point = 0

print(point)
