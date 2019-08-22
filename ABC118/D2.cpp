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


constexpr int n[9] = {2,5,5,4,5,6,3,7,6};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<int> A(M);
    REP(i,M) cin >> A[i];
    vector<string> dp(N+1,"");
    REP(i,M) {
        FOR(j,i+1,M) {
            if (n[A[i]-1] == n[A[j]-1]) {
                int m = max(A[i],A[j]);
                A[i] = m;A[j] = m;
            }
        }
    }
    UNIQ(A);
    for (int num : A) {
        if (n[num-1] <= N) dp[n[num-1]] = max(dp[n[num-1]],to_string(num));
    }
    FOR(i,1,N+1) {
        for (int num : A) {
            if (i >= n[num-1]) {
                string a;
                if (dp[i-n[num-1]] != "")
                    a = max(dp[i-n[num-1]]+to_string(num),to_string(num)+dp[i-n[num-1]]);
                else
                    a = "";
                dp[i] = max(dp[i],a,[] (string l,string r){
                    return (l.size() < r.size() || ( l.size() == r.size() && l < r ));
                });
            }
        }
    }
    cout << dp[N] << endl;
}