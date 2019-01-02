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


long N,A,B;

bool check(long mid,VI h){
	long cnt = 0;
	REP(i,N) h[i] -= ((B)*mid);
	REP(i,N){
		if (h[i] <= 0) continue;
		cnt += h[i] / (A-B);
		if (h[i] % (A-B)) cnt++;
	}

	if (cnt <= mid) return true;
	else return false; 
}


int main (void){
	cin >> N >> A >>  B;
	VI h(N,0);
	REP(i,N) cin >> h[i];
	long h_max = *max_element(h.begin(), h.end());
	long l = 0;
	long r = loINF;
	long minv = loINF;

	while (l <= r){
		long middle = (l + r) / 2;
		//dump(middle);

		if ((h_max / B) + 1 < middle){
			r = middle - 1;
			minv = min(middle,minv);
			continue;
		}

		if (check(middle,h)){
			r = middle - 1;
			minv = min(middle,minv);
		}
		else {
			l = middle + 1;
		}
	}

	cout << minv << endl;
	return 0;
}