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
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vec) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)

using namespace std;
typedef vector<short> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<VVB> VVVB;

int main(void) {
	long N;
	cin >> N;
	bool flg;
	string S;
	VVI arr(2*N,VI(2*N));
	REP(i,N) {
		cin >> S;
		REP(j,N) {
			arr[i][j] = (S[j] - 'a');
			arr[i+N][j] = arr[i][j+N] = arr[i+N][j+N] = arr[i][j];
		}
	}
	long long cnt = 0;
	REP(k,N) {
		flg = true;
		REP(x,N) {
			REP(y,N) {
				if (arr[k+x][y] != arr[k+y][x]) flg = false;
				if (!flg) break;
			}
			if (!flg) break;
		}
		if (flg) cnt += N;
	}
	
	cout << cnt << endl;
}
