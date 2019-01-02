#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI; 


int main (void){
	string a,a1,b;
	short size_a,size_b;
	LL ans;

	LL tmp_A;

	cin >> a1 >> b;

	tmp_A = stoll(a1);
	a = to_string(tmp_A-1);

	size_a = a.length();
	size_b = b.length();

	#ifdef DEBUG
		cout << "INPUT CHECK"  << endl ;
		dump(a);
		dump(b);
	#endif

	{
	VVVI dp(size_a+1,VVI(2,VI(2,0)));
	dp[0][0][0] = 1;

	/*dp[i][j][k] := i番目まで jはb以下であるtrue or false , kは4または9が含まれているか*/

	REP(i,size_a){
		REP(j,2){
			REP(k,2){
				short limit = 9;
				if (!j) limit = (int)a[i] - 48;

				REP(l,limit+1){
					dp[i+1][j || l < limit][k || l == 4 || l == 9] += dp[i][j][k];
				}
			}
		}
	}

	ans = (-(dp[size_a][1][1] + dp[size_a][0][1]));

	#ifdef DEBUG
		dump(ans);
	#endif
	}

	{
	VVVI dp(size_b+1,VVI(2,VI(2,0)));
	dp[0][0][0] = 1;

	REP(i,size_b){
		REP(j,2){
			REP(k,2){
				short limit = 9;
				if (!j) limit = (int)b[i] - 48;

				REP(l,limit+1){
					dp[i+1][j || l < limit][k || l == 4 || l == 9] += dp[i][j][k];
				}
			}
		}
	}
	#ifdef DEBUG
		dump(dp[size_b][0][1] + dp[size_b][1][1]);
	#endif

	ans += (dp[size_b][0][1] + dp[size_b][1][1]);
	}

	cout << ans << endl;

	return 0;
}