
H, W = map(int,input().split(" "))
c = [ ]
sx,sy = -1,-1
for i in range(H):
    c.append(input())
    for j in range(W):
        if c[i][j] == 's':
            sx = j
            sy = i

used = [ [0]*W for _ in range(H) ]
def dfs(i, j):
    if c[i][j] == 'g':
        print("Yes")
        exit(0)
    for dx,dy in [ (0,1),(0,-1),(1,0),(-1,0)]:
        if 0 <= i+dy < H and 0 <= j+dx < W and c[i+dy][j+dx] != '#' and used[i+dy][j+dx] != 1:
            used[i+dy][j+dx] = 1
            dfs(i+dy,j+dx)

dfs(sy,sx)
print("No")
