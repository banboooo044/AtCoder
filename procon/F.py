def Havel(seq):
  seq.sort(reverse=True)
  if (-1) in seq:
    return False , seq

  elif seq[0] == 0:
    return True , seq

  for i in range(seq[0]):
    seq[1+i] -= 1

  return Havel(seq[1:])


N = int(input())
seq = []
for i in range(N):
  n = int(input())
  seq.append(n)

flg,seq = Havel(seq)
if flg:
  print("YES")
elif seq[-2] != (-1):
  print("NO")
else:
  print("ABSOLUTELY NO")

