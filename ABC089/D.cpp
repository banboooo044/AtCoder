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
typedef pair<long,long> pr;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef vector<pr> VP;

int main(void){
	short H,W;
	long D,Q,L,R;
	long val;
	cin >> H >> W >> D;
	VP A(H*W+1);
	VI acc(H*W+1,0);
	REP(i,H){
		REP(j,W){
			cin >> val;
			A[val] = pr (i+1,j+1); 
		}
	}

	FOR(i,1+D,D+D+1){
		for(long j = i;j <= H*W;j += D){
			acc[j] += (abs(A[j].first - A[j - D].first) + abs(A[j].second - A[j - D].second) + acc[j-D]); 
		}
	}

	cin >> Q;
	REP(i,Q){
		long ans = 0;
		cin >> L >> R;
		ans = acc[R] - acc[L];
		cout << ans << endl;
	}
	return 0;
}