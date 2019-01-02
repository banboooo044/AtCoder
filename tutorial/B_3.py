#! /usr/bin/env python3
# -*- coding: utf-8 -*-
def decision(a,b,Q):
	if Q == 0:
		exit(0)

	ans = input("? "+ a + " " + b +"\n")
	Q -= 1

	if (ans == '<'):
		return 1
	else:
		return 0


def merge_sort(List,tmp,array_size,Q):
	m_sort(List,tmp,0,array_size-1,Q)

def m_sort(List,tmp,left,right,Q):

	if right > left :
		mid = (right + left) / 2
		mid = int(mid)

		m_sort(List,tmp,left,mid,Q)
		m_sort(List,tmp,mid+1,right,Q)

		merge(List,tmp,left,mid+1,right,Q)

def merge(List,tmp,left,mid,right,Q):

	left_end = mid - 1
	tmp_pos = left
	num_elements = right - left + 1

	while (left <= left_end ) and (mid <= right):
  		if decision(List[left],List[mid],Q) == 1:
  			tmp[tmp_pos] = List[left]
  			left += 1
  			tmp_pos += 1
  		else:
  			tmp[tmp_pos] = List[mid]
  			mid += 1
  			tmp_pos += 1

	while (left <= left_end):
  		tmp[tmp_pos] = List[left]
  		left += 1
  		tmp_pos += 1

	while (mid <= right):
  		tmp[tmp_pos] = List[mid]
  		mid += 1
  		tmp_pos += 1

  	#tmpの変更部分とListの置き換え。rightからnum_element分置き換えるのが意外と重要

	for i in range(num_elements):
		List[right] = tmp[right]
		right -= 1 

N,Q = map(int,input().split(" "))
charset = [chr(i) for i in range(65, 65+26)]
useset = charset[0:N]

tmp = []

for i in range(N):
	tmp.append(0)

merge_sort(useset,tmp,N,Q)

print ("! ",end='',flush=True)
for char in useset :
	print(char,end='',flush=True)
exit(0)


#マージソートを用いた。200点解答
#マージソートでも3つ目の壁は破れないことを考えると、