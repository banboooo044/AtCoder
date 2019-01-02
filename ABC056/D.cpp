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
typedef vector<bool> VB;
typedef vector<VB> VVB;

int main(void){
	long N,K;
	cin >> N >> K;

	VI a(N);
	long tmp;

	REP(i,N) cin >> a[i];

	VVB dpl(N+1,VB(K+1,false)),dpr(N+1,VB(K+1,false));
	dpl[0][0] = true;
	dpr[0][0] = true;

	FOR(i,1,N+1){
		REP(k,K+1) {
			if (k - a[i-1] >= 0) dpl[i][k] = (dpl[i-1][k] || dpl[i-1][k-a[i-1]]);
			else dpl[i][k] = dpl[i-1][k];
			if (k - a[N-i] >= 0) dpr[i][k] = (dpr[i-1][k] || dpr[i-1][k-a[N-i]]);
			else dpr[i][k] = dpr[i-1][k];
		}
	}

	//dump2d_arr(dpl);
	//dump2d_arr(dpr);

	long ans = N;
	bool flg;

	FOR(i,1,N+1){
		if (a[i-1] >= K) {
			ans --;
			continue;
		}

		flg = false;
		FOR(j,1,a[i-1]+1){
			if (flg) break;
			REP(k,K-j+1){
				if (i == 1) {
					if (dpr[N-1][K-j]) {
						ans--;	
						flg = true;
						break;
					}
				}

				else if (i == (N)) {
					if (dpl[N-1][K-j]) {
						ans--;
						flg = true;
						break;
					}
				}

				else if (dpl[i-1][k] && dpr[N-i][K-k-j]){
					ans --;
					flg = true;
					break;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}