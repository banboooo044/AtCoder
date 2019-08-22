N = int(input())
st = {}
for i in range(N):
    S = list(input())
    S.sort()
    w = "".join(S)
    if w in st:
        st[w] += 1
    else:
        st[w] = 1
ans = 0
for v in st.values():
    if v > 1:
        ans += (v * (v - 1) // 2)

print(ans)
