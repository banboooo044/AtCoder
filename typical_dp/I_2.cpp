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

int main (void){
	string s;
	string seq = "iwi";
	cin >> s;
	short N = s.length();
	int j;

	#ifdef DEBUG
		dump(N);
		dump(s);
	#endif

	VVI dp1(N,VI(N,0));	//dp1[L][R] := 区間L~R全部消せるか
	VVI dp2(N,VI(N,0)); //dp2[L][R] := 区間L~R消せる最大数

	#ifdef DEBUG
		cout << "初期化" << endl;
	#endif

	REP(i,N-2){
		if (seq == s.substr(i,3)){
			dp1[i][i+2] = 1;
			dp2[i][i+2] = 1;
		}
	}


	#ifdef DEBUG
		cout << "実行" << endl;
	#endif
	
	FOR(i,1,N){ // 幅
		REP(j,N-i){ // leftのindex 
			short r = j + i;

			FOR(k,j,r){
				dp2[j][r] = max({dp2[j][r],dp2[j][k]+dp2[k+1][r]});
			}

			if (i % 3 != 2) continue;

			if (!((s[j] == 'i') && (s[r] == 'i'))) continue;
			//例外処理
			if (s[j+1] == 'w' && dp1[j+2][r-1]) {
				dp2[j][r] = (r - j + 1)/3;
				dp1[j][r] = 1;
				continue;
			}
			 
			if (s[r-1] == 'w' && dp1[j+1][r-2]) {
				dp2[j][r] = (r - j + 1)/3;
				dp1[j][r] = 1;
				continue;
			}

			FOR(k,j,r-1){
				if ((s[k] == 'w' && dp1[j+1][k-1] && dp1[k+1][r-1])||(dp1[j][k] && dp1[k+1][r])){
					dp2[j][r] = (r - j + 1)/3;
					dp1[j][r] = 1;
					break;
				}
			}	
		}		
	}
	

	#ifdef DEBUG
	REP(i,N) REP(l,N) dump2d_arr(dp1,i,l);
	REP(i,N) REP(l,N) dump2d_arr(dp2,i,l);

	#endif

	cout << dp2[0][N-1] << endl;
	

	return 0;
}