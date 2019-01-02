//　二分探索解法
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
typedef vector<long> VI;
typedef vector<VI> VVI;

VI A;
LL K;

LL simulate(LL N){
	LL retval = N;
	REP(i,K) retval -= (retval % A[i]);
	return retval;
}

LL binary_search_min(LL maxval){
	LL middle,minv = llINF;
	LL l = 0;
	LL r = maxval;
	LL ans;
	while (l <= r){
		middle = (l + r) / 2;
		ans = simulate(middle);
		#ifdef DEBUG
		 dump(middle);
		 dump(ans);
		#endif

		if (ans == 2) minv = min(middle,minv); 
		if(ans >= 2) r = middle-1;
		else l = middle+1;
	}

	return minv;
}

LL binary_search_max(LL maxval){
	LL middle,maxv = -1;
	LL l = 0;
	LL r = maxval;
	LL ans;
	while (l <= r){
		middle = (l + r) / 2;
		ans = simulate(middle);

		if (ans == 2) maxv = max(middle,maxv);

		if(ans <= 2) l = middle + 1;
		else r = middle-1;
	}

	return maxv;
}


int main (void){
	LL maxval = -1;
	cin >> K;
	A = VI(K);

	REP(i,K) {
		cin >> A[i];
		if (maxval < A[i]) maxval = A[i];
	}

	LL a = binary_search_max(2+K*maxval);
	LL b = binary_search_min(2+K*maxval);

	if (a == -1 || b == llINF || b > a) cout << (-1) << endl;
	else cout << b << " " << a << endl;

	return 0;
}