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
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

int main(void) {
	long N,K;
	cin >> N >> K;
	VVI arr1(K,VI(K,0)),arr2(K,VI(K,0));
	long x,y;
	char c;
	REP(i,N) {
		cin >> x >> y >> c;
		x %= (2*K);y %= (2*K);
		if ((x < K  && y < K) || (x >= K && y >= K)) {
			if (c == 'B') arr1[y%K][x%K] += 1;
			else arr2[y%K][x%K] += 1;
		}
		else {
			if (c == 'W') arr1[y%K][x%K] += 1;
			else arr2[y%K][x%K] += 1;
		}
	}
	REP(i,K) REP(j,K-1) {
		arr1[i][j+1] += arr1[i][j];
		arr2[i][j+1] += arr2[i][j];
	}
	REP(i,K-1) REP(j,K) {
		arr1[i+1][j] += arr1[i][j];
		arr2[i+1][j] += arr2[i][j];
	}

	//dump2d_arr(arr1);
	//dump2d_arr(arr2);
	LL ans = 0;
	LL m,n;
	REP(i,K) {
		REP(j,K) {
			if (i == 0 && j == 0) {
				ans = max(arr1[K-1][K-1],ans);
				ans = max(arr2[K-1][K-1],ans);
			}
			else if (i == 0) {
				m = arr1[K-1][K-1] - arr1[K-1][j-1];
				n = arr2[K-1][j-1];
				ans = max(ans,m+n);
				m = arr2[K-1][K-1] - arr2[K-1][j-1];
				n = arr1[K-1][j-1];
				ans = max(ans,m+n);
			}
			else if (j == 0) {
				m = arr1[K-1][K-1] - arr1[i-1][K-1];
				n = arr2[i-1][K-1];
				ans = max(ans,m+n);
				m = arr2[K-1][K-1] - arr2[i-1][K-1];
				n = arr1[i-1][K-1];
				ans = max(ans,m+n);
			}
			else {
				m = arr1[K-1][K-1] - arr1[i-1][K-1] - arr1[K-1][j-1] + 2*arr1[i-1][j-1];
				n = (arr2[K-1][j-1] - arr2[i-1][j-1]) + (arr2[i-1][K-1] - arr2[i-1][j-1]);
				ans = max(ans,m+n);
				m = arr2[K-1][K-1] - arr2[i-1][K-1] - arr2[K-1][j-1] + 2*arr2[i-1][j-1];
				n = (arr1[K-1][j-1] - arr1[i-1][j-1]) + (arr1[i-1][K-1] - arr1[i-1][j-1]);
				ans = max(ans,m+n);
			}
		}
	}
	cout << ans << endl;
}