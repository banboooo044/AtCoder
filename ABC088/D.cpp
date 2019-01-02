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
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef pair<long,long> P;
typedef vector<long> VI;
typedef vector<VI> VVI;

int main(void){
	short dx[4] = {1,0,-1,0};
	short dy[4] = {0,1,0,-1};

	short H,W;
	cin >> H >> W;
	VVI d(H,VI(W,loINF));
	long cnt = 0;

	VVC arr(H,VC(W));

	REP(i,H){
		REP(j,W){
			cin >> arr[i][j];
			if (arr[i][j] == '#') cnt ++;
		}
	}

	queue<P> que;
	que.push(P(0,0));
	d[0][0] = 0;

	while(!que.empty()){
		P p = que.front();
		que.pop();

		if (p.first == (W-1) && p.second == (H-1)) break;

		REP(i,4){
			long nx = p.first + dx[i];
			long ny = p.second + dy[i];

			if ( 0 <= nx && nx < W && 0 <= ny && ny < H && arr[ny][nx] != '#' && d[ny][nx] == loINF){
				que.push(P(nx,ny));
				d[ny][nx] = d[p.second][p.first] + 1;
			}
		}
	}

	if (d[H-1][W-1] == (loINF)) {
		cout << (-1) << endl;
		exit(0);
	}

	cout << H * W - (d[H-1][W-1]+1) - cnt << endl;
	return 0;
}