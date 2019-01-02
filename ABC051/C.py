sx,sy,tx,ty = map(int,input().split(" "))
dx = ['R','L']
dy = ['U','D']

ans = dx[0] * (tx-sx) + dy[0] * (ty - sy)
ans += dx[1] * (tx-sx) + dy[1] * (ty - sy)
ans += (dy[1] + dx[0] * (tx-sx+1) + dy[0] * (ty - sy + 1) + dx[1])
ans += (dy[0] + dx[1] * (tx-sx+1) + dy[1] * (ty - sy + 1) + dx[0])

print(ans)