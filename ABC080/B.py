N = input()

har = 0
for i in N:
	har += int(i)

if int(N) % har == 0:
	print("Yes")
else:
	print("No")