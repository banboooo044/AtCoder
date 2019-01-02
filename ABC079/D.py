import heapq

def dijkstra(N,start, goal, E):
    """最短距離,経路を返すプログラム"""
    dist = [float('inf')] * N          #dist[i]:始点からの距離
    path = [tuple() for n in range(N)] #path[i]:(start,...,i)までの経路をカンマで区切ったもの
    dist[start] = 0
    path[start] = (start, )            
    pq = [(0, path[start])]

    while pq:
        di, pathi = heapq.heappop(pq)
        v = pathi[-1]

        if v == goal:
            return di

        #辺を全部見る
        for vertex, weight in E[v].items():
            new_di = di + weight
            if (new_di < dist[vertex]) or (new_di == dist[vertex] and pathi + (vertex, ) < path[vertex]):
                dist[vertex] = new_di
                path[vertex] = pathi + (vertex, )
                heapq.heappush(pq, (new_di, path[vertex]))



N = 10
H,W = map(int, input().split())
E = [dict() for i in range(10)]
ans = 0n

tank = [0] * 10
for i in range(10):
    tmp = list(map(int,input().split(" ")))
    for j in range(10):
        E[i][j] = tmp[j]

for i in range(H):
    A = list(map(int,input().split(" ")))
    for j in range(W):
        if abs(A[j]) != 1:
            if tank[A[j]] == 0: 
                tank[A[j]] = dijkstra(N,A[j],1,E)

            ans += tank[A[j]]

print(ans)

