#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << endl
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

template <typename V,typename Weight>
class Adjacency_Matrix {
public:
	vector<vector<Weight>> E;
	size_t sz;
	Adjacency_Matrix (V v) : E(v,vector<Weight>(v,numeric_limits<Weight>::max())),sz(v){}
	void addEdgeDirected(V from,V to,Weight dis){
		E[from][to] = dis;
	}

	void addEdgeUndirected(V from,V to,Weight dis){
		E[from][to] = dis;
		E[to][from] = dis;
	}
};
template <typename V,typename Weight>
class Adjacency_List {
public:
	vector<vector<pair<V,Weight>>> E;
	V sz;
	Adjacency_List(V v) : E(v),sz(v){}
	void addEdgeDirected(V from,V to,Weight dis){
		E[from].push_back(make_pair(to,dis));
	}
	void addEdgeUndirected(V from,V to,Weight dis){
		E[from].push_back(make_pair(to,dis));
		E[to].push_back(make_pair(from,dis));
	}
};

constexpr int c = 700;
template <typename V,typename Weight>
pair<bitset<c>,bitset<c>> separate(vector<vector<pair<V,Weight>>> &E,V start) {
	typedef bitset<c> bs;
	queue<pair<int,bool>> que;
	que.push(make_pair(start,true));
	bs S1(0),S2(0);
	while (!que.empty()) {
		pair<int,bool> n = que.front();que.pop();
		if (n.second && S2[n.first]) return make_pair(bs(0),bs(0));
		if ((!(n.second)) && S1[n.first]) return make_pair(bs(0),bs(0));	
		if (n.second) {
			S1.set(n.first);
			for (int i = 0;i < E[n.first].size();i++) {
				V next = E[n.first][i].first;
				if (S2[next]) continue;
				que.push(make_pair(next,!(n.second)));
			}
		}
		else {
			S2.set(n.first);
			for (int i = 0;i < E[n.first].size();i++) {
				V next = E[n.first][i].first;
				if (S1[next]) continue;
				que.push(make_pair(next,!(n.second)));
			}
		}
	}
	return make_pair(S1,S2);
};

int main(void) {
	long N,M,A,B;
	cin >> N >> M;
	Adjacency_Matrix<long,int> e_tmp(N);
	Adjacency_List<long,int> e(N);
	REP(i,M) {
		cin >> A >> B;
		e_tmp.addEdgeUndirected(A-1,B-1,1);
	}
	REP(i,N) FOR(j,i+1,N) {
		if (e_tmp.E[i][j] == numeric_limits<int>::max()) e.addEdgeUndirected(i,j,1);
	}

	VVI cnt(2);
	bitset<c> used(0);
	REP(i,N) {
		if (!used[i]) {
			auto p = separate<long,int>(e.E,i);
			if (p.first == (0) && p.second == (0)) {
				cout << (-1) <<  endl;
				exit(0);
			}
			used |= p.first;
			used |= p.second;
			cnt[0].push_back(p.first.count());
			cnt[1].push_back(p.second.count());
		}
	}
	int l = cnt[0].size();
	vector<vector<char>> dp(l,VB(N+1,0)); //組みを全部列挙
	dp[0][cnt[0][0]] = 1;
	FOR(i,1,l) {
		RFOR(j,N,-1) {
			if (j - cnt[0][i] >= 0 && dp[i-1][j-cnt[0][i]]) dp[i][j] = 1;
			if (j - cnt[1][i] >= 0 && dp[i-1][j-cnt[1][i]]) dp[i][j] = 1;
		}
	}
	long ans,dif = loINF;
	REP(i,N+1) {
		if (dp[l-1][i] && abs(2*i - N) < dif) {
			ans = i;
			dif = abs(2*i - N);
		}
	}
	cout << (ans * (ans-1) /2) + ((N - ans)*(N-ans-1)/2) << endl;
}
