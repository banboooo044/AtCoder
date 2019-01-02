// C問題 部分点解法
#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define SORT(c) sort((c).begin(),(c).end())

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main (void){
	short N;
	long ans = 0;
	long pattern = 0;
	short flag;
	cin >> N;
	VI C(N,0);
	
	REP(i,N) cin >> C[i];
	#ifdef DEBUG
		cout << "ソート前" << endl;
		REP(i,N) dump1d_arr(C,i);
	#endif
	SORT(C);
	# ifdef DEBUG
		cout << "ソート後" << endl;
		REP(i,N) dump1d_arr(C,i);
	#endif
	

	do {
		pattern ++;
		ans ++;
		FOR(i,1,N){
			flag = 0;
			REP(j,i){
				if ((C[i] % C[j])==0) flag ++;
			}
			if (flag % 2 == 0) ans ++;
		}
	}while( next_permutation(C.begin(), C.end()) ); 

	#ifdef DEBUG
	 	dump(ans);
	 	dump(pattern);
	#endif

	cout << setprecision(10) << ((double)ans / (double)pattern) << endl;

	return 0;
}

/*学んだこと

	1. do { }while(next_permutation(a.begin(),a.end()))で辞書順に順番に出してくれる。全通り試したいなら配列aをソートした状態から始めよ

	2. cout << setprecision(桁数) << 少数 << endl; で少数を桁数指定して表示ができる。
*/
