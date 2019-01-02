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
typedef priority_queue<pr,vector<pr>,Order> pq;
struct edge {long to,cap,dis,rev;};

class Primal_dual {
private:
    vector<vector<edge>> E;
    vector<long> pt;  
    vector<long> dist;
    vector<pr> prev; // 直前の頂点
    size_t V;
public:
    Primal_dual() : V(0) { }
    Primal_dual(size_t v) :
        E(v,vector<edge>(0)),pt(v,0),prev(v),dist(v),V(v){ }
 
    size_t size() { return V; }
 
    void add_edge(long from,long to,long cap,long dis){
        E[from].push_back({to,cap,dis,(long)E[to].size()});
        E[to].push_back({from,0,-dis,(long)E[from].size()-1});
    }
 
    short dijekstra(long start,long goal){
        pq que;
        REP(i,V) dist[i] = 2147483647;
        dist[start] = 0;
        que.push(pr(0,start));
 
        while (! que.empty()){
            pr next = que.top();
            que.pop();
            long next_v = next.second;
 
            if (dist[next_v] < next.first) continue; //既により最適が見つかっている
 
            REP(i,E[next_v].size()){
                edge* e = &E[next_v][i];
 
                if (e->cap > 0 && dist[e->to] > (dist[next_v] + e->dis + pt[next_v] - pt[e->to])){
                    dist[e->to] =  (dist[next_v] + e->dis + pt[next_v] - pt[e->to]);
                    prev[e->to] = {next_v,i};
                    que.push(pr(dist[e->to],e->to));
                }
            }
        }
 
        if (dist[goal] == 2147483647) return 1;
        else return 0;
    }
 
    long min_cost_flow(long start,long goal,long F){
        long sum_cost = 0;
        while (F > 0){
            if (dijekstra(start,goal)) return (-1); //流量Fは流せない
            REP(i,V) pt[i] += dist[i]; //potentialの更新
 
            long flow = F;
            for (long node = goal;node != start;node = prev[node].first){
                flow = min(flow,E[prev[node].first][prev[node].second].cap); //今回のフロー量を決定
            }
            F -= flow;
            sum_cost += (flow * pt[goal]);
 
            for (long node = goal;node != start;node = prev[node].first) {
                edge* e = &E[prev[node].first][prev[node].second]; //使った辺の情報
                e->cap -= flow;
                E[node][e->rev].cap += flow;
            }
        }
        return sum_cost;
    }
};

int main(void) {
	long R,G,B;
	cin >> R >> G >> B;
	Primal_dual pl(1006); // 頂点0 -> 座標-500, 頂点500->座標0 頂点1000->座標500
	// 頂点1001 -> st,頂点1002,1003,1004 -> R,G,B ,頂点1005 -> gl
	REP(i,1001){
		pl.add_edge(1002,i,1,abs((-100)-(i-500)));
		pl.add_edge(1003,i,1,abs((0)-(i-500)));
		pl.add_edge(1004,i,1,abs(100-(i-500)));
		pl.add_edge(i,1005,1,0);
	}
	pl.add_edge(1001,1002,R,0);
	pl.add_edge(1001,1003,G,0);
	pl.add_edge(1001,1004,B,0);
	cout << pl.min_cost_flow(1001,1005,(R+G+B)) << endl;
}



