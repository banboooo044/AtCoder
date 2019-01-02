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
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

int main(void) {
	long N,D;
	cin >> N >> D;
	VI X(N);
	REP(i,N) cin >> X[i];
	long l = 0;
	long r = 2;
	long ans = 0;
	long lb,ub,mid,lm,um;
	while (l < N) {
		while (r < N && X[r] - X[l] <= D) {
			r++;
		}
		if (r == N) break;
		if (X[r] - X[l] <= D) break;
		lb = l+1;
		ub = r-1;
		while (lb <= ub){
			mid = (lb+ub)/2;
			if (X[mid] - X[l] <= D) {
				lb = mid + 1;
				um = mid;
			}
			else ub = mid - 1;
		}
		lb = l + 1;
		ub = r - 1;
		while (lb <= ub){
			mid = (lb+ub)/2;
			if (X[r] - X[mid] <= D) {
				ub = mid - 1;
				lm = mid;
			}
			else lb = mid + 1;
		}
		incre = max((um - lm + 1),0L);
		ans += incre;
		if (incre == 0 || r == (N-1)){
			if (updr) r = minr;
			updr = false;
			l++;
		}
		else r++;
	}
	cout << ans << endl;
}