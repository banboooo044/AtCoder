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
typedef pair<long,long> pr;
typedef vector<pr> VP;
typedef vector<VP> VVP;

VI used;
VI dis;
VVP edge;
void dfs(long node){
    if (used[node]) return;
    used[node] = 1;

    REP(j,(long)edge[node].size()) {
        long next_node = edge[node][j].first;
        if (used[next_node]) {
            if (dis[next_node] != dis[node] + edge[node][j].second) {
                cout << "No" << endl;
                exit(0);
            }
        }
        else {
            dis[next_node] = dis[node] + edge[node][j].second;
            dfs(next_node);
        }
    }
}


int main(void) {
    long N,M;
    long  l,r,d;
    cin >> N >> M;
    edge = VVP(N+1,VP(0));
    dis = VI(N+1,0);
    used = VI(N+1,0);
    REP(i,M){
        cin >> l >> r >> d;
        edge[l].push_back(make_pair(r,d));
        edge[r].push_back(make_pair(l,-(d)));
    }

    FOR(i,1,N+1) {
        if (! used[i]) dfs(i); // スタートするノードの距離を0として始める。
    }

    cout << "Yes" << endl;
    return 0;
}