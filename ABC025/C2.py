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
def alpha_beta(turn,tup,alpha,beta):
	if turn == 9:
		return cal_score()
	else:
		al,be = alpha,beta
		flg = 1 if turn % 2 else (-1)
		ret_score = float('inf') if turn % 2 else -float('inf')
		h = tuple(board)
		for i in range(9):
			if board[i] == 0:
				board[i] = flg
				val = alpha_beta(turn+1,h,al,be)
				if turn % 2:
					if al >= val:
						ret_score = -float('inf')
						board[i] = 0
						break
					else:
						ret_score = min(val,ret_score)
						be = min(ret_score,be)
				else:
					if be <= val:
						ret_score = float('inf')
						board[i] = 0
						break
					else:
						ret_score = max(val,ret_score)
						al = max(al,ret_score)
				board[i] = 0

		return ret_score

def cal_score():
	score = 0
	for i in range(2):
		for j in range(3):
			if board[i*3+j] == board[(i+1)*3+j]:
				score += b[i][j]
			if board[j*3+i] == board[j*3+i+1]:
				score += c[j][i]
	return score #直大のスコア

chokudai = alpha_beta(0,tuple(),-float('inf'),float('inf'))
print(chokudai)
print(sumv - chokudai)