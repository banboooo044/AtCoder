#! /usr/bin/env python3
# -*- coding: utf-8 -*-
def decision(a,b,Q):
	if a == b:
		return 0

	ans = input("? "+ a + " " + b +"\n")
	Q -= 1

	if (ans == '<'):
		return 1
	else:
		return 0


def quick_sort(List,Q,left,right):
	
	
	i = left
	j = right

	if (left+right)%2 == 1:
		pivot = List[int((left+right+1)/2)]
	else:
		pivot = List[int((left+right)/2)]

	while(True):

		if i >= j:
			break

		if Q == 0:
			exit(1)

		while(decision(List[i],pivot,Q) == 1):
			i += 1
			if i >= j:
				break
			if Q == 0:
				exit(1)


		while(decision(pivot,List[j],Q) == 1):
			j -= 1
			if i >= j:
				break
			if Q == 0:
				exit(1)

		if i >= j:
			break

		List[i],List[j] = List[j],List[i]

		i += 1
		j -= 1

	#途中経過表示

	if left < (i-1):
		quick_sort(List,Q,left,i-1)

	if right > (j+1):
		quick_sort(List,Q,j+1,right) 
	

N,Q = map(int,input().split(" "))
charset = [chr(i) for i in range(65, 65+26)]
useset = charset[0:N]
quick_sort(useset,Q,0,N-1)
print ("! ",end='',flush=True)
for char in useset :
	print(char,end='',flush=True)


exit(0)


#クイックソートでの実実装。同じ質問が出てきてしまい、クエリを制限するプログラムでは非効率。