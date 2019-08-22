N = int(input())
S = input()
mod = 1e9 + 7
dic =  { i:0  for i in [chr(i) for i in range(97, 97+26)] }
for i in range(N):
    dic[S[i]] += 1

ans = 1
for value in dic.values():
    ans *= (value+1)
    ans %=  mod
print(int((ans-1) %mod))