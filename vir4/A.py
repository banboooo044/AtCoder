N = int(input())
cnt = [0] * 100002
for i in range(N):
    l,r = map(int,input().split(" "))
    cnt[r+1] -= 1
    cnt[l] += 1
ans = 0
for i in range(100001):
    cnt[i+1] += cnt[i]
    if cnt[i] > 0:
        ans += 1

print(ans)
