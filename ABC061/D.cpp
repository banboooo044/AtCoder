// TLE解法
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
typedef long long LL;
typedef pair<long,long> pr;
typedef vector<LL> VL;
typedef vector<pr> VP;
typedef vector<VP> VVP;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
VVP E;
long N;
LL ans = (-9223372036854775000);

void dfs(long node,LL score,VL used){
	//dump(node);
	if (used[node] != llINF) {
		if (used[node] < score){
			cout << "inf" << endl;
			exit(0);
		}
		else return;
	}

	if (node == (N)) {
		ans = max(ans,score);
	}

	used[node] = score;

	REP(v,E[node].size()){
		dfs(E[node][v].first,E[node][v].second + score,used);
	}

	return;
}


int main(void){
	long M;
	long x,y,c;
	cin >> N >> M;
	
	E = VVP(N+1,VP(0));
	REP(i,M){
		cin >> x >> y >> c;
		E[x].push_back(pr(y,c));
	}
	VL used(N+1,llINF);
	dfs(1,0,used);
	cout << ans << endl;
	return 0;
}