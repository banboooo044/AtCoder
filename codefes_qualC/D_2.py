#D: Yet Another Palindrome Partitioning

from itertools import accumulate
from operator import xor
 
s = tuple(map(lambda c: 1 << (ord(c)-ord('a')),input()))
L = len(s)
dp = dict()
dp[0] = 0

print(s)
for v in accumulate(s, xor):
	#dp.get(v,L)とmin(dp.get(v ^ (1 << i), L) for i in range(26))+1の小さい方を格納。
	#dp.get(v ^ (1 << i),L) (i <- 0 ~ 25)の26個の中で最小のものを比較
	#(1 << i) は 2^0から2^25の全パターンを表す
	#v ^ (1 << i)は、文字列vを最短で分けた時の分割数。辞書に入ってればそれを使って短縮。なければ L ということに。
	print(dp)
	dp[v] = min(dp.get(v,L), min(dp.get(v ^ (1 << i), L) for i in range(26))+1)
 

print(dp[v] + (v == 0))


