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
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
typedef vector<pr> VP;

int main(void){
	short H;
	long W;
	cin >> H >> W;
	VVI P(H,VI(W,0));
	VVI F(H,VI(W,0));

	REP(i,H) {
		REP(j,W){
			cin >> P[i][j];
		}
	}
	long f;
	REP(i,H) {
		REP(j,W){
			cin >> F[i][j];
			P[i][j] -= F[i][j];
		}
	}

	VVI dp(H,VI(W,-1));
	dp[0][0] = P[0][0];
	FOR(i,1,W) dp[0][i] = dp[0][i-1] + P[0][i];
	VI left(W,-loINF);
	VI right(W,-loINF);
	FOR(j,1,W) right[j] = max({dp[0][j],dp[0][j-1]-F[0][j],right[j-1]-F[0][j]});
	RREP(j,W-2) left[j] = max({dp[0][j],dp[0][j+1]-F[0][j],left[j+1]-F[0][j]});
	REP(j,W) dp[0][j] = max(right[j],left[j]);


	FOR(i,1,H){
		REP(j,W){
			dp[i][j]  = dp[i-1][j] + P[i][j];
		}
	
		left = VI(W,-loINF);
		right = VI(W,-loINF);

		FOR(j,1,W) right[j] = max(dp[i][j-1],right[j-1]) + P[i][j];	
		RREP(j,W-2) left[j] = max(dp[i][j+1],left[j+1]) + P[i][j];
		REP(j,W) dp[i][j] = max({dp[i][j],right[j],left[j]});

		left = VI(W,-loINF);
		right = VI(W,-loINF);
		FOR(j,1,W) right[j] = max({dp[i][j],dp[i][j-1]-F[i][j],right[j-1]-F[i][j]});
		RREP(j,W-2) left[j] = max({dp[i][j],dp[i][j+1]-F[i][j],left[j+1]-F[i][j]});
		REP(j,W) dp[i][j] = max(right[j],left[j]);
	}

	REP(i,W) cout << dp[H-1][i] << endl;
	return 0;
}