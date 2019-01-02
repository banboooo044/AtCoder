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
constexpr double eps = 1e-8;
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

typedef struct _PT {
  double x, y;
  _PT() {}
  _PT(double x, double y) : x(x), y(y) {} 
  _PT operator + (_PT p){
     return _PT(x + p.x, y + p.y);
  }
  _PT operator - (_PT p){
     return _PT(x - p.x, y - p.y);
  }
  _PT operator * (double d){
     return _PT(d*x, d*y);
  }

  double norm(void){
    return sqrt(x*x + y*y);
  }

  double twiceNorm(void){
    return x*x + y*y;
  }

  double dist(_PT p){ //pとの距離の2乗
     return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
  }
  bool operator <(const struct _PT &e) const{
     return x == e.x? (y < e.y) : x < e.x;
  }
  bool operator >(const struct _PT &e) const{
     return x == e.x? (y > e.y) : x > e.x;
  }

  double dot(_PT p){ //pとの内積
     return x * p.x + y * p.y;
  }
  
  double det(_PT p){ // (x,p)の外積
     return x * p.y - p.x * y;
  }
}P;

P intersection(P p1,P p2,P q1,P q2) { //直線p1-p2とq1-q2の交点
  	return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}
bool on_seq(P p1,P p2,P q) { // 線分p1-p2上に点qがあるか
    return (abs((p1 - q).det(p2 - q)) < eps) && ((p1 - q).dot(p2 - q) < eps);
}


int main(void) {
	P a,b,line;
	cin >> a.x >> a.y >> b.x >> b.y;
	line = a - b;
	long N;
	cin >> N;
	vector<P> point(N);
	REP(i,N) cin >> point[i].x >> point[i].y;
	long cnt = 0;
	REP(i,N-1) {
		//dump(i)
		if (abs((point[i+1] - point[i]).det(line)) > eps) {
			P r = intersection(point[i],point[i+1],a,b);
			if (on_seq(point[i],point[i+1],r) && on_seq(a,b,r)) cnt++;
		}
	}
	if (abs((point[0] - point[N-1]).det(line)) > eps) {
		P r = intersection(point[0],point[N-1],a,b);
		if (on_seq(point[0],point[N-1],r) && on_seq(a,b,r)) cnt++;
	}

	//dump(cnt)
	cout << 1 + (int)(cnt/2) << endl;
}
