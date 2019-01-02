
from collections import deque

a = deque([])

b = deque([0])
b.append(1)
b.append(2)

a.extend(b)

print(a)







