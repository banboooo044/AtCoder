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
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef pair<long,long> pr;
struct ver {long di,node,prev;};
struct Order {
	bool operator() (ver const& a,ver const& b) const {
		return a.di > b.di || ((a.di == b.di) && (a.node > b.node));
	}
};
template <typename T>
class Warshall_Floyd {
private:
	vector<vector<T>> dist;
	vector<vector<T>> nex;
	size_t V;
public:
	Warshall_Floyd() : V(0){}
	Warshall_Floyd(size_t v) : dist(v,vector<T>(v,loINF)),nex(v,vector<T>(v,0)),V(v){}

	void add_edge_directed(long from,long to,T dis){
		dist[from][to] = dis;
	}

	void add_edge_undirected(long from,long to,T dis){
		dist[from][to] = dis;
		dist[to][from] = dis;
	}	

	bool washall(void) { // false -> 負の閉路
		REP(i,V) dist[i][i] = 0;
		REP(i,V) {
			REP(j,V) {
				REP(k,V) {
					if (dist[j][i] == loINF || dist[i][k] == loINF) continue;
					if (dist[j][k] > dist[j][i] + dist[i][k]){
						dist[j][k] = dist[j][i] + dist[i][k];
						nex[j][k] = nex[j][i];
					}
					else {
						if (j != i && dist[j][k] == dist[j][i] + dist[i][k])
							nex[j][k] = min({nex[j][i],nex[j][k]});
					}
					if (dist[j][j] < 0) return false;
				}
			}
		}
		return true;
	}

	T requestQuery(long from,long to) {
		return dist[from][to];
	}

	string traceRoute(long from,long to) {
		string route("");
		for(long current = from;current!=to;current = nex[current][to])
			route += (to_string(current) + "-");
		route += to_string(to);
		return route;
	}
};
int main(void) {
	long N,M;
	cin >> N >> M;
	long u,v,l;
	vector<pr> b;
	Warshall_Floyd<long> wf(N);
	REP(i,M) {
		cin >> u >> v >> l;
		if (u == 1) b.push_back(pr(v-1,l));
		else if (v == 1) b.push_back(pr(u-1,l));
		else wf.add_edge_undirected(u-1,v-1,l);
	}
	long next = b.size();
	long ans = loINF;
	long tmp;
	wf.washall();

	REP(i,next) {
		FOR(j,i+1,next) {
			tmp = wf.requestQuery(b[i].first,b[j].first);
			if (tmp != loINF) ans = min((b[i].second + b[j].second + tmp),ans);
		}
	}
	if (ans == loINF) ans = (-1);
	cout << ans << endl;
}

