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
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
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
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};
struct edge {long to,cap,rev;};
class Ford_fulkerson {
private:
	vector<vector<edge>> E;
	vector<bool> used;
	size_t V;
public:
	Ford_fulkerson() : V(0) { }

	Ford_fulkerson(size_t v) :
		E(v,vector<edge>(0)),used(v,false),V(v){ }

	size_t size() { return V;}

	void add_directed_edge(long from,long to,long cap){
		E[from].push_back({to,cap,(long)E[to].size()});
		E[to].push_back({from,0,(long)E[from].size()-1});
	}

	void add_undirected_edge(long from,long to,long cap){
		E[from].push_back({to,cap,(long)E[to].size()});
		E[to].push_back({from,cap,(long)E[from].size()-1});
	}

	long dfs(long node,long goal,long flow){
		if (node == goal) return flow;
		used[node] = true;
		REP(i,E[node].size()){
			edge* e = &E[node][i];
			if (!used[e->to] && e->cap != 0){
				long d = dfs(e->to,goal,min(flow,e->cap));
				if (d != 0) {
					e->cap -= d;
					E[e->to][e->rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	long max_flow(long start,long goal){
		long ans = 0;
		while (1){
			REP(i,used.size()) used[i] = false;
			long f = dfs(start,goal,2147483647);
			if (f == 0) return ans;
			ans += f;
		}
	}
};
int main(void) {
	LL N,G,E,a,b;
	cin >> N >> G >> E;
	Ford_fulkerson ff(N+1);
	VI p(G);
	REP(i,G) {
		cin >> p[i];
		ff.add_undirected_edge(p[i],N,1);
	}

	REP(i,E) {
		cin >> a >> b;
		ff.add_undirected_edge(a,b,1);
	}
	cout << ff.max_flow(0,N) << endl;
}
