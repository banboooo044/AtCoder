#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(i,m) for (auto i = m.begin(); i != m.end(); ++i)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
using namespace std;
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
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

class Union_Find {
private:
    vector<unsigned> par;    // par[x] : x の親ノード
    vector<unsigned> rank;   // rank[x] : 木の高さ
    vector<long> group;
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

    unsigned long getGroupSize(long key){
        return group[find(key)]; 
    }

    // x と y が同じ集合に属しているか？
    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }
    
    void dump_par(void){
        dump1d_arr(par);
    }

    void dump_rank(void){
        dump1d_arr(rank);
    }

};

VVI E;
vector<bool> visited;
Union_Find uf;
void dfs(long node) {
	if (visited[node]) return;
	visited[node] = true;
	REP(i,E[node].size()) {
		uf.unite(node,E[node][i]);
		dfs(E[node][i]);
	}
}

int main(void) {
	LL N,G,e,a,b;
	map<LL,LL> dic,dic2;
	cin >> N >> G >> e;
	E = VVI(N);
	uf = Union_Find(N);
	visited = vector<bool>(N,false);
	VI p(G),dir;
	REP(i,G) cin >> p[i];
	REP(i,e) {
		cin >> a >> b;
		if (a == 0) dir.push_back(b);
		else if (b == 0) dir.push_back(a);
		else {
			E[a].push_back(b);
			E[b].push_back(a);
		}
	}

	FOR(i,1,N) if (!visited[i]) dfs(i);
	REP(i,dir.size()) dic[uf.find(dir[i])]++;
	LL par;
	REP(i,G) {
		par = uf.find(p[i]);
		if (IN(par,dic)) dic2[par]++;
	}
	LL ans = 0;
	ENUM(i,dic2) ans += (min(dic[i->first],i->second));
	cout << ans << endl;
}
