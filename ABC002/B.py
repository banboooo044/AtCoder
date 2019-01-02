#! usr/binm/env python3
# -*- coding:utf-8 -*-

#B:罠

W = input()

W_list = list(W)

while True:
	if 'a' in W_list:
		W_list.remove('a')
	else:
		break

while True:
	if 'i' in W_list:
		W_list.remove('i')
	else:
		break

while True:
	if 'u' in W_list:
		W_list.remove('u')
	else:
		break

while True:
	if 'e' in W_list:
		W_list.remove('e')
	else:
		break

while True:
	if 'o' in W_list:
		W_list.remove('o')
	else:
		break

for ch in W_list:
	print(ch,end='')

print("")

