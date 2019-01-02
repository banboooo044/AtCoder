#! usr/bin/env python3
# -*- coding:utf-8 -*-

#感雨時刻の整理
#解説1の sort & merge 

time =[]

N = int(input())


#データ作り。リストtime[]に[開始時間,終了時間]を値を丸めて格納した。
for i in range(N):
	S,E = map(int,input().split("-"))

	cut = list(map(int,str(S)))
	if cut[-1] > 5:
		S = S - (cut[-1] - 5)
	elif cut[-1] == 0:
		pass
	elif cut[-1] < 5:
		S = S - cut[-1]

	cut = list(map(int,str(E)))

	if cut[-1] > 5:
		#下2桁は60で繰り上がり <---ずっとバグってた。
		if len(cut) > 1 :
			if cut[-2] == 5:
				E = E + 50 - cut[-1]
			else:
				E = E + (10 - cut[-1])

		else:
			E = E + (10 - cut[-1])

	elif cut[-1] == 0:
		pass

	elif cut[-1] < 5:
		E = E + (5 - cut[-1])

	time.append([S,E])

#開始時刻でsortする。
time.sort(key=lambda x:x[0])

def merge(pair1,pair2):
	if pair1[1] < pair2[0]:
		return 1
	elif pair1[1] >= pair2[1]:
		return 2
	else:
		return 3

i = 0
count = len(time) - 2

while(True):

	if i > count :
		break

	sign = merge(time[i],time[i+1])

	if sign == 1:
		i += 1

	elif sign == 2:
		del time[i+1]
		count -= 1

	elif sign == 3:
		time[i] = [time[i][0],time[i+1][1]]
		del time[i+1]
		count -= 1

#表示
for pair in time:
	print(str(pair[0]).zfill(4) + "-" + str(pair[1]).zfill(4))






