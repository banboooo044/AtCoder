// 頂点を全パターン試す & 中に点がK個以上あるか判定 : O(N^5)
// 頂点をK個選んで(x_max - x_min) * (y_max - y_min)の最小値: NcK通り == O(NcK) <== 発散スピード高
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
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef pair<LL,LL> pr;
typedef vector<pr> VP;

int main(void){
	short N,K;
	cin >> N >> K;

	VL x(N);
	VL y(N);
	VP point(N);
	REP(i,N) {
		LL x_input,y_input;
		cin >> x_input >> y_input;
		point[i].first  = x[i] = x_input;
		point[i].second = y[i] = y_input;
	}
	SORT(x);
	SORT(y);

	long count;
	LL ans = llINF;
	REP(x_min,N){
		RFOR(x_max,N-1,x_min){
			REP(y_min,N){
				RFOR(y_max,N-1,y_min){
					count = 0;
					REP(p,N){
						if (x[x_min] <= point[p].first && y[y_min] <= point[p].second && point[p].first <= x[x_max] && point[p].second <= y[y_max]) count++;
					}

					if (count >= K) {
						#ifdef DEBUG
							cerr << "------------------" << endl;
							dump(x[x_max]);
							dump(x[x_min]);
							dump(y[y_max]);
							dump(y[y_min]);
							dump((x[x_max]-x[x_min])*(y[y_max]-y[y_min]));
						#endif
						ans = min(ans,(x[x_max]-x[x_min])*(y[y_max]-y[y_min]));
					}
				}
			}
		}
	}
	cout << ans <<endl;
	return 0;
}