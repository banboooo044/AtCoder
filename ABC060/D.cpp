// 制約的にdpはダメ。
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

using namespace std;
typedef vector<long long> VI;
typedef vector<VI> VVI;

int main(void){
	long N,W;
	cin >> N >> W;
	VI w(N),v(N);

	REP(i,N){
		cin >> w[i] >> v[i];
	}

	if (W < 0){
		 cout << 0 << endl;
		 exit(0);
	}

	dump1d_arr(w);
	dump1d_arr(v);

	VVI dp(N+1,VI(W+1,0));

	FOR(i,1,N+1){
		FOR(j,1,W+1){
			if (j - w[i-1] < 0) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			else dp[i][j] = max({dp[i-1][j - w[i-1]] + v[i-1],dp[i][j-1],dp[i-1][j]});
		}
	}

	//dump2d_arr(dp);

	cout << dp[N][W] << endl;

	return 0;
}