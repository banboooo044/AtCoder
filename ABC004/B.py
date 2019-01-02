#! usr/bin/env python3

#B:回転
import sys

xy = []
for i in range(4):
	C = input().split(" ")
	C.reverse()
	xy.append(C)

xy.reverse()

for i in range(4):
	for j in range(4):
		sys.stdout.write(xy[i][j])
		sys.stdout.write(" ")
	print("")



