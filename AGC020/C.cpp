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
typedef vector<short> VI;
typedef vector<VI> VVI;

int main(void){
	short N;
	long sumval,half;
	cin >> N;
	VI A(N,0);
	REP(i,N) {
		cin >> A[i];
		sumval += A[i];
	}
	half = ((sumval+1) / 2);

	bitset<2000*2000> dp(0);
	dp.set(0);
	REP(i,N){
		bitset<2000*2000> tmp(0);
		tmp |= dp;
		dp <<= A[i];
		dp |= tmp;
	}

	FOR(i,half,sumval+1){
		if (dp[i]) {
			cout << i << endl;
			exit(0);
		}
	}

	return 0;
}