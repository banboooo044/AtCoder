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
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))

using namespace std;
typedef long long LL;
typedef vector<short> VS;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
VS a,b;
VVVI memo;
LL rec(short digit,short tight,short used,vector<short> &K){
	if (memo[digit][tight][used] != (-1)) return memo[digit][tight][used];
	if (digit+1 == K.size()) {
		if (tight) {
			if (used) return K[digit] + 1;
			else return ((4 <= K[digit]) + (K[digit] == 9));
		}
		else {
			if (used) return 10;
			else return 2;
		}
	}
	LL retval;
	if (used) {
		LL free = rec(digit+1,0,1,K);
		if (tight) retval = (free * K[digit] + rec(digit+1,1,1,K));
		else retval = (free * 10);
	}
	else {
		LL free = rec(digit+1,0,0,K);
		if (!tight) retval = (rec(digit+1,0,1,K)*2 + free * 8);
		else if (K[digit] < 4) retval = (free*K[digit] + rec(digit+1,1,0,K));
		else if (K[digit] == 4) retval = (free * 4 + rec(digit+1,1,1,K));
		else if (K[digit] == 9) retval = (free * 8 + rec(digit+1,1,1,K) + rec(digit+1,0,1,K));
		else retval = (free*(K[digit]-1) + rec(digit+1,0,1,K) + rec(digit+1,1,0,K));
	}
	/*
	dump(digit);
	dump(tight);
	dump(used);
	dump(retval);*/
	return memo[digit][tight][used] = retval;
}

int main(void) {
	string A,B;
	cin >> A >> B;
	a = VS(A.length());
	b = VS(B.length());

	bool flg = false;
	REP(i,A.length()) {
		a[i] = (short)(A[i] - '0');
		if (a[i] == 4 || a[i] == 9) flg = true;
	}
	REP(i,B.length()) b[i] = (short)(B[i] - '0');
	memo = VVVI((LL)b.size(),VVI(2,VI(2,-1)));
	LL vb = rec(0,1,0,b);
	memo = memo = VVVI((LL)b.size(),VVI(2,VI(2,-1)));
	cout << vb - rec(0,1,0,a) + flg << endl;
	return 0;
}