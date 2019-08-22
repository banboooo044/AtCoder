import heapq as pq
N,K = map(int,input().split(" "))
priority_que = []
t,d= [0]*N,[0]*N
sushi_max = [-1] * N
cnt = [0] * N

for i in range(N):
    t[i],d[i] = map(int,input().split(" "))
    sushi_max[t[i]-1] = max(sushi_max[t[i]-1],d[i])

t ,d= zip(*sorted(zip(t,d),reverse=True,key=lambda x: x[1]))
ans = 0
for i in range(K):
    cnt[t[i]-1] += 1
    sushi_max[t[i]-1] = -1
    pq.heappush(priority_que,(d[i],t[i]))
    ans += d[i]

sz = len(list(filter(lambda x: x > 0,cnt)))
ans += (sz * sz)

sushi_max = sorted([ (val,idx) for idx,val in enumerate(sushi_max) ],reverse=True,key=lambda x:x[0])
idx = 0
cur = ans
while len(priority_que) > 0 and sushi_max[idx][0] != -1:
    minValue,minIdx = pq.heappop(priority_que)
    if cnt[minIdx-1] == 1:
        continue
    cur += ( (sz+1)*(sz+1) - (sz*sz) + sushi_max[idx][0] - minValue )
    cnt[minIdx-1] -= 1
    sz += 1
    idx += 1
    ans = max(cur,ans)
print(ans)
