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
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vec) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef pair<long,long> pr;
typedef vector<pr> VP;
constexpr long mod = 1000000007;

VVI e;
VVI dp;
void dfs (long node,long prev) {
	bool flg = true;
	//dump(node);
	REP(i,e[node].size()){
		long next = e[node][i];
		if (next != prev){
			dfs(next,node);
			dp[node][1] *= (dp[next][0] % mod);
			dp[node][1] %= mod;
			dp[node][0] *= ((dp[next][1] + dp[next][0])%mod);
			dp[node][0] %= mod;
			flg = false;
		}
 	}
 	if (flg) dp[node][0] = dp[node][1] = 1;
}

int main(void) {
	long N,a,b;
	cin >> N;
	e = VVI(N,VI(0));
	REP(i,N-1) {
		cin >> a >> b;
		e[a-1].push_back(b-1);
		e[b-1].push_back(a-1);
	}
	//dump2d_arr(e);
	dp = VVI(N,VI(2,1));
	dfs(0,-1);
	cout << (dp[0][0] + dp[0][1])%mod << endl;
	return 0;
}