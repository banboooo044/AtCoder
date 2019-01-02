// ワーシャルフロイド法自作ライブラリ
/* option1 経路復元 start,endを指定することで、任意の二点間の最短距離の経路を表示*/
#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define loINF 2147483647
//#define TRACE_ROUTE
using namespace std;

typedef vector<long> VI;
typedef vector<VI> VVI;
vector<vector<long>> dist;
#ifdef TRACE_ROUTE
	vector<vector<long>> nex;
#endif

short Warshall_Floyd(long V){
	// 頂点は 0 ~ V 
	REP(i,V+1) dist[i][i] = 0;	//初期化
	FOR(i,1,V+1){
		FOR(j,1,V+1){
			FOR(k,1,V+1){
				if (dist[j][i] == 2147483647 || dist[i][k] == 2147483647) continue;
				if (dist[j][k] > dist[j][i] + dist[i][k]){
					dist[j][k] = dist[j][i] + dist[i][k];
					#ifdef TRACE_ROUTE
						nex[j][k] = nex[j][i];
					#endif
				}
				#ifdef TRACE_ROUTE
				else {
					if (j != i && dist[j][k] == dist[j][i] + dist[i][k])
						nex[j][k] = min({nex[j][i],nex[j][k]});
				}
				#endif
				if (dist[j][j] < 0) return (-1);
			}
		}
	}

	//dump2d_arr(dist);
	return 0;
}

int main(void){
	long V,E;	//頂点数,辺数
	cin >> V >> E;

	dist = VVI (V+1,VI(V+1,loINF));


	#ifdef TRACE_ROUTE
		nex = vector<vector<long>>(V+1,vector<long>(V+1,0));
		REP(i,V+1) REP(j,V+1) nex[i][j] = j;
	#endif

	REP(i,E){
		long v1,v2,dis;
		cin >> v1 >> v2 >> dis;
		dist[v1][v2] = dis;
		dist[v2][v1] = dis;
	}
	VVI e = dist;
	//dump2d_arr(e);

	long retval = Warshall_Floyd(V); // 頂点数に気をつける。

	long cnt = 0;

	FOR(i,1,V+1){
		FOR(j,1,V+1){
			if (e[i][j] != loINF && e[i][j] > dist[i][j]) cnt++;
		}
	}
	cout << cnt/2 << endl;

}



// 経路復元用
#ifdef TRACE_ROUTE
string trace_route(long start ,long goal){
	string route("");
	long current;
	for(current = start;current!=goal;current = nex[current][goal])
		route += (to_string(current) + "-");
	route += to_string(goal);
	return route;
}
#endif