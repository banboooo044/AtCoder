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
	long N;
	cin >> N;
	vector<char> c(2*N);
	bool flg;
	VI a(2*N);
	REP(i,2*N) cin >> c[i] >> a[i];
	long cnt = 0;
	long i = 0;
	long tmp;
	while (1) {
		if (i == (2*N)) break;
		if (c[i] == 'W') {
			i++;
			continue;
		}
		FOR(j,i+1,2*N){
			if (c[j] == 'B' && a[j] < a[i]){
				tmp = a[i];
				cnt += (j - i - 1);
				FOR(k,i,j-1){
					a[k] = a[k+1];
					c[k] = c[k+1];
				}
				a[j-1] = tmp;
				c[j-1] = c[j];
				i = j-1;
				break;
			}
		}
		i++;
	}

	//dump1d_arr(a);

	REP(i,2*N){
		FOR(j,i+1,2*N){
			if (c[i] == c[j]) {
				if (a[i] > a[j]) cnt++;		
			}
		}
	}
	cout << cnt << endl;
}