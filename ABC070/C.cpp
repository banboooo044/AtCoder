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

LL gcd(LL a, LL b) {
  return b != 0 ? gcd(b, a % b) : a;
}
LL lcm(LL a, LL b) {
  return (a/ gcd(a, b))*b;
}

int main(void){
	short N;
	cin >> N;
	LL T = 1;
	REP(i,N){
		LL t;
		cin >> t;
		T = lcm(max(T,t),min(T,t));
	}

	cout << T << endl;
	return 0;

}

