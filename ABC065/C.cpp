#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define MOD 1000000007
using namespace std;

int main(void){
	long N,M;
	cin >> N >> M;

	if (abs(N-M) > 1) {
		cout << 0 << endl;
		exit(0);
	}

	long long ans = 1;
	REP(i,N) {
		ans *= (N - i);
		ans %= MOD;
	}
	REP(i,M){
		ans *= (M - i);
		ans %= MOD;
	}

	if (!((N + M) % 2)) ans *= 2;

	cout << ans %MOD << endl;
	return 0;
}