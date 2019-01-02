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
#define llINF_ (long long) 9223372036850000000
#define loINF (long) 2147483647
#define shINF (short) 32767
#define SORT(c) sort((c).begin(),(c).end())
using namespace std;

typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;

int main(void){
	short H;
	LL W,from_left = (-llINF_),from_right=(-llINF_);
	cin >> H >> W;
	VVI P(H,VI(W,0));
	VVI F(H,VI(W,0));
	VI right_move(W,0);
	VI left_move(W,0);

	REP(i,H) REP(j,W) cin >> P[i][j];
	REP(i,H) REP(j,W) cin >> F[i][j];

	VI dp(W,-llINF_);
	dp[0] = 0LL;
	VI dp_spare(W);
	
	REP(h,H){
		from_left = (-llINF_),from_right=(-llINF_);
		// right_move
		RREP(i,W-1) {
			if (i != W-1) right_move[i] =  max(right_move[i+1]+ P[h][i+1] - F[h][i+1] - F[h][i],0LL);		
		}
		//left_move
		REP(i,W){
			if (i != 0) left_move[i] = max(left_move[i-1] + P[h][i-1] - F[h][i-1] - F[h][i] ,0LL);
		}
		
		REP(i,W) dp_spare[i] = dp[i];

		REP(i,W){
			from_left = max(dp_spare[i] + left_move[i],from_left) + P[h][i] - F[h][i];
			dp[i] = from_left+ right_move[i];
		}

		RREP(i,W-1) {
			from_right = max(dp_spare[i] + right_move[i],from_right) + P[h][i] - F[h][i];
			dp[i] = max(dp[i],from_right + left_move[i]);
		}

		#ifdef DEBUG
			dump1d_arr(right_move);
			dump1d_arr(left_move);
			
			dump1d_arr(dp);
		#endif
	}

	REP(i,W) cout << dp[i] << endl;

	return 0;
}