H,W = map(int,input().split(" "))
S = [[0] * W for _ in range(H)]
dic = {}
for i in range(H):
	S[i] = list(input())
	for j in range(W):
		if S[i][j] in dic:
			dic += 1
		else:
			dic = 1


