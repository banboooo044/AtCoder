#! /usr/bin/env python3
# -*- coding: utf-8 -*-

#interactive_sorting

def decision(a,b):
	ans = input("? "+ a + " " + b +"\n")

	if (ans == '<'):
		return 1
	else:
		return 0


def insert_sort(List,Q):
	for i in range(N-1):

		if Q == 0:
			exit(1)
		Q -= 1
		

		if decision(List[i],List[i+1]) == 1:
			continue

		else:
			if i == 0:
				List[0],List[1] = List[1],List[0]
				continue

			j = i - 1

			if Q == 0:
				exit(1)
			Q -= 1
			

			while  decision(List[j],List[i+1]) == 0:
				if j == 0:
					List[0],List[i+1] = List[i+1],List[0]
					break
				else:
					if Q == 0:
						exit(1)
					Q -= 1
					j -= 1  

			for tmp in range(j+1,i+1):
				List[tmp],List[i+1] = List[i+1],List[tmp]
	return List



	

N,Q = map(int,input().split(" "))
charset = [chr(i) for i in range(65, 65+26)]
useset = charset[0:N]
result = insert_sort(useset,Q)
print ("! ",end='',flush=True)
for char in useset :
	print(char,end='',flush=True)

exit(0)


#挿入ソートでソートを行なった。
#テストケース1 N=26 Q=1000 は通った
#テストケース2 N=26 Q=100  は通らなかった
#挿入ソートではクエリの数が最大 1+2+...+25になるため、明らかに100を超えるためであると考えられる。

#他のソートアルゴリズムで試すべき。
#バブルソートも同じ計算量で書き方は簡潔に済むので、こちらを採用したい。

