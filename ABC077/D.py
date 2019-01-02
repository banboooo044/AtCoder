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
            return di,pathi

        #辺を全部見る
        for vertex, weight in E[v].items():
            new_di = di + weight
            if (new_di < dist[vertex]) or (new_di == dist[vertex] and pathi + (vertex, ) < path[vertex]):
                dist[vertex] = new_di
                path[vertex] = pathi + (vertex, )
                heapq.heappush(pq, (new_di, path[vertex]))

K = int(input())
E = [dict() for _ in range(K)]

for i in range(K-1):
    E[i][i+1] = 1
    E[i][((i * 10) % K)] = 0

E[K-1][0] = 1
E[(K-1)][((K-1)*10)%K] = 0

ans,path = dijkstra(K,1,0,E)

print(ans+1)