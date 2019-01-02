#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
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
typedef vector<long long> VI;
typedef vector<VI> VVI;
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int main(void){
	short N;
	cin >> N;
	VI x_acc(N,0),v_((1 << N),0),c_((1 << N),0);
	{
		VI x(N),v(N),c(N);
		REP(i,N) cin >> x[i];
		REP(i,N) cin >> c[i];
		REP(i,N) cin >> v[i];
		

		long M = (1 << N);
		x_acc[0] = x[0];

		FOR(i,1,N) x_acc[i] = x[i] + x_acc[i-1];
		FOR(mask,1,M){
			REP(dig,N){
				if ((mask >> dig) & 1) {
					v_[mask] += v[dig];
					c_[mask] += c[dig];
				}
			}
		}
	}

	VVI dp(N,VI((1 << N),0));

	// dp[i][bit] := i番目まで売却し、買える品物が(bit)状態の時の価値の最大値。あり得ない状況でも計算する。

	REP(i,N){
		FOR(bit,1,1 << N){
			// 全部買える場合。
			if (c_[bit] <= x_acc[i]) dp[i][bit] = v_[bit];
			REP(j,N){
				// もし、販売されてるもの全てが金が足りなくて買えない場合に機能する。もともとdp[i][bit] := 0
				if ((bit >> j) & 1) chmax(dp[i][bit],dp[i][bit^(1<<j)]); 
			}
		}
	}

	//dump2d_arr(dp);
	//dump1d_arr(c_);
	//dump1d_arr(v_);

	VI dp2(1 << N,-loINF);
	FOR(i,1,1<<N){
		long st = N - (__builtin_popcount(i)); // ビットの立ってない本数。= 売却した個数
		long long val1 = -loINF;
		if (st != 0)  val1 = dp[st-1][i];
		long long val2 = llINF;

		REP(j,N) if ((i >> j) & 1) chmin(val2,dp2[i^(1<<j)]);
		dp2[i] = max(val1,val2);
	}
	//dump1d_arr(dp2);

	cout << dp2[(1<<N)-1] << endl;

	return 0;

}