#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;

using namespace std;

typedef long long LL;
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
	vector<long> dist;
	vector<long> trace;
	bool createdDag;
	vector<bool> visited;
	vector<vector<pr>> DAG;
	size_t V;
public:
	Dijekstra() : V(0) { }
	Dijekstra(size_t v) :
		V(v),E(v,vector<pr>(0)),dist(v,2147483647),trace(v,2147483647) {}

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
		else return dist[goal];
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

	void showE(void){
		REP(i,V) {
			REP(j,E[i].size()) {
				dump(i)
				dump(E[i][j].first)
				dump(E[i][j].second)
			}
		}
	}
};

int main(void){
	long H,W,T;
	cin >> H >> W >> T;
	vector<string> s(H);
	Dijekstra dij(H*W),dij2(H*W);
	long st,gl;
	REP(i,H){
		REP(j,W-1){
			if (s[i][j] == 'S') st = W*i+j;
			if (s[i][j] == 'G') gl = W*i+j;   
			if (s[i][j+1] == '#') {
				dij.add_edge_directed(i*W+j,i*W+j+1,1000);
				dij2.add_edge_directed(i*W+j,i*W+j+1,1);
			}
			else {
				dij.add_edge_directed(i*W+j,i*W+j+1,1);
				dij2.add_edge_directed(i*W+j,i*W+j+1,1000);
			}
			if (s[i][j] == '#') {
				dij.add_edge_directed(i*W+j+1,i*W+j,1000);
				dij2.add_edge_directed(i*W+j+1,i*W+j,1);
			}
			else {
				dij.add_edge_directed(i*W+j+1,i*W+j,1);
				dij2.add_edge_directed(i*W+j+1,i*W+j,1000);
			}

			if (i != 0){
				if (s[i-1][j] == '#') {
					dij.add_edge_directed(i*W+j,(i-1)*W+j,1000);
					dij2.add_edge_directed(i*W+j,(i-1)*W+j,1);
				}
				else {
					dij.add_edge_directed(i*W+j,(i-1)*W+j,1);
					dij2.add_edge_directed(i*W+j,(i-1)*W+j,1000);
				}
				if (s[i][j] == '#') {
					dij.add_edge_directed((i-1)*W+j,i*W+j,1000);
					dij2.add_edge_directed((i-1)*W+j,i*W+j,1);
				}
				else {
					dij.add_edge_directed((i-1)*W+j,i*W+j,1);
					dij2.add_edge_directed((i-1)*W+j,i*W+j,1000);
				}
			}
		}
		if (s[i][W-1] == 'S') st = W*i+W-1;
		if (s[i][W-1] == 'G') gl = W*i+W-1;
		if (i != 0){
			if (s[i-1][W-1] == '#') {
				dij.add_edge_directed(i*W+W-1,(i-1)*W+W-1,1000);
				dij2.add_edge_directed(i*W+W-1,(i-1)*W+W-1,1);
			}
			else {
				dij.add_edge_directed(i*W+W-1,(i-1)*W+W-1,1);
				dij2.add_edge_directed(i*W+W-1,(i-1)*W+W-1,1000);
			}
			if (s[i][W-1] == '#') {
				dij.add_edge_directed((i-1)*W+W-1,i*W+W-1,1000);
				dij2.add_edge_directed((i-1)*W+W-1,i*W+W-1,1);
			}
			else {
				dij.add_edge_directed((i-1)*W+W-1,i*W+W-1,1);
				dij2.add_edge_directed((i-1)*W+W-1,i*W+W-1,1000);
			}
		}
	}

	dij.dijekstra(st);
	dij2.dijekstra(st);
	long r = dij.result_query(gl);
	long r2 = dij2.result_query(gl);
	long X = r / 1000;
	long X2 = (r2 % 1000);
	long ans1 = (T - (r%1000))/X;
	long ans2 = (T - (r2/1000))/X2;
	cout << max(ans1,ans2) << endl;

	return 0;
}