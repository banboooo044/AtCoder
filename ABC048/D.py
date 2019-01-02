s = input()

if s[0] == s[-1]:
	flg = 1
else:
	flg = 0

if len(s) % 2 == 0:
	flg += 1

if (flg % 2 == 1):
	print("Second")
else:
	print("First")
