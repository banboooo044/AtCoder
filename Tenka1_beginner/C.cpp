#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
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
typedef long long LL;

int main(void){
	LL N;
	cin >> N;
	LL minv = (N / 4);
	if (minv == 0) minv = 1;
	LL maxv = (N * 3)/4;

	#ifdef DEBUG
		dump(minv);
		dump(maxv);
	#endif

	FOR(w,maxv,loINF){
		FOR(h,minv,maxv+1){
			#ifdef DEBUG
				dump(w);
				dump(h);
			#endif

			if (((4*h*w)-(N*w)-(N*h)) == 0) continue;
			if (((N*h*w) % ((4*h*w)-(N*w)-(N*h))) == 0 && ((4*h*w)-(N*w)-(N*h)) > 0) {
				cout << w << " " << h << " " << ((N*h*w) / ((4*h*w)-(N*w)-(N*h))) << endl;
				exit(0);
			}
		}
	}

	return 0;
}