#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define RREP(i, n) for (long long i = n; i >= 0; i--)
#define RFOR(i, a, b) for (long long i = (a); i > (b); i--)
#define dump(x) cerr << #x << " => " << (x) << endl
#define SORT(c) sort((c).begin(), (c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end()) //ソートの必要あり
#define IN(n, m) (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m)                                           \
    for (auto itr = m.begin(); itr != m.end(); ++itr)         \
    {                                                         \
        cerr << itr->first << " --> " << itr->second << endl; \
    }
#define FINDL(vec, x) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())
#define FINDU(vec, x) (upper_bound(vec.begin(), vec.end(), x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N, val) \
    cout << fixed;          \
    cout << setprecision(N) << val << endl
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h, w, x, y) (0 <= y && y < h && 0 <= x && x < w)
#define EQ(a, b) (abs(a - b) < 1e-10)
using namespace std;
constexpr int dx[4] = {0, 1, 0, -1};
constexpr int dy[4] = {1, 0, -1, 0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL, LL> pr;
typedef vector<bool> VB;
typedef vector<pr> VP;
typedef priority_queue<pr, vector<pr>, greater<pr>> pq;
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

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    long N, M;
    cin >> N >> M;
    vector<LL> A(N - 1 + M), B(N - 1 + M);
    vector<vector<int>> edge(N);
    vector<pair<int, int>> par(N, pair<int, int>(-1, 0));
    vector<int> root(N, 0);
    vector<int> used(N, 0);

    REP(i, N - 1 + M)
    {
        cin >> A[i] >> B[i];
        edge[A[i] - 1].push_back(B[i] - 1);
        root[B[i] - 1] = 1;
        used[B[i] - 1]++;
    }

    queue<pair<int, int>> que;
    REP(i, N)
    {
        if (root[i] == 0)
        {
            par[i] = make_pair(0, 0);
            que.push(make_pair(i + 1, 0));
            break;
        }
    }
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        int pos = cur.first;
        int depth = cur.second;
        for (int nx : edge[pos - 1])
        {
            par[nx] = make_pair(depth + 1, pos);
            if (used[nx] == 1)
            {
                que.push(make_pair(nx + 1, depth + 1));
            }
            else
                used[nx]--;
        }
    }
    REP(i, N)
    {
        cout << par[i].second << endl;
    }
}
