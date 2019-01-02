b1 = list(map(int,input().split(" ")))
b2 = list(map(int,input().split(" ")))
sumv = sum(b1) + sum(b2)
b = [b1,b2]
c1 = list(map(int,input().split(" ")))
c2 = list(map(int,input().split(" ")))
c3 = list(map(int,input().split(" ")))
sumv += sum(c1) + sum(c2) + sum(c3)
c = [c1,c2,c3]
board = [0]*9 #盤面
memo = {} #メモ
def min_max(turn,tup):
	if turn == 9:
		return cal_score()
	if tup in memo:
		return memo[tup]

	else:
		ret_score = -float('inf')
		flg = (-1) if turn % 2 else 1
		h = tuple(board)
		for i in range(9):
			if board[i] == 0:
				board[i] = flg
				ret_score = max(ret_score,flg*min_max(turn+1,h))
				board[i] = 0

		memo[h] = flg*ret_score
		return flg*ret_score

def cal_score():
	score = 0
	for i in range(2):
		for j in range(3):
			if board[i*3+j] == board[(i+1)*3+j]:
				score += b[i][j]
			if board[j*3+i] == board[j*3+i+1]:
				score += c[j][i]
	return score #直大のスコア

chokudai = min_max(0,tuple())
print(memo)
print(chokudai)
print(sumv - chokudai)