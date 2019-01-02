#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define loINF (long)10000000000
#define shINF (short)10000
#define SORT(c) sort((c).begin(),(c).end())

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main(void){
	string S,T;
	cin >> S;
	cin >> T;
	short s = 0;
	short t = 0;
	short slen = S.length();
	short tlen = T.length();

	VVI dp(slen+1,VI(tlen+1,0));

	dp[0][0] = 1;
	FOR(i,1,slen+1){
		 dp[i][0] = ((S[i-1] == 'A') && dp[i-1][0]);
	}
	FOR(j,1,tlen+1){
		 dp[0][j] = ((T[j-1] == 'B') && dp[0][j-1]);
	}

	FOR(i,1,slen+1){
		FOR(j,1,tlen+1){
			dp[i][j] = ((dp[i-1][j-1] && (S[i-1] == T[j-1])) || (dp[i-1][j] && S[i-1] == 'A') || (dp[i][j-1] && T[j-1] == 'B'));
		}
	}

	#ifdef DEBUG 
		REP(i,slen+1) REP(j,tlen+1) dump2d_arr(dp,i,j);
	#endif

	if (dp[slen][tlen]) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
