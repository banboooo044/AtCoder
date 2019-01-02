// A - Bに辺が必要ない <==> 他の回り方の A - Bパスが存在 必要な辺を探索するよりは、必要ない辺を探索する方が楽。
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
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int main(void){
	short N;
	char flag;
	cin >> N;
	VVI A(N,VI(N));
	VVB E(N,VB(N,true));

	REP(i,N) REP(j,N) cin >> A[i][j];

	REP(i,N){
		FOR(j,i+1,N){
			flag = 0;
			REP(k,N){
				if (i == k || j == k) continue;
				if (A[i][j] > A[i][k] + A[k][j]){
					cout << "-1" << endl;
					exit(0);
				}
				else {
					if (A[i][j] == A[i][k] + A[k][j]){
						flag = 1;
						E[i][j] = E[j][i] = false;
					}
				}
			}
		}
	}
	LL ans = 0;

	REP(i,N){
		REP(j,N){
			if (E[i][j]) ans += A[i][j];			
		}
	}

	cout << ans/2 << endl;

	return 0;
}