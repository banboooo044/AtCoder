#! usr/bin/env python3
#D:Atcoder Express
#TLEシテシマッタ
from collections import deque

N = int(input())

gragh = deque([])
tmp = deque([0])

t = list(map(int,input().split(" ")))
v = list(map(int,input().split(" ")))

for i in range(1,N):
	t[i] += t[i-1]
t.insert(0,0)

sumt = t[-1]

for i in range(1,sumt+1):
	tmp.append(0.5*i)

gragh.extend(tmp)
tmp.pop()
tmp.reverse()
gragh.extend(tmp)


for j in range(N):
	for i in range(1,sumt*2+1):
		if t[j]*2 > i:
			tmp = (t[j]+v[j]-0.5*i)
			if gragh[i] > tmp:
				gragh[i] = tmp
		elif t[j]*2 <= i <= (t[j+1]*2) :
			if gragh[i] > v[j]:
				gragh[i] = v[j]
		else:
			tmp = (v[j]+0.5*(i-t[j+1]*2))
			if gragh[i] > tmp:
				gragh[i] = tmp

for i in range(sumt*2+1):
	print("gragh[" + str(i) + "] = " + str(gragh[i]))

val = 0
for i in range(sumt*2):
	if gragh[i] != gragh[i+1]:
		val += ((gragh[i]+gragh[i+1]) * 0.25)
	else:
		val += ((gragh[i]) * 0.5)


print(val)


	
