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
#define SORT(c) sort((c).begin(),(c).end())

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
bool pairCompare(const pr& firstElof, const pr& secondElof)
{
    return firstElof.first < secondElof.first;
}
class Union_Find {
private:
    vector<unsigned> par;    // par[x] : x の親ノード
    vector<unsigned> rank;   // rank[x] : 木の高さ
    vector<vector<pr>> min_node;
    vector<long> other_node;
    size_t sz;             // 集合の個数
public:
    
    // コンストラクタ : 空
    Union_Find() : sz(0) { }

    // コンストラクタ : 1 要素の集合 n 個
    Union_Find(size_t n,vector<long> a) :
        par(n, -1), rank(n, 0), sz(n) ,min_node(n) {
        for (size_t i = 0; i < n; i++) {
        	par[i] = i;
        	min_node[i].push_back(pr(a[i],i));
        }
        other_node = a;
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
            REP(i,min_node[x].size()){
            	min_node[y].push_back(min_node[x][i]);
            }
        }

        else {
            par[y] = x;
            REP(i,min_node[y].size()){
            	min_node[x].push_back(min_node[y][i]);
            }
            if (rank[x] == rank[y]) rank[x]++;
        }
        sz--;
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

    long getRootMin(void){
    	long root_min = 0;
    	REP(i,par.size()){
    		if (par[i] == i) {
    			sort(min_node[i].begin(),min_node[i].end(),pairCompare);

    				/*REP(j,min_node[i].size()){
    					dump(min_node[i][j].first);
    					dump(min_node[i][j].second);
    				}*/

    			root_min += min_node[i][0].first;
    			other_node[min_node[i][0].second] = loINF;
    		}
    	}
    	return root_min;
    }

    long getOtherMin(long N,long M){
    	long num = 2 * (N - M - 1) - sz;

    	if (num < 0) {
    		cout << 0 << endl;
    		exit(0);
    	}

    	if (num > M) {
    		cout << "Impossible" << endl;
    		exit(0);
	   	}
	   	if (num ==  0) return 0;

    	SORT(other_node);
    	REP(i,num-1){
    		other_node[i+1] += other_node[i];
    	}
    	return other_node[num-1];
    }
};

int main(void) {
	long N,M;
	long x,y;
	cin >> N >>  M;
	VI a(N);
	REP(i,N) cin >> a[i];
	Union_Find uf(N,a);
	REP(i,M){
		cin >> x >> y;
		uf.unite(x,y);
	}
	//dump(uf.getRootMin());

	cout << uf.getRootMin() + uf.getOtherMin(N,M) << endl;
	return 0;
}