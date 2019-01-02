#! /usr/bin/env python3
# -*- coding: utf-8 -*-

N = int(input())
a_list = []
b_list = []

for i in range(N):
	A,B = map(int,input().split(" "))

	a_list.append((A,B))

a_list.sort()

print(a_list[-1][1] + a_list[-1][0])
