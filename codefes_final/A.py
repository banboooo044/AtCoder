# A問題
S = input() 
if((not S in "AKIHABARA") and (not S in "AKIHBARA") and (not S in "AKIHBRA") and (not S in "AKIHABRA")):
	print("NO")
	exit(0)


string =  ""
count = 0

for i in S:
	if i != 'A':
		string += i


if string == "KIHBR":
	print("YES")

else:
	print("NO")
