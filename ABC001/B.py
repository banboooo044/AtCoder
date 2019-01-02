#! /usr/bin/env python3
# -*- coding: utf-8 -*-

m = int(input())

if m < 100:
	V = 0
elif 100 <= m and m <= 5000:
	V = m / 100
elif 6000 <= m and m <= 30000:
	V =  (m / 1000) + 50
elif 35000 <= m and m <= 70000:
	V = ((m / 1000) - 30) / 5 + 80
elif 70000 < m:
	V = 89


if (float(V)/10) < 1:
	print("0"+str(int(V)))
else:
	print(int(V))

