#! usr/bin/env python3

#B:atcorderトランプ

replace = ['a','t','c','o','r','d','e']

S = list(input())
T = list(input())

i =  0
length = len(S)


def match (ch):
	for i in replace:
		if i == ch:
			return 0
	
	return 1


while True:
	if i > length - 1:
		break

	if (S[i] != T[i]):
		if (S[i] == '@'):
			if match(T[i]) == 1:
				print("You will lose")
				exit(0)
			else:
				i += 1

		elif (T[i] == '@'):
			if match(S[i]) == 1:
				print("You will lose")
				exit(0)
			else:
				i += 1

		else:
			print("You will lose")
			exit(0)

	else:
		i += 1

print("You can win")






		
