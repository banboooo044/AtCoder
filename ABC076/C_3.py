#C: Ducbious Document
s = input()
t = input()
 
candidates = []
for i in range(len(s) - len(t) + 1):
    tfr = i
    tto = i + len(t)
    u = ''
    ok = True
    for p in range(len(s)):
    	#S[tfr]からS[tto]までがTと一致するか判定
        if tfr <= p < tto:
            if s[p] in ['?', t[p - i]]:
                u += t[p - i]
            else:
                ok = False
                break
        #それ以外の場所の文字列を作る
        else:
            if s[p] == '?':
                u += 'a'
            else:
                u += s[p]
    if ok:
        candidates.append(u)
 
if candidates:
    print(min(candidates))
else:
    print("UNRESTORABLE")