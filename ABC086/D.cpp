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

long N,K;
VVI arr;
long query(long x1,long y1,long x2,long y2){
	return arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
}

int main(void){
	cin >> N >> K;
	arr = VVI(4*K,VI(4*K,0));

	REP(i,N){
		long x,y;
		char c;
		cin >> x >> y >> c;
		if (c == 'W') x += K;
		arr[(x)%(2*K)][y%(2*K)] += 1;
		arr[(x)%(2*K)+2*K][(y)%(2*K)+2*K] += 1;
		arr[(x)%(2*K)][y%(2*K)+2*K] += 1;
		arr[x%(2*K)+2*K][(y)%(2*K)] += 1;
	}


	REP(i,4*K) REP(j,4*K-1) arr[i][j+1] += arr[i][j];
	REP(j,4*K) REP(i,4*K-1) arr[i+1][j] += arr[i][j];
	#ifdef DEBUG
		dump2d_arr(arr);
	#endif

	long ans = 0;
	long tmp;
	
	FOR(i,1,2*K+1){
		FOR(j,1,2*K+1){ 
			tmp = 0;
			tmp += query(i,j,i+K-1,j+K-1);
			tmp += query(i+K,j+K,i+2*K-1,j+2*K-1);
			ans = max(ans,tmp);
		}		
	}

	cout << ans << endl;

	return 0;
}