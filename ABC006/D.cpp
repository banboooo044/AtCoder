/*挿入ソートの回数*/
/*最長増加部分列のdpに帰着する*/

#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define loINF (long)10000000000
#define shINF (short)10000

using namespace std;
typedef vector<int> VI;

int main(void){
	long N;
	long maxval;
	cin >> N;

	VI C(N,0);
	REP(i,N) cin >> C[i];

	VI dp(N+1,0);


	
	FOR(i,1,N+1){
		maxval = 0;
		FOR(j,1,C[i-1]+1){
			if (j == C[i-1]){
				dp[j] = maxval + 1;
			}
			maxval = MAX(dp[j],maxval);
		}
	}

	maxval = 0;
	REP(i,N+1) maxval = MAX(dp[i],maxval);
	cout << (N - maxval) << endl;

	return 0;
}


/*イメージはむしろこっち
 	dp[深さ][最大の数] := 数列の長さ


	FOR(i,1,N+1){
		maxval = 0;
		FOR(j,1,N+1){
			// C[i-1]より小さいなら、値はそのまま。この中から最大値を見つけておく
			if (j < C[i-1]){
				dp[i][j] = dp[i-1][j];
				maxval = MAX(dp[i][j],maxval);
			}
			// 最大の値がC[i-1]になったら見つけておいた最大値に1を足す。
			else { 
				if (j == C[i-1]){
					dp[i][j] = maxval + 1;
				}
			
				// C[i-1]より大きい場合は、何も変わらないのでそのまま代入
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}


	===> これらのプログラムをメモリの節約技術を用いて、高速化する。
*/