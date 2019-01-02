from itertools import accumulate
from operator import xor
 
s = tuple(map(lambda c: 1 << (ord(c)-ord('a')),input()))

print(s)