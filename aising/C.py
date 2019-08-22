H,W = map(int,input().split(" "))
S = [""]*H
for i in range(H):
    S[i] = input()


for h in range(H):
    for w in range(W):
        for dx,dy in zip([0,1,0,-1],[1,0,-1,0]):
            if (h + dy) < 0 or (h + dy) >= H or (w + dx) < 0 or (w + dx) >= W:
                continue
            else:
                if S[h][w] == '.' and S[h+dy][w+dx] == '#':
                    if S[h][w]    
                elif S[h][w] == '#' and S[h+dy][w+dx] == '.':
