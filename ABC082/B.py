s = list(input())
t = list(input())

s.sort()
t.sort()
t.reverse()

for S,T in zip(s,t):
	if 'S' == 'T':
		continue

	elif ord(S) < ord(T):
		print("Yes")
		exit(0)

	elif ord(T) < ord(S):
		print("No") 
		exit(0)

if len(s) < len(t):
	print("Yes")

else:
	print("No")