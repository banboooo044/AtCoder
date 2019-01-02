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
#define MOD (long) 1000000007
#define shINF (short) 32767
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))

using namespace std;
typedef long long LL;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef map<LL,long> mp;
typedef map<LL,mp> mmp;

mmp memo;
long rec(LL S,LL X){
	if (IN(S,memo) && IN(X,memo[S])) return memo[S][X];
	if (X == 0) return (S+1);
	if (S == 1) return 2L;
	long val = rec(S/2,X/2) % MOD;
	if (S >= 1 && X >= 1) val += (rec((S-1)/2,(X-1)/2)%MOD);
	if (S >= 2) val += (rec((S-2)/2,X/2)%MOD);
	return memo[S][X] = val;
}
int main(void){
	LL N;
	cin >> N;
	cout << rec(N,N)%MOD << endl;
	return 0;
}