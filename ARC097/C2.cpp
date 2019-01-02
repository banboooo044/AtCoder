#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define all(v) begin(v), end(v)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define int long long int

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define LEQ(n, m) ((n) <= (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int const MOD = 1000000007;

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

int const INF = 1e18 + 10;
int dp[1000010][26];
signed main() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.length();
    memset(dp, 0, sizeof(dp));
    rep(i,0,26) dp[n][i] = 0;

    repr(i,n-1,0) {
        rep(j,0,26) {
            if(s[i] - 'a' == j) {
                dp[i][j] = 1;
                rep(x,0,26) dp[i][j] = min(INF, dp[i][j] + dp[i+1][x]);
            }
            else dp[i][j] = dp[i+1][j];
        }
    }

    string ans = "";
    rep(i,0,n) {
        int j;
        for(j = 0; j < 26; j++) {
            if(k <= dp[i][j]) {
                ans += 'a' + j;
                k--;
                while(s[i] != j + 'a') i++;
                break;
            }
            else k -= dp[i][j];
        }
        if(j == 26 || k == 0) break;
    }
    if(ans == "") cout << "Eel" << endl;
    else cout << ans << endl;
    return 0;
}