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
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};
int x[5][5];
vector<int> used(25,0);
vector<long> dic(25,0);
vector<long> ok;
map<LL,LL> memo;

bool can_pos(LL S,LL pos) {
	bool flg = false;
	if ((pos%5) != 0 && (pos%5) != 4 ){
		if (((S >> (pos+1)) & 1) && (!((S >> (pos-1)) & 1))) flg = true;
		if (((S >> (pos-1)) & 1) && (!((S >> (pos+1)) & 1))) flg = true;
	}
	if ((pos/5) != 0 && (pos/5) != 4 ) {
		if (((S >> (pos+5)) & 1) && (!((S >> (pos-5)) & 1))) flg = true;
		if (((S >> (pos-5)) & 1) && (!((S >> (pos+5)) & 1))) flg = true;
	}
	if (flg) return false;
	else return true;
}

LL dfs(LL S,LL num){
	if (IN(S,memo)) return memo[S];
	if (num == 25) return 1;
	if (used[num]) {
		if (can_pos(S,dic[num])) return dfs((S | (1 << dic[num])),num+1);
		else return 0;
	}
	else {
		LL pat = 0;
		REP(i,ok.size()) {
			if ((S >> (ok[i])) & 1) continue;
			if (can_pos(S,ok[i])) {
				pat += dfs((S | (1 << (ok[i]))),num+1);
				pat %= mod;
			}
		}
		return memo[S] = pat;
	}
}

int main(void) {
	REP(i,5) REP(j,5) {
		cin >> x[i][j];
		if (x[i][j] != 0) {
			used[x[i][j]-1] = 1;
			dic[x[i][j]-1] = j + 5*i;
		}
		else ok.push_back(j + 5*i);
	}
	cout << dfs(0,0)%mod << endl;
}