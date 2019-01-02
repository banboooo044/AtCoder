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
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef pair<long,long> pr;
struct ver {long di,node,prev;};
struct Order {
	bool operator() (ver const& a,ver const& b) const {
		return a.di > b.di || ((a.di == b.di) && (a.node > b.node));
	}
};
typedef priority_queue<ver,vector<ver>,Order> pq;

class Dijekstra {
private:
	vector<vector<pr>> E;
	VVI memo;
	vector<long> dist;
	vector<long> trace;
	size_t V;
	long goal;
	long mind;
public:
	Dijekstra() : V(0) { }
	Dijekstra(size_t v,long b) :
		V(v),E(v,vector<pr>(0)),dist(v,2147483647),trace(v,2147483647),memo(v,VI(v,loINF)),goal(b-1){}

	size_t size() { return V;}

	void add_edge_directed(long from,long to,long dis){
		E[from].push_back(pr(to,dis));
	}

	void add_edge_undirected(long from,long to,long dis){
		E[from].push_back(pr(to,dis));
		E[to].push_back(pr(from,dis));
	}	

	void dijekstra(long start){
		pq que;
		dist[start] = 0;
		trace[start] = start;
		que.push(ver{0,start,start});

		while(! que.empty()){
			ver next = que.top();
			que.pop();
			long next_v = next.node;
			if (dist[next_v] < next.di) continue; //既により最適が見つかっている
			dist[next_v] = next.di;
			trace[next_v] = next.prev;
			
			REP(i,E[next_v].size()){
				pr e = E[next_v][i];
				if (dist[e.first] == 2147483647) que.push(ver{next.di+e.second,e.first,next_v});
			}
		}
	}

	long dijekstra_fast(long start,long goal){
		pq que;
		dist[start] = 0;
		trace[start] = start;
		que.push(ver{0,start,start});

		while(! que.empty()){
			ver next = que.top();
			que.pop();
			long next_v = next.node;
			if (dist[next_v] < next.di) continue; //既により最適が見つかっている
			dist[next_v] = next.di;
			trace[next_v] = next.prev;
			if (next_v == goal) break;	//goalが求まったら即終了
			
			REP(i,E[next_v].size()){
				pr e = E[next_v][i];
				if (dist[e.first] == 2147483647) que.push(ver{next.di+e.second,e.first,next_v});
			}
		}

		if (dist[goal] == 2147483647) return 1;
		else return mind = dist[goal];
	}

	vector<long> result(void){
		return dist;	// 非連結なら 2147483647 が入っている。
	}

	long result_query(long goal){
		return dist[goal];
	}

	vector<long> show_trace(long start,long goal){
		vector<long> trace_result;
		for (long node = goal;node != start;node = trace[node]){
			trace_result.push_back(node);
		}
		trace_result.push_back(start);

		return trace_result; // 配列の先頭がgoal,末尾がstart
	}

	long dfs(long step,long node) {
		if (memo[step-1][node] != loINF) return memo[step-1][node];
		long v = 0;
		if (step == mind) {
			bool flg = false;
			REP(i,E[node].size()) {
				if (goal == E[node][i].first) {
					flg = true;
					break;
				}
			}
			if (flg) return 1;
			else return 0;
		}
		REP(i,E[node].size()) {
			v += dfs(step+1,E[node][i].first);
			v %= mod;
		}
		return memo[step-1][node] = v;
	}
};

int main(void) {
	long N,M,a,b,x,y;
	cin >> N >> a >> b >> M;
	Dijekstra dj(N,b);
	REP(i,M) {
		cin >> x >> y;
		dj.add_edge_undirected(x-1,y-1,1);
	}
	long mind = dj.dijekstra_fast(a-1,b-1);
	long ans = dj.dfs(1,a-1);
	//dump(mind)
	//dump(ans);
	cout << ans << endl;
}