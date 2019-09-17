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

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> G;
    vector<vector<int>> E(N, vector<int>(N, 0));
    vector<int> used;

    vector<int> v1_l;
    vector<int> v2_l;
    REP(v, N)
    {
        if (v % 2)
            v2_l.push_back(v);
        else
        {
            v1_l.push_back(v);
        }
    }
    int l1 = v1_l.size();
    int l2 = v2_l.size();

    int pattern = 1;
    if (N % 2 == 1)
    {
        for (int i = (N); i >= 1; i -= 2)
        {
            pattern *= i;
        }
    }
    else
    {
        for (int i = (N - 1); i >= 1; i -= 2)
        {
            pattern *= i;
        }
    }
    dump(pattern);

    for (int j = 0; j < pattern; j++)
    {
        REP(cnt, l1)
        {
            cout << v1_l << endl;
            cout << v2_l. << endl;
            REP(l, l2)
            {
                int v1 = v1_l[l];
                int v2 = v2_l[l];

                used = vector<int>(N, 0);
                REP(o, N)
                {
                    if (o == v1 || o == v2)
                        continue;
                    if (E[v1][o] == E[v2][o])
                        used[E[v1][o]]++;
                }
                FOR(i, 1, N)
                {
                    if (used[i] < 1)
                    {
                        E[v1][v2] = i;
                        E[v2][v1] = i;
                        break;
                    }
                }
            }
            int tmp = v2_l[0];
            REP(i, l2 - 1)
            {
                v2_l[i] = v2_l[i + 1];
            }
            v2_l[l2 - 1] = tmp;
        }
        int tmp = v1_l[0];
        REP(i, l1 - 1)
        {
            v1_l[i] = v1_l[i + 1];
        }
        v1_l[l1 - 1] = tmp;
    }

    REP(i, N - 1)
    {
        FOR(j, i + 1, N)
        {
            cout << E[i][j] << " ";
        }
        cout << endl;
    }
}
