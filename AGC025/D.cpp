#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h,w,x,y) (0 <= y && y < h && 0 <= x && x < w)

using namespace std;
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
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
typedef vector<bool> VB;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

using namespace std;
// to:次の頂点,cap:辺の重み,rev:逆辺のindex
template<typename Ver,typename Weight>
class fordFulkerson {
private:
	typedef struct {Ver to;Weight cap;Ver rev;}edge;
	vector<vector<edge>> E;
	vector<char> used;
	size_t V;
	Weight dfs(Ver node,Ver goal,Weight flow){
		if (node == goal) return flow;
		used[node] = 1;
		REP(i,E[node].size()){
			edge* e = &E[node][i];
			if (!used[e->to] && e->cap != 0){
				Weight d = dfs(e->to,goal,min(flow,e->cap));
				if (d != 0) {
					e->cap -= d;
					E[e->to][e->rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
public:
	fordFulkerson(size_t v) :
		E(v),used(v,0),V(v){}

	size_t size() { return V;}

	void addDirectedEdge(Ver from,Ver to,Weight cap){
		E[from].push_back({to,cap,(Ver)E[to].size()});
		E[to].push_back({from,0,(Ver)E[from].size()-1});
	}

	void addUndirectedEdge(Ver from,Ver to,Weight cap){
		E[from].push_back({to,cap,(Ver)E[to].size()});
		E[to].push_back({from,cap,(Ver)E[from].size()-1});
	}

	Weight maxFlow(Ver start,Ver goal){
		Weight ans = 0;
		while (1){
			REP(i,used.size()) used[i] = 0;
			Weight f = dfs(start,goal,numeric_limits<Weight>::max());
			if (f == 0) return ans;
			ans += f;
		}
	}
};
template<typename Ver>
class BipartiteMatching : public fordFulkerson<Ver,int> {
private:
	Ver V;
	vector<char> connected;
public:
	BipartiteMatching (Ver v) : V(v),connected(v,0),fordFulkerson<Ver,int>(v+2){}
	void addEdge(Ver g1,Ver g2) { // g1 : 独立集合A, g2 : 独立集合B
		fordFulkerson<Ver,int>::addDirectedEdge(g1,g2,1);
		if (!connected[g1]) {
			fordFulkerson<Ver,int>::addDirectedEdge(V,g1,1);
			connected[g1] = 1;
		}
		if (!connected[g2]) {
			fordFulkerson<Ver,int>::addDirectedEdge(g2,V+1,1);
			connected[g2] = 1;
		}
	}
	Ver matching(void) {
		return fordFulkerson<Ver,int>::maxFlow(V,V+1);
	}
};

int main(void) {
	
}



