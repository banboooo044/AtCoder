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
// union find構造
/* 使い方  Union_Find uf(V); uf.find(),uf.size()　etc..*/
using namespace std;
typedef priority_queue<long,vector<long>,greater<long>> pq;
typedef map<long,pq> mp;
typedef vector<long> VI;
typedef vector<VI> VVI;
long N;



class Union_Find {
private:
    vector<unsigned> par;    // par[x] : x の親ノード
    vector<unsigned> rank;   // rank[x] : 木の高さ
    mp cost;
    vector<long> root;
    vector<long> root_only;
    vector<long> root_two;
    size_t sz;             // 集合の個数
public:
    
    // コンストラクタ : 空
    Union_Find() : sz(0) { }

    // コンストラクタ : 1 要素の集合 n 個
    Union_Find(size_t n) :
        par(n, -1), rank(n, 0), sz(n) {
        for (size_t i = 0; i < n; i++) {
            pq a;
            par[i] = i;
            cost[i] = a;
        }
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

    void add_weight(long node,long weight){
        cost[node].push(weight);
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

        if (cost[x].size() < cost[y].size()){
            par[x] = y;
            while (!cost[x].empty()){
                cost[y].push(cost[x].top());
                cost[x].pop();
            }
        }

        else {
            par[y] = x;
            while (!cost[y].empty()){
                cost[x].push(cost[y].top());
                cost[y].pop();
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

    void find_root(void){
        REP(i,N) {
            if (par[i] == i){
                if (cost[i].size() == 1) root_only.push_back(i);
                else {
                    if (cost[i].size() == 2) root_two.push_back(i);
                    root.push_back(i);
                }
            }
        }
    }

    long long connect(void){
        find_root();
        //dump1d_arr(root);
        long long ans = 0LL;

        while (sz != 1){
            REP(i,root_only.size()){
                if (root_only[i] == loINF) continue;
                long long a = cost[root_only[i]].top();
                cost[root_only[i]].pop();
                long long minc = loINF,minv;
                REP(j,root.size()){
                    if (root[j] == loINF) continue;
                    long long c = cost[root[j]].top();
                    if (minc > c) {
                        minc = c;
                        minv = j;
                    }
                }
                if (minc == loINF){
                    REP(j,root_two.size()){
                        if (root_two[j] == loINF) continue;
                        long long c = cost[root_two[j]].top();
                        if (minc > c) {
                            minc = c;
                            minv = j;
                        }
                    }
                    if (minc == loINF) {
                        cout << "Impossible" << endl;
                        exit(0);
                    }
                    root_only.push_back(root_two[minv]);
                    root_two[minv] = loINF;
                }
                else {
                    if (cost[root[minv]].size() == 3) {
                        root_two.push_back(root[minv]);
                        root[minv] = loINF;
                    }
                }
                //dump(minc);
                ans += (minc + a);
                cost[minv].pop();
                unite(root_only[i],minv);
                root_only[i] = loINF;
            }

            long long minv = N+1,minv2 = N+1,minc = loINF,minc2 = loINF;
            REP(i,root.size()){
                if (root[i] == loINF) continue;
                if (cost[root[i]].top() < minc2){
                    minc2 = cost[root[i]].top();
                    minv2 = i;
                    if (minc2 < minc) {
                        long long tmp = minc;
                        minc = minc2;  
                        minc2 = tmp;
                        long long tmpv = minv;
                        minv = minv2;
                        minv2 = tmpv;
                    }
               }
            }

            if (minc == loINF || minc2 == loINF) continue;
            //dump(root[minv]);
            //dump(root[minv2]);
            cost[root[minv]].pop();
            cost[root[minv2]].pop();
            unite(root[minv],root[minv2]);
            ans += (minc + minc2);

            if (cost[root[minv]].size() < cost[root[minv2]].size()){
                 root[minv] = loINF;
            }
            else root[minv2] = loINF;
        }
        
        return ans;
    }
};


int main(void){
    long M;
    cin >> N >> M;
    Union_Find uf(N);
    long a,x,y;
    REP(i,N){
        cin >> a;
        uf.add_weight(i,a);
    }

    REP(i,M){
        cin >> x >> y;
        uf.unite(x,y);
    }
   //uf.dump_par();

    cout << uf.connect() << endl;
    return 0;
}