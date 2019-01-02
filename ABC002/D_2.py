#派閥(最大クリーク問題)
#bit総当たり方法をpythonで実現したプログラム
#他の人の回答を参考にしている。

from itertools import combinations as comb
 
n, m = map(int, input().split())
#n * n の配列を作っている。

rels = [[False] * n for _ in range(n)]

for _ in range(m):
    xi, yi = map(int, input().split())
    x, y = xi - 1, yi - 1
    rels[x][y] = True
    rels[y][x] = True

#   1 | 2 | 3 | 4 | 5
# 1 - | - | - | - | -
# 2 - | - | ◯ | - | -
# 3 - | ○ | - | - | - 
# 4 - | - | - | - | -
# 5 - | - | - | - | -

#入力(2,3) or (3,2) があたえられた場合上のような表を作りたい.

ans = 1

for rep in range(n, 0, -1):
    relcombs = comb(range(0, n), rep)
    for relcomb in relcombs:
        #relcombには 集合(0,1,2,3,4)の部分集合が大きい順に格納されてくる。

        #部分集合に対し、２つの組みを順にi,jとし、全て作る
        #rels[i][j]の値を順にリストに格納
        #つながっていればrels[i][j]はTrueになっているので、全部Trueならば、それはクリークであることを意味する
        jud = [(rels[i][j]) for (i, j) in comb(relcomb, 2)]

        #よって、すべてがTrueであれば、その時の要素数はrepに格納されているのでこれを答えとしてあげる。
        if all(jud):
            ans = rep
        #また、要素数は大きい方から探索しているから、見つかり次第、それが最大で答えである。
    if ans != 1:
        break
 
print(ans)