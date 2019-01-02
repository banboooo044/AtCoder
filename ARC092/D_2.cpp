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
using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;

int main(void){
	long N;
	cin >> N;
	VI a(N,0),b(N,0),a_t(N,0),b_t(N,0);
	REP(i,N) cin >> a[i];
	REP(i,N) cin >> b[i];

	long T = 1;
	long long ans = 0;

	REP(k,30){
		// [T 2T) [3T 4T)
		REP(i,N) {
			a_t[i] = a[i] % (2*T);
			b_t[i] = b[i] % (2*T);
		}

		SORT(b_t);
		long bit = 0;
		REP(j,N){
			//dump(FINDU(b_t,T*3-a_t[j]-1));
			//dump(FINDU(b_t,T-a_t[j]-1));
			bit  += ((FINDL(b_t,T*4-a_t[j]) + FINDL(b_t,T*2-a_t[j]) - FINDU(b_t,T*3-a_t[j]-1) - FINDU(b_t,T-a_t[j]-1)) % 2);
		}
		//dump(k);
		//dump(bit);

		ans += ((1 << k)*(bit%2));
		T <<= 1;
	}

	cout << ans << endl;
}