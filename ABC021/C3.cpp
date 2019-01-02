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

class BFS {
private:
	vector<vector<long>> E;
	vector<long> dist;
	vector<long> route;
	//vector<bool> visited;
	size_t V;
public:
	BFS () : V(0) {}
	BFS (size_t v) : V(v),E(v),dist(v,loINF),route(v){}

	void add_edge_directed(long from,long to){
		E[from].push_back(to);
	}

	void add_edge_undirected(long from,long to){
		E[from].push_back(to);
		E[to].push_back(from);
	}	
	void bfs(long start) {
		queue<long> que;
		que.push(start);
		dist[start] = 1;
		route[start] = 1;
		while (!que.empty()) {
			long from = que.front();
			que.pop();
			REP(to,E[from].size()){
				if (dist[E[from][to]] == loINF) {
					dist[E[from][to]] = dist[from]+1;
					que.push(E[from][to]);
				}
				if (dist[E[from][to]] == dist[from]+1) {
					route[E[from][to]] += route[from];
					route[E[from][to]] %= mod;
				}
			}
		}
	}
	long queryDist(long goal) {
		return dist[goal];
	}
	long queryRoute(long goal) {
		return route[goal];
	}
};

int main(void){
	long N,M,a,b,x,y;
	cin >> N >> a >> b >> M;
	BFS bf(N);
	REP(i,M) {
		cin >> x >> y;
		bf.add_edge_undirected(x-1,y-1);
	}
	bf.bfs(a-1);
	long ans = bf.queryRoute(b-1);
	cout << ans << endl;
}

