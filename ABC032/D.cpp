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
typedef vector<long> VI;
typedef vector<long long> VL;
typedef vector<VL> VVL;
typedef pair<long long,long long> pr;
typedef vector<pr> VP;
typedef map<pr,long long> mp; 
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.second < b.second;
	}
};

long N,W;
VP vw;
mp memo;
long long dfs(long i,long weight) {
	if (IN(pr(i,weight),memo)) return memo[pr(i,weight)];
	if (i == N) return 0;
	if (weight + vw[i].second > W) return 0;
	else return memo[pr(i,weight)] = max(dfs(i+1,weight),dfs(i+1,weight+vw[i].second)+vw[i].first);
}

int main(void) {
	cin >> N >> W;
	long  maxv = 0,maxw = 0;
	long long ans = 0;
	if (N <= 30) {
		vw = VP(N);
		REP(i,N) cin >> vw[i].first >> vw[i].second;
		sort(vw.begin(),vw.end(),Order());
		cout << dfs(0,0) << endl;
	}
	else {
		VVL dp;
		VI v(N),w(N);
		REP(i,N) {
			cin >> v[i] >> w[i];
			maxv = max(v[i],maxv);
			maxw = max(w[i],maxw);
		}
		if (maxw <= 1000) {
			long M = maxw*N+1;
			dp = VVL(N+1,VL(M+1,0));
			FOR(i,1,N+1) {
				REP(j,M+1) {
					if (j - w[i-1] >= 0) dp[i][j] = dp[i-1][j - w[i-1]] + v[i-1];
					dp[i][j] = max(dp[i][j],dp[i-1][j]);
				}
			}
			REP(j,min((M+1),W+1)) {
				if (dp[N][j] > ans) ans = dp[N][j];
			}
			cout << ans << endl;	
		}
		if (maxv <= 1000) {
			long M = maxv*N+1;
			dp = VVL(N+1,VL(M+1,loINF));
			dp[0][0] = 0;
			FOR(i,1,N+1) {
				REP(j,M+1) {
					if (j - v[i-1] >= 0) dp[i][j] = dp[i-1][j - v[i-1]] + w[i-1];
					dp[i][j] = min(dp[i][j],dp[i-1][j]); 
				}
			}
			//dump2d_arr(dp);
			REP(i,M+1) {
				if (dp[N][i] <= W && ans < i) ans = i;
			}
			cout << ans << endl;	
		}
	}
	return 0;
}