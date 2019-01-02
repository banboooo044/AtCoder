#! usr/bin/env python3
#C:入れ替え
import sys

def swap(i,j):
	global num
	tmp = num[i]
	num[i] = num[j]
	num[j] = tmp

	
N = int(input())
N = N % 30
num = list("123456")

for l in range(N):
	i = l % 5
	swap(i,i+1)



for k in num:
	sys.stdout.write(k)

print("")




