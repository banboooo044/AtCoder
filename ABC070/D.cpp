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
#define ALL_VERTEX  // option2

using namespace std;
typedef pair<long,long> pr;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};
typedef priority_queue<pr,vector<pr>,Order> pq;
typedef vector<char> VC;
typedef vector<long> VL;
typedef vector<VL> VVL;
typedef vector<pr> VP;
typedef vector<VP> VVP;

// global変数
VVP cost;	//辺の情報

#ifdef ALL_VERTEX
	VL ans;
#endif // ALL_VERTEX

#ifdef TRACE_ROUTE
	VL trace;
#endif // TRACE_ROUTE

// 最短距離を返す ,  -1 :連結でない , loINF : ALL_VERTEX , 
long dijekstra(long start,long end,long V){
	pq distance;
	pr minver;
	VC used(V+1,0);

	#ifdef ALL_VERTEX
		ans = VL(V+1,loINF); 
		end = -(loINF);
	#endif // ALL_VERTEX

	distance.push(make_pair(0,start));	//初期化 スタートの頂点は距離0

	while (!distance.empty()) {
		minver = distance.top();
		distance.pop();
		if (used[minver.second]) continue; //すでに使った頂点なら飛ばす

		#ifdef TRACE_ROUTE
			trace.push_back(minver.second); // 経路復元用に、確定した頂点の情報を格納
		#endif

		if (minver.second == end) break; //ゴールについたらやめる 
		else {
			used[minver.second] = 1;    //頂点を使ったことを記録
			#ifdef ALL_VERTEX
				ans[minver.second] = minver.first;
			#endif // ALL_VERTEX
		}

		REP(i,cost[minver.second].size()) {
			if (used[cost[minver.second][i].first]) continue;
			distance.push(make_pair(minver.first+cost[minver.second][i].second,cost[minver.second][i].first));
		}	
	}
	#ifndef ALL_VERTEX
		if (minver.second == end) return minver.first; //最小距離を返す
		else return -1;
	#endif	
	return loINF; // 全ての頂点の最短距離を調べた。(ansを見る)
}

/* テンプレの入力フォーマット
V E
v11 v12 dis
v21 v22 dis
.
.
start (goal)
*/

int main (void){
	long V,Q;
	long ver1,ver2,dis;

	//入力部分1
	cin >> V;	//V:頂点数 , E:辺数
	//入力部分1　ここまで


	#ifdef ALL_VERTEX
	ans = VL(V+1,0); 
	#endif
	cost = VVP(V+1,VP(0)); // 隣接リスト

	//入力部分2
	REP(i,V-1){ //辺の情報を入力
		cin >> ver1 >> ver2 >> dis;
		/*有向グラフ ver1 ==> ver2 */
		cost[ver1].push_back(make_pair(ver2,dis));
		cost[ver2].push_back(make_pair(ver1,dis));
	}
	//入力部分2ここまで

	//入力部分3
	long start,x,y;
	cin >> Q >> start;
	//入力部分3ここまで
	VL query_result(Q);

	#ifdef ALL_VERTEX 
		if (dijekstra(start,loINF,V) == loINF){
			REP(i,Q){
				cin >> x >> y;
				query_result[i] = ans[x] + ans[y];
			}
		}
		else cerr << "error" << endl;

		REP(i,Q) cout << query_result[i] << endl;
		exit(0);
	#endif

	//入力部分4(二点間の距離を求める時のみ)
	long end;
	cin >> end;	//終点を入力
	//入力部分4ここまで

	long ans_val = dijekstra(start,end,V);
	
	if (ans_val == -1) cerr << "Not Connected" << endl; //連結でなかった場合。
	else {
		#ifdef TRACE_ROUTE
			REP(i,trace.size()) cout << trace[i] << endl; //経路復元
		#endif
		cout << ans_val << endl; 	//最短距離の表示
	}

 	return 0;
 }