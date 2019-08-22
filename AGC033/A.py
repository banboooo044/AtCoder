import heapq
H, W = map(int,input().split(" "))
A = [""] * H
used = [ [ -1 ]*W for _ in range(H) ]
que = []
for i in range(H):
    A[i] = input()
    for j in range(W):
        if A[i][j] == '#':
            heapq.heappush(que,(0,i,j))
            used[i][j] = 0

while que != []:
    d, i, j = heapq.heappop(que)
    if i > 0 and used[i-1][j] == -1:
        used[i-1][j] = d+1
        heapq.heappush(que,((d+1,i-1,j)))
    if i < H-1 and used[i+1][j] == -1:
        used[i+1][j] = d+1
        heapq.heappush(que,((d+1,i+1,j)))
    if j > 0 and used[i][j-1] == -1:
        used[i][j-1] = d+1
        heapq.heappush(que,((d+1,i,j-1)))
    if j < W-1 and used[i][j+1] == -1:
        used[i][j+1] = d+1
        heapq.heappush(que,((d+1,i,j+1)))

print(max(list(map(lambda x: max(x),used))))