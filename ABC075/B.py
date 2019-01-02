#! /usr/bin/env python3
# -*- coding: utf-8 -*-

H,W = map(int,input().split(" "))

mat = []
bomb = []
for i in range(H):
	S = list(input())

	for val,j in zip(S,range(W)):
		if val == '#':
			bomb.append((i,j))
		else:
			S[j] = 0

	mat.append(S)


def rep (i,j,mat,H,W):
	for k in [i-1,i,i+1]:
		for l in [j-1,j,j+1]:

			if (k < 0) or (k > (H-1)) or (l < 0) or (l > (W-1)):
				continue

			if mat[k][l] == '#':
				continue
			else:
				mat[k][l] += 1

for t in bomb:
	rep(t[0],t[1],mat,H,W)

for i in range(H):
	for j in range(W):
		print(mat[i][j],end="")
	print("")
	


