#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end())
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
using namespace std;
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
constexpr short dx[4] = {1,0,-1,0};
constexpr short dy[4] = {0,1,0,-1};
typedef long long LL;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<long,long> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};
typedef map<long,long> mp;

int main(void) {
	long W,H,N;
	cin >> W >> H >> N;
	VI xs(N),xg(N),ys(N),yg(N);
	VI xlis,ylis;
	REP(i,N) {
		cin >> xs[i] >> ys[i] >> xg[i] >> yg[i];
		xlis.push_back(xs[i]);
		xlis.push_back(xg[i]-1);
		if (xs[i] > 0) xlis.push_back(xs[i]-1);
		if (xg[i] < W) xlis.push_back(xg[i]);
		ylis.push_back(ys[i]);
		ylis.push_back(yg[i]-1);
		if (ys[i] > 0) ylis.push_back(ys[i]-1);
		if (yg[i] < H) ylis.push_back(yg[i]);
	}
	SORT(xlis);SORT(ylis);
	UNIQ(xlis);UNIQ(ylis);
	long w = xlis.size();
	long h = ylis.size();
	mp xdic,ydic;
	REP(i,w) xdic[xlis[i]] = i;
	REP(i,h) ydic[ylis[i]] = i;
	vector<vector<short>> imos(h,vector<short>(w,0));
	long x1,y1,x2,y2,f,s;
	REP(i,N) {
		x1 = xdic[xs[i]];
		x2 = xdic[xg[i]-1];
		y1 = ydic[ys[i]];
		y2 = ydic[yg[i]-1];
		imos[y1][x1] += 1;
		if (y2 < (h-1)) imos[y2+1][x1] += (-1);
		if (x2 < (w-1)) imos[y1][x2+1] += (-1);
		if ((x2 < (w-1)) && (y2 < (h-1))) imos[y2+1][x2+1] += 1;
	}
	REP(i,h) REP(j,w-1) imos[i][j+1] += imos[i][j];
	REP(i,h-1) REP(j,w) imos[i+1][j] += imos[i][j];
	LL ans = 0;
	queue<pr> que;
	REP(y,h) {
		REP(x,w) {
			if (imos[y][x] != 0) continue;
			ans ++;
			que.push(pr(x,y));
			while(!que.empty()) {
				f = que.front().first;
				s = que.front().second;
				que.pop();
				REP(k,4) {
					if (0 <= (f + dx[k]) && 0 <= (s + dy[k]) && w > (f + dx[k]) && h > (s + dy[k]) && imos[s + dy[k]][f + dx[k]] == 0) {
						imos[s + dy[k]][f + dx[k]] = 1;
						que.push(pr(f + dx[k],s + dy[k]));
					}
				}
			}
		}
	}
	cout << ans << endl;
}

