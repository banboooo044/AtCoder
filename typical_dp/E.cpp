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
#define MOD 1000000007
//#define DEBUG
using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI; 
typedef vector<VVI> VVVI;

int main(void){
	long D;
	string N;
	cin >> D;
	cin >> N;

	long l = N.length();

	VVVI dp(l+1,VVI(2,VI(D,0)));
	dp[0][0][0] = 1;

	REP(i,l){
		REP(j,2){
			long limit;
			string M = N.substr(i,1);
			if (!j) limit = stol(M);
			else limit = 9;
			REP(k,D){
				REP(m,limit+1){
					dp[i+1][j || m < limit][(k + m) % D] = ((dp[i+1][j || m < limit][(k + m) % D] + (dp[i][j][k])) % MOD);
				}
			}
		}
	}

	cout << dp[l][1][0]-1 << endl;

	#ifdef DEBUG
		REP(i,l+1) REP(j,2) REP(k,D) cerr << "dp[" << i << "][" << j << "][" << k <<  "] ==> " << dp[i][j][k] << endl;
	#endif

	return 0;
}