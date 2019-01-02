H,W = map(int,input().split(" "))
N = int(input())
a = list(map(int,input().split(" ")))

grid = [[0]*W for _ in range(H)]
grid_iter = [0,0]
for i in range(N):
	for j in range(a[i]):
		grid[grid_iter[1]][grid_iter[0]] = i+1

		if grid_iter[0] == 0 and grid_iter[1] % 2 == 1:
			grid_iter = [0,grid_iter[1]+1]

		elif grid_iter[0] == W-1 and grid_iter[1] % 2 == 0:
			grid_iter = [W-1,grid_iter[1]+1]

		else:
			if grid_iter[1] % 2 == 1:
				grid_iter[0] -= 1
			else:
				grid_iter[0] += 1

for i in range(H):
	for j in range(W):
		print(str(grid[i][j]) + " ",end = "")
	print()




