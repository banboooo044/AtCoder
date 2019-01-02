#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
using namespace std;
constexpr int dx[4] = {1,0,-1,0};
constexpr int dy[4] = {0,1,0,-1};
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
typedef vector<bool> VB;
typedef pair<LL,LL> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

LL W,H,N;
VVI dp;
vector<VB> arr;
VI x,y;

bool in_arr(LL s,LL t){
	if (s >= 0 && s < (W) && t >= 0 && t < (H)) return true;
	else return false;
}
LL dfs(LL S,LL n) {
	if (n != (-1) && dp[S][n] != (-1)) return dp[S][n];
	if (S == ((1 << N)-1)) return 0;
	LL cnt,k;
	LL m = (-1);
	vector<pr> p;
	REP(i,N) {
		if (!((S >> i) & 1)) {
			cnt = 0;
			p = vector<pr>(0);
			REP(j,4) {
				k = 1;
				while(1) {
					if (!in_arr(x[i]+dx[j]*(k)-1,y[i]+dy[j]*(k)-1)) break;
					if (!arr[(y[i]+dy[j]*(k))-1][(x[i]+dx[j]*(k))-1]) break;
					arr[(y[i]+dy[j]*(k))-1][(x[i]+dx[j]*(k))-1] = false;
					p.push_back(pr(j,k));
					k++;
					cnt++;
				}
			}

			m = (max(dfs((S | (1 << i)),i)+cnt,m));
			REP(j,p.size()) {
				arr[(y[i]+dy[p[j].first]*(p[j].second))-1][(x[i]+dx[p[j].first]*(p[j].second))-1] = true;
			}
		}
	}
	if (n != (-1)) dp[S][n] = m;
	return m;
}

int main(void) {
	cin >> W >> H;
	cin >> N;
	x = VI(N);y = VI(N);
	arr = vector<VB>(H,VB(W,true));
	REP(i,N) {
		cin >> x[i] >> y[i];
		arr[y[i]-1][x[i]-1] = false;
	}
	dp = VVI((1<<N),VI(N,-1));
	LL ans = dfs(0,-1);

	cout << ans+N << endl;
}
