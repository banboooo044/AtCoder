S = list(input())
a = S.count('0')
print(min(a,len(S)-a)*2)