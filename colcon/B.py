N,X = map(int,input().split(" "))
S = input()
ans = 0
for i in range(N):
	T = int(input())
	if S[i] == '0':
		ans += T
	else:
		ans += (min([T,X]))

print(ans)
	
