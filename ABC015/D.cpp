// ナップザック問題亜種

#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
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
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

/*dp[i][幅][K] := (重要度)*/
/*Kでメモリ節約*/

int main(void){
	short W;
	short N,K;
	cin >> W;
	cin >> N >> K;
	VI A(N,0);
	VI B(N,0);
	REP(i,N) cin >> A[i] >> B[i];

	VVVI dp(N+1,VVI(W+1, VI(K+1,0)));


	FOR(i,1,N+1){
		REP(j,W+1){
			FOR(k,1,K+1){
				if (j - A[i-1] >= 0)
					dp[i][j][k] = MAX(dp[i-1][j-A[i-1]][k-1] + B[i-1],dp[i-1][j][k]);
				else{ dp[i][j][k] = dp[i-1][j][k];}
			}
		}
	}

	#ifdef DEBUG

	REP(i,W+1) 
		REP(j,K+1)
			dump2d_arr(dp[N],i,j);
	#endif //(DEBUG) 

	cout << dp[N][W][K] << endl;
	
	return 0;	

}
