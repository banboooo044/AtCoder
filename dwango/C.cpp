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

	void dump_E(void){
		REP(i,E.size()){
			REP(j,E[i].size()){
				dump(i);
				dump(E[i][j].to);
				dump(E[i][j].cap);
				dump(E[i][j].rev);
			}
		}
	}
};

int main(void){
	short r,c;
	short ver_sum = 2;
	cin >> r >> c;
	vector<vector<long>> array(r,vector<long>(c,-1));
	char ch;
	long cnt = 0;
	bool flg_b = false,flg_w = false;
	REP(i,r){
		REP(j,c){
			cin >> ch;
			if (ch == '.') {
				array[i][j] = cnt++;
				ver_sum ++;
				if ((i+j)%2) flg_w = true;
				else flg_b = true;
			}
		}
	}
	if (!(flg_w && flg_b)) {
		cout << ver_sum-2 << endl;
		exit(0);
	}

	Ford_fulkerson ff(ver_sum);

	REP(i,r-1){
		REP(j,c-1){
			if (array[i][j] >= 0){
				long ver = array[i][j];
				if ((i+j)%2) {
					ff.add_edge(ver_sum-2,ver,1);
					if (array[i][j+1] >= 0) ff.add_edge(ver,ver+1,1);

					if (array[i+1][j]>= 0) ff.add_edge(ver,array[i+1][j],1);
				}
				else {
					ff.add_edge(ver,ver_sum-1,1);
					if (array[i][j+1]>= 0) ff.add_edge(ver+1,ver,1);
					if (array[i+1][j]>= 0) ff.add_edge(array[i+1][j],ver,1);
				}
			}
		}
		if (array[i][c-1] >= 0) {
			long ver = array[i][c-1];
			if ((i+c-1)%2) {
				ff.add_edge(ver_sum-2,ver,1);
				if (array[i+1][c-1]>= 0) ff.add_edge(ver,array[i+1][c-1],1);
			}
			else {
				ff.add_edge(ver,ver_sum-1,1);
				if (array[i+1][c-1]>= 0) ff.add_edge(array[i+1][c-1],ver,1);
			}
		}
	}
	
	REP(j,c-1) {
		if (array[r-1][j] >= 0){
			long ver = array[r-1][j];
			if ((r-1+j)%2) {
				ff.add_edge(ver_sum-2,ver,1);
				if (array[r-1][j+1]>= 0) ff.add_edge(ver,ver+1,1);
			}
			else {
				ff.add_edge(ver,ver_sum-1,1);
				if (array[r-1][j+1]>= 0) ff.add_edge(ver+1,ver,1);
			}
		}
	}

	if (array[r-1][c-1] >= 0){
		if ((r+c-2)%2) ff.add_edge(ver_sum-2,array[r-1][c-1],1);
		else ff.add_edge(array[r-1][c-1],ver_sum-1,1); 
	}

	#ifdef DEBUG
		ff.dump_E();
	#endif



	cout << ver_sum - ff.max_flow(ver_sum-2,ver_sum-1) - 2 << endl;

	return 0;
}






