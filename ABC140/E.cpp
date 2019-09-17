#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define dump(x)  cerr << #x << " => " << (x) << endl
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
typedef long long LL;
constexpr LL dx[4] = {0,1,0,-1};
constexpr LL dy[4] = {1,0,-1,0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
// LONG_MAX,LLONG_MAX
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (LL i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (LL i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class Key,class Value> ostream& operator << (ostream &s, map<Key,Value> M)
{ for ( auto itr = begin(M); itr != end(M); ++itr) { s << itr->first << ":" << itr->second; } return s;}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
    LL N;
    cin >> N;
    vector<LL> P(N);
    vector<LL> pos(N);
    for(LL i = 0;i < N;i++) {
        cin >> P[i];
        P[i]--;
        pos[P[i]] = i;
    }

    set<LL> S;
    S.insert(-2);
    S.insert(-1);
    S.insert(N);
    S.insert(N+1);
    LL ans = 0;
    for(LL i = N-1;i >= 0;i--) {
        auto it1 = S.lower_bound(pos[i]);
        it1 = prev(it1, 1);
        LL lr = *it1;
        it1 = prev(it1, 1);
        LL ll = *it1;
        auto it2 = S.upper_bound(pos[i]);
        LL rl = *it2;
        it2 = next(it2, 1);
        LL rr = *it2;
        if (lr != -1) {
            ans += (LL) ((lr - ll) * (rl - pos[i]) * (i+1));
        }
        if (rl != N) {
            ans += (LL) ((rr - rl) * (pos[i] - lr) * (i+1));
        }
        
        S.insert(pos[i]);
    }
    cout << ans << endl;
}
