/* ダイトストラ法自作ライブラリ*/
/* option1:経路復元 => trace配列に復元情報 
   option2:全頂点への最短距離 => ans配列に情報*/
/*頂点の開始番号を気をつける必要なし*/
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
//#define TRACE_ROUTE // option1
//#define ALL_VERTEX  // option2

using namespace std;
typedef long long LL;

class Union_Find {
private:
    vector<unsigned> par;    // par[x] : x の親ノード
    vector<unsigned> rank;   // rank[x] : 木の高さ
    size_t sz;             // 集合の個数
public:

    // コンストラクタ : 空
    Union_Find() : sz(0) { }

    // コンストラクタ : 1 要素の集合 n 個
    Union_Find(size_t n) :
        par(n, -1), rank(n, 0), sz(n) {
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

        if (rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
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
};
/*ベルマンフォード法自作ライブラリ*/
/*標準:単一始点からの他の全頂点への最短距離 & 閉ループ判定 ,option1:経路復元(非辞書順) ,option2:単一始点&終点の最短距離。&辞書順経路復元 */
typedef vector<long> VL;
typedef vector<VL> VVL;
typedef vector<char> VC;

//global変数
VVL edge;	//隣接リスト
VL dis;

#if defined(TRACE_ROUTE) || defined(TRACE_ROUTE_DIC)
	VL pre;
#endif 

short bellman_ford (long start,long V){
	long update_flag = 1;
	long edge_start,edge_end,edge_dis;
	long roop_count = 0;

	while (update_flag) {
		if (++roop_count > V) return -1;
		update_flag = 0;
		REP(i,edge.size()) {	// 辺の始点
			edge_start = edge[i][0];
			edge_end = edge[i][1];
			edge_dis = edge[i][2];

			if (dis[edge_start] == loINF) continue; //まだ候補すらない頂点

			if (dis[edge_start] + edge_dis < dis[edge_end]){
				dis[edge_end] = dis[edge_start] + edge_dis;
				update_flag = 1;

				#if defined(TRACE_ROUTE) || defined(TRACE_ROUTE_DIC)
					pre[edge_end] = edge_start;
				#endif
			}

			#if defined(TRACE_ROUTE) || defined(TRACE_ROUTE_DIC)
			else {
				if (dis[edge_start] + edge_dis == dis[edge_end] && pre[edge_end] > edge_start){
					pre[edge_end] = edge_start;
					update_flag = 1;
				}
			}
			#endif
		}
	}

	return 0;
}

#ifdef TRACE_ROUTE
string trace_route (long start,long goal) {
	string tmp;
	string route("");
	long ver = goal;
	while (ver != start){
		tmp = ("-" + to_string(ver)) ;
		route = (tmp + route);
		ver = pre[ver];
	}
	route = (to_string(start) + route);
	return route;
}
#endif

#ifdef TRACE_ROUTE_DIC
string trace_route_dic(long start,long goal) {
	string route("");
	long ver = start;
	while (ver != goal){
		route += (to_string(ver) + "-");
		ver = pre[ver];
	}
	route += to_string(goal);
	return route;
}

short bellman_ford_dic(long start,long goal,long V){
	short flag = bellman_ford(goal,V);
	if (ans_val == -1) cout << "exist negative loop" << endl;
	
	if (ans_val == 0){
		// 最短距離の表示
		cout << dis[start] << endl;
		// 辞書順の経路復元
		cout << trace_route_dic(start,goal) << endl;
	}
	else cerr << "error" << endl;
}
#endif

/* テンプレの入力フォーマット
V E
v11 v12 dis
v21 v22 dis
.
.
start (goal)
*/

int main(void) {
	long V,E; 
	long ver1,ver2,weight;

	//入力部分1
	cin >> V >> E; //V:頂点数 , E:辺数
	//入力部分1　ここまで
	Union_Find uf(V+1);
	edge = VVL(2*E,VL(3,0)); //　辺の端点とコストの組を格納
	dis = VL(V+1,loINF);

	//入力部分2
	for (long i = 0;i < 2*E;i+=2){ //辺の情報を入力
		cin >> ver1 >> ver2 >> weight;

		if (uf.same(ver1,ver2)){
			dis[ver1] = 0;
        	bellman_ford(ver1,V);
        	if (dis[ver2] != weight) {
        		cout << "No" << endl;
        		exit(0);
        	}
        	dis = VL(V+1,loINF); 
        }
        else {
        	edge[i][0] = ver1;
			edge[i][1] = ver2;
			edge[i][2] = weight; 
			edge[i+1][0] = ver2;
			edge[i+1][1] = ver1;
			edge[i+1][2] = -weight;
        	uf.unite(ver1,ver2);
        }		
	}	
	cout << "Yes" << endl;
 	return 0;
}


