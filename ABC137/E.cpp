#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define dump(x) cerr << #x << " => " << (x) << endl
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end()) //ソートの必要あり
#define IN(n, m) (!(m.find(n) == m.end()))
#define FINDL(vec, x) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())
#define FINDU(vec, x) (upper_bound(vec.begin(), vec.end(), x) - vec.begin())
#define EQ(a, b) (abs(a - b) < 1e-10)
using namespace std;
typedef long long LL;
constexpr int dx[4] = {0, 1, 0, -1};
constexpr int dy[4] = {1, 0, -1, 0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;

// LONG_MAX,LLONG_MAX
template <class T1, class T2>
ostream &operator<<(ostream &s, pair<T1, T2> P)
{
    return s << '<' << P.first << ", " << P.second << '>';
}
template <class T>
ostream &operator<<(ostream &s, vector<T> P)
{
    for (int i = 0; i < P.size(); ++i)
    {
        if (i > 0)
        {
            s << " ";
        }
        s << P[i];
    }
    return s;
}
template <class T>
ostream &operator<<(ostream &s, vector<vector<T>> P)
{
    for (int i = 0; i < P.size(); ++i)
    {
        s << endl
          << P[i];
    }
    return s << endl;
}
template <class Key, class Value>
ostream &operator<<(ostream &s, map<Key, Value> M)
{
    for (auto itr = begin(M); itr != end(M); ++itr)
    {
        s << itr->first << ":" << itr->second;
    }
    return s;
}

using Long = long long;

template <typename W>
using Edge = pair<int, W>;

template <typename W>
using WeightedGraph = vector<vector<Edge<W>>>;

vector<int> upd;
// 時間計算量 ; O(VE)
template <typename W>
tuple<vector<W>, bool> bellman_ford(int s, int V_size, int E_size, WeightedGraph<W> &G)
{
    // true -> 負の閉路なし, false -> 負の閉路あり
    // s : 始点, G : 隣接リスト G[v1][v2] : (頂点, 重み)
    const W INF = numeric_limits<W>::max();
    // P.first : 距離, P.second : 頂点番号
    using P = pair<W, int>;

    // 初期化
    vector<W> d(V_size, INF);
    d[s] = 0;
    bool update = true;
    int c = 0;
    for (int k = 0; update && k < (2 * V_size); k++)
    {
        update = false;
        for (int i = 0; i < G.size(); i++)
        {
            for (auto &&p : G[i])
            {
                if (d[i] != INF && d[p.first] > d[i] + p.second)
                {
                    d[p.first] = d[i] + p.second;
                    update = true;
                    if (p.first == (V_size - 1) && k >= (V_size))
                    {
                        return forward_as_tuple(d, false);
                    }
                }
            }
        }
    }
    return forward_as_tuple(d, true);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, P;
    cin >> N >> M >> P;
    WeightedGraph<int> G(N);
    int a, b, c;
    REP(i, M)
    {
        cin >> a >> b >> c;
        G[a - 1].emplace_back(b - 1, -(c - P));
    }
    vector<int> D;
    bool flg;
    tie(D, flg) = bellman_ford(0, N, M, G);

    if (flg)
    {
        cout << max((-D[N - 1]), 0) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
