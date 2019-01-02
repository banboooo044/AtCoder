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

constexpr long mod = 1000000007;

int main(void){
	long H,W,A,B;
	cin >> H >> W >> A >> B;
	long l = min(A,H-A);
	long m = max(A,H-A);

	VVI route(2,VI(W,0));
	VI up(W);
	REP(i,W) route[0][i] = 1;
	REP(i,H-1) {
		if (i == (l-1)) up = route[0];
		if (i == (m-1)) break;
		route[1][0] = 1;
		FOR(j,1,W){
			route[1][j] = route[0][j] + route[1][j-1];
		}
		route[0] = route[1];	
	}

	dump1d_arr(up);
	dump1d_arr(route[0]);

	long ans = 0L;
	if (A >= (H-A)){
		REP(i,W-B) ans += ((up[i+B] * route[0][W-B-i-1]) % mod);
	}
	else {
		REP(i,W-B) ans += ((up[W-B-i] * route[0][i+B-1]) % mod);
	}

	cout << ans << endl;


	return 0;
}