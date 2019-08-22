#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
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

struct Node{
    long d,i,j;
};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
    priority_queue<Node, vector<Node>, function<bool(Node,Node)>> que (
        [](const Node &a,const Node &b){return a.d > b.d;}
    );
    long H,W;
    cin >> H >> W;
    vector<string> A(H);
    vector<vector<long>> used(H,vector<long>(W,-1));
    REP(i,H) {
        cin >> A[i];
        REP(j,W) {
            if (A[i][j] == '#') {
                que.push(Node{0,i,j});
                used[i][j] = 0;
            }
        }
    }
    while (!que.empty()) {
        Node ret = que.top();
        long d = ret.d;
        long i = ret.i;
        long j = ret.j;
        que.pop();
        if (i > 0 && used[i-1][j] == -1) {
            used[i-1][j] = d+1;
            que.push(Node{ d+1, i-1,j});
        }
        if (i < H-1 && used[i+1][j] == -1) {
            used[i+1][j] = d+1;
            que.push(Node{ d+1, i+1,j});
        }
        if (j > 0 && used[i][j-1] == -1) {
            used[i][j-1] = d+1;
            que.push(Node{ d+1, i,j-1});
        }
        if (j < W-1 && used[i][j+1] == -1) {
            used[i][j+1] = d+1;
            que.push(Node{ d+1, i,j+1});
        }
    }
    long ans = 0;
    REP(i,H) {
        REP(j,W) {
            ans = max(ans,used[i][j]);
        }
    }
    cout << ans << endl;
}
