#! usr/bin/env python3

#A:atcorderの給料

N = int(input())

num = 0

for i in range(1,N+1):
	num += i

print(int(num * 10000 / N + 0.001))
