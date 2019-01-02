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

int main(void){
	long H,W;
	cin >> H >> W;
	if (H*W % 3 == 0) {
		cout << 0 << endl;
		exit(0);
	}
	long ans = loINF;

	FOR(i,1,H){
		// 高さiを使う
		long sec = (H - i) * (W / 2);
		long thi = ((H - i) * W) - sec;
		ans = min(ans,max({abs(i*W - sec),abs(i*W - thi),abs(sec - thi)}));
		sec = W * ((H - i) / 2);
		thi = ((H - i) * W) - sec;
		ans = min(ans,max({abs(i*W - sec),abs(i*W - thi),abs(sec - thi)}));

	}

	FOR(i,1,W) {
		long sec = (W - i) * (H / 2);
		long thi = ((W - i) * H) - sec;
		ans = min(ans,max({abs(i*H - sec),abs(i*H - thi),abs(sec - thi)}));
		sec = H * ((W - i) / 2);
		thi = ((W - i) * H) - sec;
		ans = min(ans,max({abs(i*H - sec),abs(i*H - thi),abs(sec - thi)}));
	}

	cout << ans << endl;
	return 0;
}