s = input()
ans = ""
for i in range(len(s)-1):
	if s[i] == s[i+1]:
		ans = str(i+1) + " " + str(i+2)

if ans != "":
	print(ans)
	exit(0)

for i in range(len(s)-2):
	if s[i] == s[i+2]:
		ans = str(i+1) + " " + str(i+3)

if ans == "":
	print("-1 -1")
else:
	print(ans)