#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
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
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

int main(void) {
	short R,C,K;
	cin >> R >> C >> K;
	vector<string> s(R);
	REP(i,R) cin >> s[i];
	VVI over(R,VI(C,0)),under(R,VI(C,0));
	REP(i,R) {
		REP(j,C) {
			if (s[i][j] == 'x') over[i][j] = 0;				
				
			else {
				if (i != 0) over[i][j] = over[i-1][j]+1;
				else over[i][j] = 1;
			}
		}
	}
	RREP(i,R-1){
		RREP(j,C-1){
			if (s[i][j] == 'x') under[i][j] = 0;	
			else {
				if (i != (R-1)) under[i][j] = under[i+1][j]+1;
				else under[i][j] = 1;
			}
		}
	}


	long cnt = 0;
	bool flg;
	REP(i,R) {
		FOR(j,K-1,C-(K-1)) {
			if (under[i][j] >= K && over[i][j] >= K) {
				flg = false;
				FOR(k,1,K) {
					if (under[i][j-k] < (K-k) || over[i][j-k] < (K-k) || under[i][j+k] < (K-k) || over[i][j+k] < (K-k)) flg = true;
					if (flg) break;
				}
				if (!flg) cnt++;	
			}
		}
	}
	cout << cnt << endl;
	return 0;
}