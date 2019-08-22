from bisect import bisect_left
s = input()
t = input()

l = len(s)
dic = {c: [0] * l for c in set(s)}

for i in range(l):
    dic[s[i]][i] = 1

for key in dic.keys():
    lst = dic[key]
    for i in range(l - 1):
        lst[i + 1] += lst[i]

idx = -1
ans = 0
for c in t:
    if not c in dic:
        print(-1)
        exit(0)
    lst = dic[c]
    cur = lst[idx] if idx >= 0 else 0
    i = bisect_left(lst, cur + 1)
    if i == l:
        ans += l
        idx = -1
        cur = 0
        i = bisect_left(lst, 1)

    idx = i
ans += idx
print(ans + 1)