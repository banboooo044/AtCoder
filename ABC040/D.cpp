#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define llINF (long long) 9223372036854775807
#define loINF (long) 2147483647
#define shINF (short) 32767
#define SORT(c,func) sort((c).begin(),(c).end(),func())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vec) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define COMP(type,el) struct Order_r {bool operator() (road const& A,road const& B) const{return A.y > B.y;}}
using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;

typedef struct {
    long a,b,y;
}road;
typedef struct {
    long q,v,w;
}query;
struct Order_r {
    bool operator() (road const& A,road const& B) const {
        return A.y > B.y;
    }
};
struct Order_q {
    bool operator() (query const& A,query const& B) const {
        return A.w > B.w;
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

void dump_road(road A){
    dump(A.a)
    dump(A.b)
    dump(A.y)
}

void dump_query(query A){
    dump(A.q)
    dump(A.v)
    dump(A.w)
}

int main(void){
    long N,M,Q;
    long a,b,y,v,w;
    cin >> N >> M;
    vector<road> R(M);
    Union_Find uf(N);
    REP(i,M) {
        cin >> a >> b >> y;
        R[i] = {a,b,y};
    }
    cin >> Q;
    vector<query> men(Q);
    vector<long> ans(Q,0);
    REP(i,Q) {
        cin >> v >> w;
        men[i] = {i,v,w};
    }
    SORT(R,Order_r);
    SORT(men,Order_q);

    //REP(i,R.size()) dump_road(R[i]);
    //REP(i,men.size()) dump_query(men[i]);

    long itr = 0;
    long j;
    REP(i,Q) {
        for (j = itr;R[j].y > men[i].w && j < M;j++){
            uf.unite((R[j].a)-1,(R[j].b)-1);
        }
        itr = j;
        ans[men[i].q] = uf.getGroupSize((men[i].v)-1);
    }

    REP(i,Q) cout << ans[i] << endl;
    return 0;
}