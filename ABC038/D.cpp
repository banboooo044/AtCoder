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
typedef pair<long,long> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first < b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

template <typename T>
T LIS(vector<T> const& seq) {
	const long n = seq.size();
	vector<long> id(n);
	vector<long> dp(n,loINF);
	for (long i = 0;i < n;i++ ) {
		id[i] = (lower_bound(dp.begin(),dp.end(),seq[i]) - dp.begin());
		dp[id[i]] = seq[i];
	}
	long m = *max_element(id.begin(),id.end());
	return (m+1);
}

int main(void) {
	long N,h,w;
	cin >> N;
	VP box(N);
	VI W(N);
	VI dp(N,loINF);
	// dp[i] := 長さiの部分列の最小の数
	REP(i,N) {
		cin >> w >> h;
		box[i] = pr (w,h);
	}
	sort(box.begin(),box.end(),Order());
	REP(i,N) {
		W[i] = box[i].second;
	}
	cout << LIS<long>(W) << endl;
	return 0;
}