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
typedef tuple<LL,LL,LL,LL> tp;

LL W,H,N;
map<tp,LL> memo;
VI X,Y;
LL dfs(tp ran) {
	if (IN(ran,memo)) return memo[ran];
	LL x1 = get<0>(ran);
	LL y1 = get<1>(ran);
	LL x2 = get<2>(ran);
	LL y2 = get<3>(ran);
	LL ret = 0,tmp,del = (x2-x1+y2-y1+1);
	REP(i,N) {
		if (x1 <= X[i] && x2 >= X[i] && y1 <= Y[i] && y2 >= Y[i]){
			tmp = dfs(tp(x1,y1,X[i]-1,Y[i]-1)) 
				+ dfs(tp(x1,Y[i]+1,X[i]-1,y2))
				+ dfs(tp(X[i]+1,y1,x2,Y[i]-1))
				+ dfs(tp(X[i]+1,Y[i]+1,x2,y2));
			ret = max(ret,(tmp+del));
		}
	}
	return memo[ran] = ret;
}

int main(void) {
	cin >> W >> H;
	cin >> N;
	X = VI(N);
	Y = VI(N);
	REP(i,N) {
		cin >> X[i] >> Y[i];
		X[i] -= 1;
		Y[i] -= 1;
	}
	cout << dfs(tp(0,0,W-1,H-1)) << endl;
}






