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

using Long = long long;
template<typename W>
using Edge = pair<int, W>;
template<typename W>
using WeightedGraph = vector<vector<Edge<W>>>;
using UnWeightedGraph = vector< vector<int>>;

void bfs(int s,const UnWeightedGraph &g, vector<int> &indeg, vector<int> &used, vector<int> &order, vector<int> &pathLen) {
    // q : 入力辺を持たない全てのノード集合
    queue<int> q;
    q.push(s);
    used[s] = true;
    pathLen[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        // 入力辺を持たないのでトポロジカル順序が確定.
        order.push_back(u);
        for(auto &&v: g[u]) {
            indeg[v]--;
            pathLen[v] = max(pathLen[v], pathLen[u]+1);
            if(indeg[v] == 0 && !used[v]) {
                used[v] = true;
                q.push(v);
            }
        }
    }
}

// トポロジカルソート 
// 時間計算量 : O( V + E )
bool tpsort(const UnWeightedGraph &g, vector<int> &order, vector<int> &pathLen){
    // g : 重みなしグラフ, order : トポロジカル順序で頂点番号を格納する用.
    // indeg[i] : 頂点iに対する入力辺の数
    // used : 頂点を既に通ったか
    vector<int> indeg(g.size(), 0);
    vector<int> used(g.size(), false);
    order.clear();
    pathLen.resize(g.size(), 0);
    // indegの初期化
    for(int u = 0;u < g.size(); u++)
        for(int v: g[u])
            indeg[v]++;
    // 各頂点からbfsを行う.
    for(int u = 0;u < g.size(); u++)
        if(indeg[u] == 0 && !used[u])
            bfs(u, g, indeg, used, order, pathLen);
    
    if (order.size() != g.size()) 
        return false;
    else 
        return true;
}

int vertex(int i,int j, int N) {
    if (i < j) {
        return N * i + j - 1;
    }
    else {
        return N * j + i - 1;
    }
}

int main(void) {
    int N;
    cin >> N;
    int V = N*N;
    UnWeightedGraph g(V);
    int prev, a;
    for(int i = 0;i < N;i++) {
        cin >> prev;
        prev--;
        for(int j = 0;j < N-2;j++) {
            cin >> a;
            a--;
            g[vertex(i, prev, N)].emplace_back(vertex(i, a, N));
            prev = a;
        }
    }
    vector<int> order;
    vector<int> depth;
    bool flg = tpsort(g, order, depth);
    if ( !flg ) {
        cout << -1 << endl;
        exit(0);
    }
    cout << MAX(depth)+1 << endl;
}
