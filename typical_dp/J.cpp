// わからん
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
typedef long long LL;
typedef pair<long,long> pr;
typedef vector<pr> VP;
typedef vector<VP> VVP;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<long> VI;
typedef vector<VI> VVI;

int main(void){
	LL N;
	cin >> N;
	LL mask = 0;
	REP(i,N){
		short x;
		cin >> x;
		mask = (mask | (1 << x));		
	}

	VVD dp(2,VD((1 << 16),0.0));
	dp[0][mask] = 1.0;
	VD tmp((1 << 16),0.0);
	double prob = 1.0 / 3.0;
	dump(prob);

	double ans = 0.0;
	short ind = 0;
	while (ind < 20){
		
		for (LL bit = 1;bit != 1 << 16;bit <<= 1){
			FOR(i,1,(1 << 16)-1){
				tmp[i & ((1 << 16)-1-bit)] += dp[0][i] * prob;
			}
			REP(i,(1 << 16)-1) dp[1][i] = max(dp[1][i],tmp[i]);
		}

		dump2d_arr(dp);
		exit(0);

		ind ++;
		ans += dp[1][0] * (double)ind;
		dump(dp[1][0]);
		dp[0] = dp[1]; // 入れ替え。
		dp[1] = tmp = VD((1 << 16),0.0);
	}

	cout << ans << endl;
	return 0;
}