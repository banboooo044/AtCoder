from itertools import combinations
N = int(input())
S = input()
cnt = 0
for tup in combinations(range(N*2),N):
	s1 = ""
	s2 = ""
	for k in range(N*2):
		if k in tup:
			s1 += S[k]
		else:
			s2 += S[k]
	if s1 == s2[::-1]:
		cnt += 1

print(cnt)
