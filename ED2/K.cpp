// Grundy数
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
constexpr long mod = 1000000007;
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
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> dp(K+1,-1);
    REP(i,N) cin >> A[i];
    REP(i,A[0]) dp[i] = 0;

    vector<int> usedGrundy(N+1);
    FOR(k,A[0],K+1) {
        int cnt = 0;
        fill(usedGrundy.begin(),usedGrundy.end(),0);
        for(int a : A) {
            if (a > k) break;
            if (dp[k-a] != -1 ) {
                cnt++;
                usedGrundy[dp[k-a]] = 1;
            }
        }
        if (cnt == 0) continue;
        REP(i,N+1) {
            if(usedGrundy[i] == 0) {
                dp[k] = i;
                break;
            }
        }
    }
    if (dp[K] == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}

