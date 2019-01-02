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
typedef vector<short> VI;
typedef vector<VI> VVI;

int main(void) {
	long H,W;
	char ch;
	cin >> H >> W;
	VVI array(H,VI(W,0));
	REP(i,H){
		REP(j,W){
			cin >> ch;
			if (ch == '.') array[i][j] = 1;
		}
	}
	VVI array_b = array;
	REP(i,H){
		REP(j,W){
			if (array[i][j]){
				if (i > 0) {
					array_b[i-1][j] = 1;
					if (j > 0) array_b[i-1][j-1] = 1;
					if (j < (W-1)) array_b[i-1][j+1] = 1;
				}
				if (i < (H-1)){
					array_b[i+1][j] = 1;
					if (j > 0) array_b[i+1][j-1] = 1;
					if (j < (W-1)) array_b[i+1][j+1] = 1;
				}
				if (j > 0) array_b[i][j-1] = 1;
				if (j < (W-1)) array_b[i][j+1] = 1;
			}
		}
	}

	//dump2d_arr(array);
	//dump2d_arr(array_b);

	bool flg;

	REP(i,H){
		REP(j,W){
			if (!array[i][j] && array_b[i][j]) {
				flg = false;
				if (i > 0){
					if (!array_b[i-1][j]) flg = true;
					else if (j > 0 && (!array_b[i-1][j-1])) flg = true;
					else if (j < (W-1) && (!array_b[i-1][j+1])) flg = true;
				}
				if (i < (H-1)){
					if (!array_b[i+1][j]) flg = true;
					else if (j > 0 && (!array_b[i+1][j-1])) flg = true;
					else if (j < (W-1) && (!array_b[i+1][j+1])) flg = true;
				}

				if (j > 0 && !array_b[i][j-1]) flg = true;
				if (j < (W-1) && !array_b[i][j+1]) flg = true;

				if (!flg) {
					cout << "impossible" << endl;
					exit(0);
				}
			}
		}
	}

	cout << "possible" << endl;

	REP(i,H){
		REP(j,W){
			if (array_b[i][j]) cout << ".";
			else cout << "#";
		}
		cout << endl;
	}
}