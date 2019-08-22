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
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 998244353;
typedef vector<long> VL;
typedef vector<vector<long>> VLL;
typedef vector<vector<vector<long>>> VLLL;
// LONG_MAX,LLONG_MAX
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class Key,class Value> ostream& operator << (ostream &s, map<Key,Value> M)
{ for ( auto itr = begin(M); itr != end(M); ++itr) { s << itr->first << ":" << itr->second; } return s;}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    int s = 0;
    REP (i,N) {
        cin >> a[i];
        s += a[i];
    }
    
    vector<vector<long>> dp(N+1,vector<long>(s+1,0));
    dp[0][0] = 1;
    REP(i,N) {
        REP(R,s+1) {
            if (R >= a[i]) {
                dp[i+1][R] += dp[i][R-a[i]];
            }
            dp[i+1][R] += (2 * dp[i][R]);
            dp[i+1][R] %= mod;
        }
    }
    
    vector<vector<long>> dp2(N+1,vector<long>(s+1,0));
    dp2[0][0] = 1;
    REP(i,N) {
        REP(R,s+1) {
            if (R >= a[i]) dp2[i+1][R] += dp2[i][R-a[i]];
            dp2[i+1][R] += (dp2[i][R]);
            dp2[i+1][R] %= mod;
        }
    }

    int f = (s+1) / 2;
    long long int ans = 1;
	for (int i = 0; i < N; i++) {
		ans *= 3;
		ans %= mod;
	}
    FOR(R,f,s+1) {
        ans += (mod-dp[N][R]);
        ans %= mod;
        ans += (mod-dp[N][R]);
        ans %= mod;
        ans += (mod-dp[N][R]);
        ans %= mod;

    }
    if (s % 2 == 0) {
        ans += 3*dp2[N][s/2];
        ans %= mod;
    }

    cout << ans%mod << endl;
}
