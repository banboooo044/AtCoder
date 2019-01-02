k = int(input())

shou = k//50
amari = k%50

a = str(49-k+shou*51)
b = str(100-k+shou*51)

n = []

for i in range(amari):
    n.append(b)

for i in range(50-amari):
    n.append(a)

print('50')
nstr = ' '.join(n)
print(nstr)
