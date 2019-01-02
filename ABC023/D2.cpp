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
#define ROUND(N) setprecision(N)

using namespace std;
typedef long long LL;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

int main(void) {
	long N;
	cin >> N;
	vector<LL> H(N),S(N),limit(N);
	REP(i,N) cin >> H[i] >> S[i];
	LL l = 0;
	LL r = 100000000000000;
	LL mid;
	LL ans;
	bool flg;
	while (l <= r) {
		mid = (l + r) / 2;
		flg = false;
		REP(i,N) {
			if (mid - H[i] < 0) {
				flg = true;
				break;
			}
			else {
				limit[i] = (mid - H[i]) / S[i];
			}
		}
		if (flg) {
			l = mid + 1;
			continue;
		}
		SORT(limit);
		flg = false;
		REP(i,N) {
			if (limit[i] < i) {
				flg = true;
				break;
			}
		}
		if (flg) l = mid+1;
		else {
			ans = mid;
			r = mid-1;
		}
	}
	cout << ans << endl;
}