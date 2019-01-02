#! usr/bin/env python3
# -*- coding:utf-8 -*-

#感雨時刻の整理
#解説3のイモス法

N = int(input())
#配列の初期化
array = [0] * (12 * 24 + 1) 

ans = []

for i in range(N):
	S,E = map(int,input().split("-"))
	ad_S = (S // 100 * 12)  + ((S % 100) // 5) 
	ad_E = (E // 100 * 12)  + ((E % 100) // 5) 

	array[ad_S] += 1

	if E == 0:
		array[ad_E+1] += -1
	elif E % 5 == 0:
		array[ad_E] += -1

	else:
		array[ad_E+1] += -1


for i in range(1,12*24):
	array[i] += array[i-1]

count = 0

if array[0] >= 1:
	S = 0

for i in range(12*24-1):
	if (array[i] <= 0) and (array[i+1] >= 1):
		S = ((i+1) // 12)*100 + ((i+1) % 12) * 5

	if (array[i] >= 1) and (array[i+1] <= 0):
		E = ((i+1) // 12)*100 + ((i+1) % 12)*5
		ans.append([S,E])
		

if array[12*24-1] >= 1:
	ans.append([S,2400])

for pair in ans:
	print(str(pair[0]).zfill(4) + "-" + str(pair[1]).zfill(4))






 








