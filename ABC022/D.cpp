#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define dumpP(p) cerr << "(" << p.first << "," << p.second << ")" << endl;
#define ENUM_v(vec) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
using namespace std;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<LL,LL> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

long long dis(pr vec1,pr vec2) {
	return (abs(vec1.first - vec2.first))*(abs(vec1.first - vec2.first)) + (abs(vec1.second - vec2.second))*(abs(vec1.second - vec2.second));
}

int main(void) {
	long N;
	cin >> N;
	VI ax(N),ay(N);

	pr minx(loINF,loINF);
	pr maxx(-loINF,-loINF);
	pr miny(loINF,loINF);
	pr maxy(-loINF,-loINF);
	REP(i,N) {
		cin >> ax[i] >> ay[i];
		if (ax[i] < minx.first || (ax[i] == minx.first && ay[i] < minx.second) ) minx = pr (ax[i],ay[i]);
		if (ax[i] > maxx.first || (ax[i] == maxx.first && ay[i] > maxx.second) ) maxx = pr(ax[i],ay[i]);
		if (ay[i] < miny.second|| (ay[i] == miny.second && ax[i] < miny.first) ) miny = pr(ax[i],ay[i]);
		if (ay[i] > maxy.second|| (ay[i] == maxy.second && ax[i] > maxy.first) ) maxy = pr(ax[i],ay[i]);
	}
	LL longest = max(dis(minx,maxx),dis(miny,maxy));
/*
	dumpP(minx)
	dumpP(maxx)
	dumpP(miny)
	dumpP(maxy)
	dump(longest)
*/
	minx = pr (loINF,loINF);
	maxx = pr (-loINF,-loINF);
	miny = pr (loINF,loINF);
	maxy = pr (-loINF,-loINF);
	REP(i,N) {
		cin >> ax[i] >> ay[i];
		if (ax[i] < minx.first || (ax[i] == minx.first && ay[i] < minx.second) ) minx = pr (ax[i],ay[i]);
		if (ax[i] > maxx.first || (ax[i] == maxx.first && ay[i] > maxx.second) ) maxx = pr(ax[i],ay[i]);
		if (ay[i] < miny.second|| (ay[i] == miny.second && ax[i] < miny.first) ) miny = pr(ax[i],ay[i]);
		if (ay[i] > maxy.second|| (ay[i] == maxy.second && ax[i] > maxy.first) ) maxy = pr(ax[i],ay[i]);
	}
	LL longest2 = max(dis(minx,maxx),dis(miny,maxy));
/*
	dumpP(minx)
	dumpP(maxx)
	dumpP(miny)
	dumpP(maxy)
	dump(longest2)
*/
	double p = sqrt((double)longest2/(double)longest);
	cout << ROUND(10) << p << endl;

}