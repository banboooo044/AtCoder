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

long fractal(short n){
	if (n == 1) return 1;
	return n * fractal(n-1);
}

int main (void){
	short N;
	double ans;
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
	VI divisor(N,0);

	REP(i,N){
		REP(j,N){
			if ((i != j) && (C[i] % C[j] == 0)) divisor[i]++;
		}
	}

	REP(i,N){ 
		short div = divisor[i];
		if(div%2){//奇数個の時 ==> 表が多い。
			ans += (0.5);
		}
		else { //裏が多い
			ans += (((double)(div+2))/((double)(div*2+2)));
		}
	}

	#ifdef DEBUG
		REP(i,N) dump1d_arr(divisor,i);
	#endif

	cout << setprecision(10) << ans << endl;

	return 0;

}