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
typedef pair<long long,long long> pr;
struct ver {long long di,node,prev;};
struct Order {
	bool operator() (ver const& a,ver const& b) const {
		return a.di > b.di || ((a.di == b.di) && (a.node > b.node));
	}
};
typedef priority_queue<ver,vector<ver>,Order> pq;
class Dijekstra {
private:
	vector<vector<pr>> E;
	vector<long long> dist;
	vector<long> trace;
	bool createdDag;
	vector<bool> visited;
	vector<vector<pr>> DAG;
	size_t V;
public:
	Dijekstra() : V(0) { }
	Dijekstra(size_t v) :
		V(v),E(v,vector<pr>(0)),dist(v,llINF),trace(v,2147483647) {}

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

	long long dijekstra_fast(long start,long goal){
		pq que;
		dist[start] = 0;
		trace[start] = start;
		que.push(ver{0,start,start});

		while(! que.empty()){
			ver next = que.top();
			que.pop();
			long long next_v = next.node;
			if (dist[next_v] < next.di) continue; //既により最適が見つかっている
			dist[next_v] = next.di;
			trace[next_v] = next.prev;
			if (next_v == goal) break;	//goalが求まったら即終了
			
			REP(i,E[next_v].size()){
				pr e = E[next_v][i];
				if (dist[e.first] == llINF) que.push(ver{next.di+e.second,e.first,next_v});
			}
		}

		if (dist[goal] == 2147483647) return 1;
		else return dist[goal];
	}

	vector<long long> result(void){
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

	void createDag(long node) { //dijekstraをやった後。
		if (!createdDag) {
			DAG = vector<vector<pr>>(V);
			visited = vector<bool>(V,false);
			createdDag = true;
		}
		REP(i,E[node].size()){
			if (E[node][i].second == dist[E[node][i].first] - dist[node]) {
				DAG[node].push_back(E[node][i]);
				if (!visited[E[node][i].first]){
					visited[E[node][i].first] = true;
					createDag(E[node][i].first);
				}
			}
		}
	}
};

short H,W;
void input_edge(Dijekstra &dj,vector<string> &s,long T) {
	REP(i,H){
		REP(j,W-1){
			if (s[i][j+1] == '#') dj.add_edge_directed(i*W+j,i*W+j+1,T);
			else dj.add_edge_directed(i*W+j,i*W+j+1,1);	
			if (s[i][j] == '#') dj.add_edge_directed(i*W+j+1,i*W+j,T);
			else dj.add_edge_directed(i*W+j+1,i*W+j,1);
			if (i != 0){
				if (s[i-1][j] == '#') dj.add_edge_directed(i*W+j,(i-1)*W+j,T);
				else dj.add_edge_directed(i*W+j,(i-1)*W+j,1);
				if (s[i][j] == '#') dj.add_edge_directed((i-1)*W+j,i*W+j,T);
				else dj.add_edge_directed((i-1)*W+j,i*W+j,1);
			}
		}
		if (i != 0){
			if (s[i-1][W-1] == '#') dj.add_edge_directed(i*W+W-1,(i-1)*W+W-1,T);	
			else dj.add_edge_directed(i*W+W-1,(i-1)*W+W-1,1);	
			if (s[i][W-1] == '#') dj.add_edge_directed((i-1)*W+W-1,i*W+W-1,T);	
			else dj.add_edge_directed((i-1)*W+W-1,i*W+W-1,1);		
		}
	}
}

int main(void){
	long T,st,gl;
	cin >> H >> W >> T;
	vector<string> s(H);
	REP(i,H) cin >> s[i];
	REP(i,H) REP(j,W) {
		if (s[i][j] == 'S') st = i*W+j;
		if (s[i][j] == 'G') gl = i*W+j;
	}
	long l = 0;
	long r = T;
	long ans,mid;
	while (l <= r) {
		mid = (l + r)/2;
		//dump(mid)
		Dijekstra d(H*W);
		input_edge(d,s,mid);
		if (d.dijekstra_fast(st,gl) <= T) {
			l = (mid + 1);
			ans = mid;
		}
		else r = (mid - 1);
	}
	cout << ans << endl;
}

