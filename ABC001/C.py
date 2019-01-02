#! /usr/bin/env python3
# -*- coding: utf-8 -*-

def myround(num,digits):
	tmp = int(num * (10 ** digits) + 0.01)
	numList = list(map(int,str(tmp)))
	if numList[-1] >= 5:
		tmp += 10
	tmp = int(tmp / 10)
	num = float(tmp) / (10 ** (digits-1))
	return num
	



	

Deg,Dis  = map(float,input().split(" "))

dirList = ["NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"]
ceil_speed = [2,15,33,54,79,107,138,171,207,244,284,326]

floar = 1125
ceil = 3375

Dir = 'N'

#Dirの生成

Deg *= 10
Deg = int(Deg)


for direc in dirList:
	if (floar <= Deg) and (Deg < ceil) :
		Dir = direc
		break
	else:
		floar = ceil
		ceil += 2250

floar = 0

W = 12
Dis /= 60
Dis = myround(Dis,2)
Dis *= 10
Dis = int(Dis)

for i , ceil in zip(range(12),ceil_speed):
	if (floar <= Dis) and (Dis <= ceil):
		W = i
		break
	else:
		floar = ceil + 1

if W == 0:
	Dir = 'C'

print(Dir + " " + str(W))













