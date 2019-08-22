S = input()

a = "01" * (len(S) // 2) 

if len(S) % 2 == 1:
    a += "0"
cnt = 0
for i in range(len(S)):
    if S[i] != a[i]:
        cnt += 1

print(min(cnt,len(S)-cnt))