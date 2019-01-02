#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>=(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define llINF (long long) 9223372036854775807
#define loINF (long) 2147483647
#define shINF (short) 32767
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;


int main(void){
	short N,Ma,Mb;
	cin >> N >> Ma >> Mb;
	VI a(N),b(N),c(N);

	REP(i,N){
		cin >> a[i] >> b[i] >> c[i];
	}


	long h = MAX(a)*N;
	long w = MAX(b)*N;

	VVI dp(h+1,VI(w+1,loINF));
	dp[0][0] = 0;

	REP(i,N){
		RFOR(j,h,a[i]){
			RFOR(k,w,b[i]){
				if (dp[j-a[i]][k-b[i]] != loINF){
					dp[j][k] = min(dp[j-a[i]][k-b[i]]+c[i],dp[j][k]);
				}
			}
		}
	}

	//dump2d_arr(dp);

	long ans =  loINF;

	for (long i = 1; i * Ma < h && i * Mb < w;i++){
		if (dp[i*Ma][i*Mb] != loINF) ans = min(ans,dp[i*Ma][i*Mb]);
	}

	if (ans == loINF) cout << (-1) << endl;
	else cout << ans << endl;

	return 0;
}