#! /usr/bin/env python3
# -*- coding: utf-8 -*-

H,W = map(int,input().split(" "))
A,B = map(int,input().split(" "))

xy = []
xy_2 = []

for i in range(H):
	a = input()
	b = list(a)
	for j in range(W):
		if (b[j] == 'S'):
			xy.append((i,j))

num = len(xy)

point = A + B


def y (xy,num):
	count = 0

	for i in range(num):
		for j in range(i,num):
			if xy[i][0] == xy[j][0] and ((W + 1 - xy[i][1]) == xy[j][1]):
				count += 1

	return count

def x (xy,num):
	count = 0

	for i in range(num):
		for j in range(i,num):
			if xy[i][1] == xy[j][1] and ((H + 1 - xy[i][0]) == xy[j][0]):
				count += 1

	return count


count_x = x(xy,num)
count_y = y(xy,num)

print(A*count_x + B*count_y + point)


