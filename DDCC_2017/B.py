#! /usr/bin/env python3
# -*- coding: utf-8 -*-

N = int(input())
D = input().split(" ")
M = int(input())
T = input().split(" ")


if len(D) < len(T):
	print("NO")
	exit(0)

D.sort()
T.sort()

i = 0
j = 0

while True:
	if i > M-1:
		print("YES")
		break

	elif D[j] == T[i] :
		i += 1
		j += 1

	else:
		j += 1

		if j > N - 1:
			print("NO")
			break

		elif D[j] > T[i]:
			print("NO")
			break





