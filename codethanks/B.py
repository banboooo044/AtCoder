# B問題
S = input()

count = 1
T = S[:]
while True:
	if T == T[::-1]:
		break

	else:
		K = S[0:count]
		T = S[:]
		count += 1
		T += K[::-1]

print(count-1)

