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
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<pr> VP;
typedef tuple<LL,LL,LL> tp;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

LL A,B;
VI a,b;
map<tp,LL> mp;
LL dfs(LL i,LL a_idx,LL b_idx){
	tp x = tp(i,a_idx,b_idx);
	if (IN(x,mp)) return mp[x];
	if (a_idx == A && b_idx == B) return 0;
	else if (a_idx == A) {
		LL s = 0;
		for (LL j = b_idx+(i%2);j < B;j += 2) s += b[j];
		return s;
	}
	else if (b_idx == B) {
		LL s = 0;
		for (LL j = a_idx+(i%2);j < A;j += 2) s += a[j];
		return s;
	}
	if (i % 2) return mp[x] = min(dfs(i+1,a_idx+1,b_idx),dfs(i+1,a_idx,b_idx+1));
	else return mp[x] = max(dfs(i+1,a_idx+1,b_idx)+a[a_idx],dfs(i+1,a_idx,b_idx+1)+b[b_idx]);
}

int main(void) {
	cin >> A >> B;
	a = VI(A);
	b = VI(B);
	REP(i,A) cin >> a[i];
	REP(i,B) cin >> b[i];
	cout << dfs(0,0,0) << endl;
}














