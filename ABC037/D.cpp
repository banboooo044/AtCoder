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
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
typedef vector<pr> VP;

short dx[2] = {0,1};
short dy[2] = {1,0};
VI ans;
VVI e;
long dfs(long node){
	if (ans[node] != (-1)) return ans[node];
	long sum = 1;
	REP(i,e[node].size()) {
		sum += (dfs(e[node][i]) % 1000000007);
		sum %= 1000000007;
	}
	return ans[node] = sum;
}

int main(void) {
	short H,W;
	cin >> H >> W;
	VVI a(H,VI(W,0));
	e = VVI (H*W,VI(0));
	long maxval = 0;
	REP(i,H) REP(j,W) cin >> a[i][j];
	//(i + dx[])*W + (j + dy[])
	REP(i,H) {
		REP(j,W) {
			if (j < (W-1) && a[i+dx[0]][j+dy[0]] > a[i][j]) e[i*W+j].push_back((i + dx[0])*W + (j + dy[0]));
			else if (j < (W-1) && a[i+dx[0]][j+dy[0]] < a[i][j]) e[(i + dx[0])*W + (j + dy[0])].push_back(i*W+j);
			if (i < (H-1) && a[i+dx[1]][j+dy[1]] > a[i][j]) e[i*W+j].push_back((i + dx[1])*W + (j + dy[1]));
			else if (i < (H-1) && a[i+dx[1]][j+dy[1]] < a[i][j]) e[(i + dx[1])*W + (j + dy[1])].push_back(i*W+j);
		}
	}
	ans = VI (H*W,-1);
	long sumval = 0;
	REP(i,H*W) {
		sumval += dfs(i);
		sumval %= 1000000007;
	}
	//dump1d_arr(ans);
	cout << sumval << endl;
	return 0;
}