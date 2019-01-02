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
#define EQ(a,b) (abs(a - b) < 1e-10)
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

template<typename V,typename Weight>
class DijekstraFast {
private:
	typedef pair<Weight,V> P;
	struct RadixHeap{
		V last,sz;
		vector<P> bucket[32];
		RadixHeap() : last(0), sz(0){}
		int inline bsr(V x) {
			return x == 0 ? 0 : (31 - __builtin_clz(x^last));
		}

		void push(Weight d,V ver){
			sz++, bucket[bsr(d)].emplace_back(d,ver);
		}

		P pop(bool flg = true){
			if(bucket[0].empty()){
				int idx = 1;
				while(bucket[idx].empty()) idx++;
				last = min_element(bucket[idx].begin(), bucket[idx].end())->first;
				for(P val : bucket[idx]) bucket[bsr(val.first)].push_back(val);
				bucket[idx].clear();
			}
			P res = bucket[0].back();
			if(flg) sz--, bucket[0].pop_back();
			return res;
		}
		P inline top(){ return pop(false); }
		bool inline empty(){ return !sz; }
	};
	vector<vector<pair<V,Weight>>> E;
	V const sz;
public:
	Weight const inf = numeric_limits<Weight>::max();
	vector<Weight> D;
	DijekstraFast(V v) :
		E(v),sz(v),D(v,inf) {}

	void inline addEdgeDirected(V from,V to,Weight dis){
		E[from].emplace_back(to,dis);
	}
	void inline addEdgeUndirected(V from,V to,Weight dis){
		E[from].emplace_back(to,dis);
		E[to].emplace_back(from,dis);
	}

	V inline size() {return sz;}
	Weight & operator[] (V n) { if (0 <= n && n < sz) return D[n];} 

	void dijekstra(V start){
		RadixHeap que;
		D[start] = 0;
		que.push(0,start);
		while(!que.empty()){
			P cur = que.pop();
			Weight d = cur.first;
			V v = cur.second;
			if (D[v] < d) continue; //既により最適が見つかっている
			for(V i = 0;i < E[v].size();i++){
				V next = E[v][i].first;
				Weight newCost = d + E[v][i].second;
				if (D[next] > newCost) {
					D[next] = newCost;
					que.push(newCost,next);
				}
			}
		}
	}
};
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long N,M,S,T,u,v,a,b;
	cin >> N >> M >> S >> T;
	DijekstraFast<long,LL> yens(N);
	DijekstraFast<long,LL> snookg(N);
	REP(i,M) {
		cin >> u >> v >> a >> b;
		yens.addEdgeUndirected(u-1,v-1,a);
		snookg.addEdgeUndirected(u-1,v-1,b);
	}
	yens.dijekstra(S-1);
	snookg.dijekstra(T-1);
	VI acc(N);
	acc[N-1] = yens[N-1] + snookg[N-1];
	REP(i,N-1) {
		acc[N-i-2] = yens[N-i-2]+snookg[N-i-2];
		acc[N-i-2] = min(acc[N-i-1],acc[N-i-2]);
	}
	long long ans = 1000000000000000;
	REP(i,N) cout << ans - (LL)acc[i] << endl;
}