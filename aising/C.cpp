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
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h,w,x,y) (0 <= y && y < h && 0 <= x && x < w)
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
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
typedef pair<LL,LL> pr;
typedef vector<bool> VB;
typedef vector<pr> VP;
typedef priority_queue<pr,vector<pr>,greater<pr>> pq;

class Union_Find {
private:
    vector<unsigned> par;    // par[x] : x の親ノード
    vector<unsigned> rank;   // rank[x] : 木の高さ
    vector<int> group;
    size_t sz;             // 集合の個数
public:  
    // コンストラクタ : 空
    Union_Find() : sz(0) { }

    // コンストラクタ : 1 要素の集合 n 個
    Union_Find(size_t n) :
        par(n, -1), rank(n, 0), sz(n) ,group(n,1) {
        for (size_t i = 0; i < n; i++) par[i] = i;
    }

    size_t size() { return sz; }

    // 集合の追加 : 1 個
    void add_node() {
        par.push_back(par.size());
        rank.push_back(0);
        sz++;
    }
    // 集合の追加 : n 個
    void add_node(size_t n) {
        for (size_t i = 0; i < n; i++) add_node();
    }

    // x が属する集合の代表元を返す
    size_t find(size_t x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    // x が属する集合と y が属する集合をマージする
    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
            group[y] += group[x];
            group[x] = (-1);
        }
        else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
            group[x] += group[y];
            group[y] = (-1);
        }
        sz--;
    }

    int getGroupSize(size_t key){
        return group[find(key)]; 
    }

    // x と y が同じ集合に属しているか？
    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL H,W;
    cin >> H >> W;
    vector<string> S(H);
    map<long,LL> dicBlack;
    map<long,LL> dicWhite;
    REP(i,H) {
        cin >> S[i];
    }
    Union_Find uf(H*W);
    REP(i,H) {
        REP(j,W) {
            REP(k,4) {
                if (!INARR(H,W,j+dx[k],i+dy[k])) continue;
                if (S[i][j] == '#' && S[i+dy[k]][j+dx[k]] == '.') uf.unite(i*W+j,(i+dy[k])*W+(j+dx[k]));
                else if (S[i][j] == '.' && S[i+dy[k]][j+dx[k]] == '#') uf.unite(i*W+j,(i+dy[k])*W+(j+dx[k]));
            }
        }
    }

    REP(i,H) {
        REP(j,W) {
            if (S[i][j] == '.') dicWhite[uf.find(i*W+j)]++;
            else dicBlack[uf.find(i*W+j)]++;
        }
    }

    LL ans = 0;
    for(auto itr = dicBlack.begin(); itr != dicBlack.end(); ++itr) {
        if (IN(itr->first,dicWhite)) {
            ans += (dicWhite[itr->first]*(itr->second));
        }
    }
    cout << ans << endl;
}

