#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>=(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define llINF (long long) 9223372036854775807
#define loINF (long) 2147483647
#define shINF (short) 32767
#define SORT(c) sort((c).begin(),(c).end())
//#define DEBUG
using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef priority_queue<long,vector<long>,greater<long>> minp;
typedef priority_queue<long> maxp;

int main(void){
	long N,a;
	cin >> N;
	minp af;
	maxp ab;
	VI a_mid(N);
	long sum_f = 0;
	long sum_b = 0;

	REP(i,N) {
		cin >> a;
		af.push(a);
		sum_f += a;
	}
	REP(i,N) {
		cin >> a;
		a_mid[i] = a;
	}
	REP(i,N) {
		cin >> a;
		ab.push(a);
		sum_b += a;
	}

	VI dp_f(N+1,0);
	VI dp_b(N+1,0);
	dp_f[0] = sum_f;
	dp_b[N] = sum_b;

	// 0 ~ 2Nの中で最大を決める dp_l[i]:=左からN+iこ使って最大。
	REP(i,N) {
		long minv = af.top();
		if (minv < a_mid[i]) {
			af.pop();
			af.push(a_mid[i]);
			dp_f[i+1] = dp_f[i] + (a_mid[i] - minv);
		}
		else dp_f[i+1] = dp_f[i];
	}

	RFOR(i,N,1) {
		long maxv = ab.top();
		if (maxv > a_mid[i-1]) {
			ab.pop();
			ab.push(a_mid[i-1]);
			dp_b[i-1] = dp_b[i] + a_mid[i-1] - maxv	;	
		}
		else dp_b[i-1] = dp_b[i];
	}

	#ifdef DEBUG
		dump1d_arr(dp_f);
		dump1d_arr(dp_b);
	#endif

	REP(i,N+1) dp_f[i] -= dp_b[i];
	cout << *max_element(dp_f.begin(),dp_f.end()) << endl;
	return 0;


}