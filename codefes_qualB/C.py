#! /usr/bin/env python3
# -*- coding: utf-8 -*-

N,C = map(int,input().split(" "))

L = []
num = range(N)

for i in num:
	a = int(input())
	L.append(a)

L.sort()

i = 0
j = N-1
count = 0

while True:
	if(L[i] + L[j] + 1 <= C):
		j -= 1
		i += 1
	else:
		j -= 1

	count += 1

	if i==j:
		count += 1
		break

	if i > j:
		break
print(count)


