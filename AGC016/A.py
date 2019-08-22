S = input()
L = len(S)
ans = float('inf')
for s in [chr(i) for i in range(97, 97+26)]:
    mx = 0
    cnt = 0
    for i in range(L):
        if S[i] == s:
            mx = max(mx,cnt)
            cnt = 0
        else:
            cnt += 1
    
    val = max(cnt , mx)
    ans = min(ans,val)

print(ans)