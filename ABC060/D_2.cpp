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
#define SORT(c) sort((c).begin()+1,(c).end(),greater<long>())

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;

int main(void){
	long N,W;
	VVI V(4,VI(1,0));
	cin >> N >> W;

	long w,v;
	cin >> w >> v;
	V[0].push_back(v);
	REP(i,N-1){
		long w_ot;
		cin >> w_ot >> v;
		V[w_ot-w].push_back(v);
	}

	REP(i,4){
		SORT(V[i]);
		REP(j,V[i].size()-1) V[i][j+1] += V[i][j];
	}

	//dump2d_arr(V);

	long ans = 0;
	REP(i,V[0].size()){
		if (i * w > W) break;
		REP(j,V[1].size()){
			if ((i+j)*w + j > W) break;
			REP(k,V[2].size()){
				long l = (i+j+k)*w + j + (2 * k) - W;
				if (l > 0) break;
				l = min((long)V[3].size()-1,((-l) / (w+3)));
				/*
				dump(i);
				dump(j);
				dump(k);
				dump(l);
				*/

				ans = max(ans,V[0][i] + V[1][j] + V[2][k] + V[3][l]);
			}
		}
	}

	cout << ans << endl;
	return 0;
}