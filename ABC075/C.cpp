#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define loINF (long)10000000000
#define shINF (short)10000
#define SORT(c) sort((c).begin(),(c).end())

using namespace std;
typedef vector<short> VI;
typedef vector<VI> VVI;
typedef map<short,VI> mp;

VI ver_oreder; //辺の通った順番 ==> 辺の値
VVI vertex;	// 辺の lowと番号を持ってる。
mp edge;

void update_low(short low,short i){ // low:更新する値 i:通った順番
	#ifdef DEBUG
		cout << "update_low_run" << endl;
		dump(low);
		dump(i);
	#endif

	if (low != i){
		vertex[i][1] = min({low,vertex[i][1]});
		update_low(low,vertex[i][0]-1);
	}
}

void dfs(short i,short j){ // i:頂点の番号 j:頂点の番号(一個前)
	#ifdef DEBUG
		dump(i);
		dump(j);
	#endif

	if (vertex[i][0] == shINF) {
		vertex[i][0] = vertex[j][0] + 1;
		vertex[i][1] = vertex[j][0] + 1;
		ver_oreder[vertex[i][0]] = i;

		REP(k,edge[i].size()){
			if (edge[i][k] != j) dfs(edge[i][k],i);
		}
 		return;
	}

	else {
		if (vertex[i][1] == vertex[j][1]) return;
		vertex[j][1] = min({vertex[i][1],vertex[j][1]});
		short low = vertex[i][1];
		for(int k = vertex[j][0] - 1;k > low;k--){
			vertex[ver_oreder[k]][1] = min({low,vertex[ver_oreder[k]][1]}); 
		}
	}
}


int main (void){
	short N,M;
	long ans = 0;
	cin >> N >> M;
	vertex = VVI(N+1,VI(2,shINF)); //配列[0]が何番目をみているか、配列[1]が最小の到達元。(初期値は配列[0])
	ver_oreder = VI(N+1,0);
	vertex[0][0] = 0;
	vertex[0][1] = 0;

	REP(i,M) {
		short a,b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	#ifdef DEBUG
	cout << "INPUT CHECK" << endl;
		REP(i,N+1) REP(j,2) dump2d_arr(vertex,i,j);
		REP(i,N+1) REP(j,edge[i].size()) dump2d_arr(edge,i,j);
	#endif

	dfs(1,0);

	#ifdef DEBUG
	cout << "dfs CHECK" << endl;
		REP(i,N+1) REP(j,2) dump2d_arr(vertex,i,j);
		REP(i,N+1) dump1d_arr(ver_oreder,i);
	#endif

	FOR(i,2,N+1){
		if (vertex[i][0] == vertex[i][1]) ans++;
	}
	cout << ans << endl;
	return 0;

}
