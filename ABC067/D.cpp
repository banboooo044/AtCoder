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

VI route;
long count = -1;

short dfs(long ver,long prev){
	count ++;
	REP(i,edge[ver].size()){
		if (edge[ver][i] == prev) continue;
		if (edge[ver][i] == N) {
			route.push_back(ver);
			return 1;
		}
		else{
			if (dfs(edge[ver][i],ver) == 1){
				route.push_back(ver);
				return 1;
			}
		}
	}
	return 0;
}

int main (void){
	long N;
	cin >> N;
	VVI edge(N,VI(0));
	REP(i,N-1) {
		long a,b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	if (dfs(1,-1) == 1){
		#ifdef DEBUG
			dump1d_arr(route);
		#endif
		long l = route.size() - 1;
		if (l % 2) {
			FOR(i,(l / 2) + 1,l+1){
				dump(route[i]);
				count -= (edge[route[i]].size());
			} 
	}



}