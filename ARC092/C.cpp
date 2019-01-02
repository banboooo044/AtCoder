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

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
// to:次の頂点,cap:辺の重み,rev:逆辺のindex
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

	void add_edge(long from,long to,long cap){
		E[from].push_back({to,cap,(long)E[to].size()});
		E[to].push_back({from,0,(long)E[from].size()-1});
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

// 入力例
int main(void){
	long N;
	cin >> N;
	Ford_fulkerson ff((2*N)+2);
	VI a(N,0),b(N,0),c(N,0),d(N,0);
	REP(i,N) cin >> a[i] >> b[i];
	REP(i,N) {
		cin >> c[i] >> d[i];
		REP(j,N){
			if (a[j] < c[i] && b[j] < d[i]) ff.add_edge(i,N+j,1);
		}
	}

	REP(i,N) {
		ff.add_edge(2*N,i,1);
		ff.add_edge(N+i,2*N+1,1);
	}

	cout << ff.max_flow(2*N,2*N+1) << endl;

	return 0;
}