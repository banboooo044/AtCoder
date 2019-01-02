#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h,w,x,y) (0 <= y && y < h && 0 <= x && x < w)
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<bool> VB;
typedef vector<pr> VP;
typedef priority_queue<pr,vector<pr>,greater<pr>> pq;
long inf,sup;
vector<vector<pair<long,long>>> E;
VVI limit;
int dfs(long node,long val,bool odd) {
	if (odd) {
		if (limit[node][1] != loINF){
			if (limit[node][1] != (val-1) ) return (1);
			else return 0;
		}
		limit[node][1] = (val-1);
		int flg = 0;
		REP(i,E[node].size()) {
			long next = E[node][i].first;
			long s = E[node][i].second;
			flg |= dfs(next,s-val,false);
		}
		return flg;
	}
	else {
		if (limit[node][0] != loINF){
			if (limit[node][0] != (-val)+1 ) return (1);
			else return 0;
		}
		limit[node][0] = (-val)+1;
		int flg = 0;
		REP(i,E[node].size()) {
			long next = E[node][i].first;
			long s = E[node][i].second;
			flg |= dfs(next,s-val,true);
		}
		return flg;
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	long n,m,u,v,s;
	cin >> n >>  m;
	E.resize(n);
	limit = VVI(n,VI(2,loINF));
	REP(i,m) {
		cin >> u >> v >>  s;
		E[u-1].emplace_back(v-1,s);
		E[v-1].emplace_back(u-1,s);
	}
	inf = 1;sup = loINF;
	if (dfs(0,0,false)) cout << 0 <<  endl;
	else {
		long long inf = 0,sup = loINF;
		REP(i,n) {
			if (limit[i][0] != loINF) inf = max(inf,limit[i][0]);
			if (limit[i][1] != loINF) sup = min(sup,limit[i][1]);
		}
		if (sup >= inf) cout << sup - inf + 1 << endl;
		else cout << 0 << endl;
	}
}
