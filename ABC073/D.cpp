// Rの数がmax8だったので組み合わせで処理可能
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
//#define TRACE_ROUTE
using namespace std;
typedef vector<long> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;

VVL dist;
VL r;
long V,R;
#ifdef TRACE_ROUTE
	VVL nex;
#endif

short Warshall_Floyd(void){
	// 頂点は 0 ~ V 
	REP(i,V+1) dist[i][i] = 0;	//初期化
	FOR(i,1,V+1){
		FOR(j,1,V+1){
			FOR(k,1,V+1){
				if (dist[j][i] == loINF || dist[i][k] == loINF) continue;
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
	return 0;
}

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

/*long rec(long var,VB visited,long past){
	#ifdef DEBUG
		dump(var);
		dump(past);
	#endif

	VL nextvar;
	long dis = loINF;
	char flag = 0;
	REP(i,R) {
		if (!visited[i]) {
			flag = 1;
			if (dist[var][r[i]] <= dis) {
				if (dist[var][r[i]] < dis) {
					nextvar = VL(1,i);
					dis = dist[var][r[i]];
				}
				else nextvar.push_back(i);
			}
		}
	}
	if (!flag) return past;
	long ans = loINF;
	REP(i,nextvar.size()) {
		VB v = visited;
		v[nextvar[i]] = true;
		ans = min(rec(r[nextvar[i]],v,past+dis),ans);
	}
	return ans;
}*/

int main(void){
	long E;//頂点数,辺数
	cin >> V >> E >> R;
	r = VL(R);

	REP(i,R) cin >> r[i];

	dist = VVL(V+1,VL(V+1,loINF));
	#ifdef TRACE_ROUTE
		nex = VVL(V+1,VL(V+1,0));
		REP(i,V+1) REP(j,V+1) nex[i][j] = j;
	#endif

	REP(i,E){
		long v1,v2,dis;
		cin >> v1 >> v2 >> dis;
		dist[v1][v2] = dis;
		dist[v2][v1] = dis;
	}
	#ifdef DEBUG
		cout << "input_finish" << endl;
	#endif

	long ans_val = loINF;
	long retval = Warshall_Floyd();
	#ifdef DEBUG
		cout << "Warshall_Floyd_end" << endl;
		dump2d_arr(dist);
	#endif

	if (retval == (-1)) cout << "NEGATIVE CYCLE" << endl;
	else {
		if (retval == 0){
			SORT(r);
			do {
				long sum = 0;
				FOR(i,1,R){
					sum += dist[r[i-1]][r[i]];
				}
				ans_val = min(sum,ans_val);
			}while(next_permutation(r.begin(), r.end()));
			/*REP(i,R) {
				VB visited(R,false);
				visited[i] = true;
				ans_val = min(rec(r[i],visited,0),ans_val);
				#ifdef DEBUG
					dump(ans_val);
				#endif
			}*/
		}
	}
		cout << ans_val << endl;
	return 0;
}