#! usr/bin/env python3

# D:派閥
# 解法2:深さ優先探索

rel = {}

N,M = map(int,input().split(" "))

for i in range(1,N+1):	
	rel[i] = []

for i in range(M):
	x,y = map(int,input().split(" "))
	rel[x].append(y)
	rel[y].append(x)