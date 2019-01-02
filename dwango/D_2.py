from itertools import chain
import sys

from collections import defaultdict
sys.setrecursionlimit(1500)

N = int(input())
x = list(map(int,input().split()))
if (N == 1) :
  exit(0)
a = list(map(int,input().split(" ")))

parent = list(map(lambda x:int(x)-1,a))
parent.insert(0,0)

D = defaultdict(int)
children_weight = defaultdict(int)
children = defaultdict(list)
for v,p in enumerate(parent):
  D[p] += 1
  children[p].append(v)
  children_weight[p] += x[v]

D[0] -= 1

leaves = set(range(N)) - set(parent)

def rec(candidates, satisfied, cmax, current):
  if not candidates:
    return cmax

  m = float('inf')
  for p in candidates:
    ncandidates = candidates.copy()
    ncandidates.discard(p)
    
    ncurrent = current + x[p] + sum(x[v] for v in children[p] if v in leaves)
    ncmax = max(cmax,ncurrent)
    ncurrent -= children_weight[p]

    nsatisfied = satisfied.copy()
    nsatisfied[parent[p]] += 1
    if D[parent[p]] == nsatisfied[parent[p]]:
      ncandidates.add(parent[p])

    m = min(rec(ncandidates, nsatisfied, ncmax, ncurrent),m)
  return m




# initial candidates
satisfied = defaultdict(int)
for t in leaves:
  satisfied[parent[t]] += 1

candidates = set(p for p in D.keys() if D[p] == satisfied[p])
task = {}
need_task = [1]
que = [1]
while que != []:
  t = que.pop()
  for i in range(N-1):
    if a[i] == t:
      need_task.append(i+2)
      que.append(i+2)
 
print(need_task)
for i in range(N-1):
  if not (a[i] in need_task):
    continue 
 
  if a[i] in task:
    task[a[i]] += x[i+1]
 
  else:
    task[a[i]] = x[i+1] + x[a[i]-1]

if task == {}:
  ans = x[0]
else:
  ans = max(task.values())
ans2 = rec(candidates, satisfied, 0,0)
if ans2 == ans:
  print("YES")

else:
  print(ans)
  print(ans2)
  print("NO")