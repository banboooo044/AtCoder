R, C =  map(int,input().split(" "))
sy, sx = map(int,input().split(" "))
gy, gx = map(int,input().split(" "))

sx -= 1
sy -= 1
gy -= 1
gx -= 1
c = []
for i in range(R):
    c.append(input())
used = [ [0]*C for _ in range(R) ]
used[sy][sx] = 1
que = [ (sx, sy, 0 )]
while len(que) > 0:
    tmpQueue = []
    for x,y,d in que:
        if x == gx and y == gy:
            print(d)
            exit(0)
        for dx,dy in [ (0,1),(0,-1),(1,0),(-1,0)]:
            if 0 <= y+dy < R and 0 <= x+dx < C and c[y+dy][x+dx] != '#' and used[y+dy][x+dx] != 1:
                tmpQueue.append(( x+dx, y+dy, d+1))
                used[y+dy][x+dx] = 1
    que = tmpQueue