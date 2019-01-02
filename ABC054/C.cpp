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
typedef vector<bool> VB;
short N,M;
long cnt = 0;
VVI edge;

void dfs(long node,bitset<8> used){
	//dump(node);
	//dump(used.to_ulong());
	if (used[node]) return;

	used.set(node);
	if(used.count() == N){
		cnt++;
		return;
	} 

	REP(i,edge[node].size()){
		dfs(edge[node][i],used);
	}
	return;
}

int main(void){
	cin >> N >> M;
	edge = VVI(N,VI(0));
	short a,b;
	REP(i,M){
		cin >> a >> b;
		edge[a-1].push_back(b-1);
		edge[b-1].push_back(a-1);
	}

	dfs(0,bitset<8>(0));

	cout << cnt << endl;

	return 0;
}