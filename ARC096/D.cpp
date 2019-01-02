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
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<long long,long long> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first < b.first;
	}
};


int main(void) {
	long N;
	LL C,x,v;
	cin >> N >> C;	
	VP xv(N);
	VI acc(N),accr(N);
	VI acc2(N),accr2(N);
	REP(i,N) {
		cin >> x >> v;
		xv[i] = pr(x,v);
	}
	sort(xv.begin(),xv.end(),Order());

	acc[0] = xv[0].second - xv[0].first;
	accr[0] = xv[N-1].second - (C - xv[N-1].first);
	FOR(i,1,N) {
		acc[i] = acc[i-1] + (xv[i].second - (xv[i].first-xv[i-1].first));
		accr[i] = accr[i-1] + (xv[N-i-1].second + (xv[N-i-1].first-xv[N-i].first));
	}
	acc2 = acc;
	accr2 = accr;

	FOR(i,1,N) {
		acc[i] = max(acc[i-1],acc[i]);
		accr[i] = max(accr[i-1],accr[i]);
	}

	//dump1d_arr(acc);
	//dump1d_arr(accr);
	long long ans = max(accr[N-1],acc[N-1]);
	long long sumv;
	REP(i,N-1) {
		sumv = max(acc2[i] + accr[N-i-2] - xv[i].first,acc2[i]);
		if (sumv > ans) ans = sumv;
		sumv = max(accr2[i] + acc[N-i-2] - (C - xv[N-i-1].first),accr2[i]);
		if (sumv > ans) ans = sumv;
	}
	if (ans < 0) ans = 0;
	cout << ans << endl;
}