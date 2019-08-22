#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define MIN(vec) *min_element(vec.begin(), vec.end())
using namespace std;
typedef long long LL;
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
    int L;
    cin >> L;
    vector<LL>  A(L);
    REP(i, L) cin >> A[i];
    vector<vector<LL> > DP(L,vector<LL> (5,0));
    // <通らない(Z)> [A_D <偶数回通る>] [A_S <奇数回数通る>] [A_G <偶数回通る>] [A_U <通らない>]
    constexpr int Z = 0,D = 1,S = 2,G = 3,U = 4;
    DP[0][Z] = A[0];
    DP[0][D] = A[0] != 0 ? A[0] % 2 : 2;
    DP[0][S] = (A[0] % 2 == 0) ? 1 : 0;
    DP[0][G] = A[0] != 0 ? A[0] % 2 : 2;
    DP[0][U] = A[0];
    REP(i,L-1) {
        DP[i+1][Z] = DP[i][Z] + A[i+1];
        DP[i+1][D] = min(DP[i][Z],DP[i][D]) + ((A[i+1] != 0) ? A[i+1] % 2 : 2);
        DP[i+1][S] = min({DP[i][Z],DP[i][D],DP[i][S]}) + ((A[i+1] % 2 == 0) ? 1 : 0);
        DP[i+1][G] = min({DP[i][Z],DP[i][D],DP[i][S],DP[i][G]}) + ((A[i+1] != 0) ? A[i+1] % 2 : 2);
        DP[i+1][U] = min({DP[i][Z],DP[i][D],DP[i][S],DP[i][G],DP[i][U]}) + A[i+1];
    }
    cout << MIN(DP[L-1]) << endl;
}
