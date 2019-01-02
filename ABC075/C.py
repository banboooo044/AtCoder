#! /usr/bin/env python3
# -*- coding: utf-8 -*-

N,M = map(int,input().split(" "))
ans = N - 1

line = {}
double = {}

for i in range(1,N+1):
	line[i] = [i,i]
	double[i] = 0


for i in range(M):
	a,b = map(int,input().split(" "))
	double[a] += 1
	double[b] += 1
	if (b - line[b][0]) < (b - a):
		line[b][0] = a
	if (line[a][1] - a) < (b - a):
		line[a][1] = b 


if N-1 == M :
	print(N-1)
	exit(0)

for i in double.items():
	if i[1] >= 3:
		if double[line[i[0]][0]] >= 3:
			ans -= i[0] - line[i[0]][0]
			double[line[i[0]][0]] -= 1

		else:
			ans -= line[i[0]][1] - i[0]
			double[line[i[0]][1]] -= 1



print(ans)













