#! usr/bin/env python3

#D: Yet Another Palindrome Partitioning

#誤回答

def is_kaibun (S):
	#戻り値が0:回文,1:回文無理
	l = len(S)
	S.sort()

	i = 0


	if l % 2 == 1:
		sign = 0
		
		while True:
			if i >= l-1:
				return 0
			elif S[i] == S[i+1]:
				i += 2
			else:
				if sign == 1:
					return 1
				else:
					sign += 1
					i += 1

	else:
		while True:
			if i >= l-1:
				return 0
			elif S[i] == S[i+1]:
				i += 2
			else:
				return 1



	

def is_kaibun3(S):
	if (S[0] == S[1]) or (S[0] == S[2]) or (S[1] == S[2]):
		return 0
	else:
		return 1



S = list(input())
devide = 0


def maxkaibun(S,front,last):
	global devide 
	i = len(S)

	for length in range(i,0,-1):
		for start in range(i-length+1):
			if length  == 1:
				devide += i
				return 0 

			elif length == 2:
				if S[start] == S[start+1]:

					if (front == start) or ((start+length+1) == last):
						return 0

					maxkaibun(S[front:start],front,start)
					maxkaibun(S[start+length+1:last],start+length+1,last)
					return 0

			elif length == 3:
				if (is_kaibun3(S[start:start+length+1]) == 0):
					devide += 1
				
					if (front == start) or ((start+length+1) == last):
						return 0

					maxkaibun(S[front:start],front,start)
					maxkaibun(S[start+length+1:last],start+length+1,last)
					return 0

			if (is_kaibun(S[start:start+length+1]) == 0):
				devide += 1

				if (front == start) or ((start+length+1) == last):
					return 0

				maxkaibun(S[front:start],front,start)
				maxkaibun(S[start+length+1:last],start+length+1,last)
				return 0

maxkaibun(S,0,len(S))
print(devide)
				

