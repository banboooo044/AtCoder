 

A, B = map(int, input().split())
l = B-A+1
     
divisors = []
for i in range(A, B+1):
  tmp = set()
  for n in [2,3,5,7,11,13,17,19,23,29,31]:
    #幅を超えてるのでかぶることはない
    if n >= l:
       break

    if i % n == 0:
      tmp.add(n)
  #約数を格納
  divisors.append(tmp)


memo = {}

def process(arr, div, i):
  if i == len(arr):
    return 1
  divstr = str(div)
  print(divstr)
  if (divstr,i) in memo:
    return memo[(divstr,i)]
     
  ret = 0
  if len(div & arr[i]) == 0:
    ret += process(arr, div | arr[i], i+1)
  ret += process(arr, div, i+1)
  memo[(divstr,i)] = ret
  print(ret)
  return ret
     
print(process(divisors, set(), 0))