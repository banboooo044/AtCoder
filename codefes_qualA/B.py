#! /usr/bin/env python3
# -*- coding: utf-8 -*-

N,M,K = map(int,input().split(" "))

tureList = []

for i in range(N+1):
	for j in range(M+1):
		tureList.append((i*M) + (j*N) - 2*(i*j))

if K in tureList:
	print("Yes")

else:
	print("No")