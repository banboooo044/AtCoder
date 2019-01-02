import random
import string
import subprocess
from itertools import count

n = random.randint(1,30)
n2 = random.randint(0,10)
random_str = ''.join([random.choice(string.ascii_uppercase) + 'A'  for i in range(n)])
random_str2  = random_str[0:2*n]
for i in range(n2):
	random_str2 += (random.choice(string.ascii_uppercase) + 'B' )

print(random_str)
print(random_str2)
print("----------------------------------------------------")

filename = "./result"

with open(filename,'w') as fileObj:
	fileObj.write(random_str + "\n")
	fileObj.write(random_str2 + "\n")
	fileObj.write("\n")



cp = subprocess.Popen(["cat",filename],stdout=subprocess.PIPE)
c = subprocess.Popen("./a.out",shell=True,stdin=cp.stdout,stdout=subprocess.PIPE)
output = c.stdout

for line in output:
	ans1 = line.decode('ascii')


Ss = random_str + '#'
Ts = random_str2 + '#'

dp = [[False] * (len(Ts) + 1) for i in range(len(Ss) + 1)]
dp[0][0] = True
for iS, S in enumerate(Ss):
    for iT, T in enumerate(Ts):
        if not dp[iS][iT]: continue
        if Ss[iS] == Ts[iT]:
            dp[iS + 1][iT + 1] = True
        else:
            if Ss[iS] == 'A':
                dp[iS + 1][iT] = True
            if Ts[iT] == 'B':
                dp[iS][iT + 1] = True

if dp[-1][-1]:
    ans = "YES\n"
else:
    ans = "NO\n"

print(ans1)
print(ans)

if ans == ans1:
	print("ok")
else:
	print("ERROR")

