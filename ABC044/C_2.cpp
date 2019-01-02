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
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vet) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }

using namespace std;
typedef vector<long long> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<short> VS;

int main(void) {
	short N,A;
	cin >> N >> A;
	VI x(N);
	long long minv = 0,maxv = 0;
	REP(i,N) {
		cin >> x[i];
		x[i] -= A;
		if (x[i] < 0) minv += (x[i]);
		else maxv += (x[i]);
	}
	long long S = maxv-minv;
	//dump(S);
	VVVI dp(N,VVI(N,VI(S+1,0)));
	REP(i,N){
		dp[i][0][x[i]-minv]++;
		if (i == 0) continue;
		REP(j,N){
			RREP(k,S){
				dp[i][j][k] += dp[i-1][j][k];
				if (k - x[i] <= S && k - x[i] >= 0 && j >= 1) dp[i][j][k] += dp[i-1][j-1][k-x[i]];
			}
		}
	}

	long long ans = 0;
	REP(i,N){
		ans += dp[N-1][i][(-minv)];
	}
	cout << ans << endl;
	return 0;
}
