#! usr/bin/env python3
#B:

N = int(input())

A = list(map(int,input().split(" ")))

count = 1

for i in A:
	if i % 2 == 0:
		count *= 2
	else:
		pass

ans = (3 ** len(A)) - count

print(ans)