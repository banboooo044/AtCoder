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
typedef vector<long> VI;
typedef vector<VI> VVI;

int main(void){
	long ans = 0;
	long N;
	cin >> N;
	VI A(N),B(N),C(N);
	REP(i,N) cin >> A[i];
	REP(i,N) cin >> B[i];
	REP(i,N) cin >> C[i];

	SORT(A);
	SORT(C);

	REP(b,N){
		auto use_a = lower_bound(A.begin(),A.end(),B[b])- A.begin();
		auto use_c = N - (upper_bound(C.begin(),C.end(),B[b]) - C.begin());
		#ifdef DEBUG
			dump(use_a);
			dump(use_c);
		#endif
		ans += ((use_a)*(use_c));
	}
	cout << ans << endl;
	return 0;
}