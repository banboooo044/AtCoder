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
	short N;
	cin >> N;

	// v_[mask] := 買える品物(mask)を全部買った時の価値
	// c_[mask] := 
	VI x_acc(N,0),v_((1 << N) - 1,0),c_((1 << N) - 1,0);
	{
		VI x(N),v(N),c(N);
		REP(i,N) cin >> x[i];
		REP(i,N) cin >> v[i];
		REP(i,N) cin >> c[i];

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

	VVI dp(N,VI((1 << N)-1));

	long mask = (1 << N) - 1;
	REP(i,N){
		// 何個売却したか
		long aoki = loINF;
		REP(j,N){
			// 次にどれを販売停止にするか。
			if ((mask >> j) & 1){
				long bit = mask - (1 << j);
				long taka = (-1);
				for (long m = bit;m > 0;m = (m-1)&bit){
					// 最大を見つける。
					if (x_acc[i] >= c_[m]) taka = max(taka,v_[m]);
				}
				dp[i+1][bit] = taka;
				aoki = min(aoki,taka);
			}
		}

		
	}
	
}