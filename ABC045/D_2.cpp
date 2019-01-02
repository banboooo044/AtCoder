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
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vet) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << "(" << itr->first.first << "," << itr->first.second << ") --> "  << itr->second << endl; }

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
typedef map<pr,long> mp;

int main(void){
	long H,W,N,a,b;
	mp center;
	VI ans(10,0);
	cin >> H >> W >> N;
	REP(i,N) {
		cin >> a >> b;
		center[pr(a-1,b-1)]++;
		if (b >= 2) center[pr(a-1,b-2)]++;
		if (b <= (W-1)) center[pr(a-1,b)]++;
		if (a >= 2){
			center[pr(a-2,b-1)]++;
			if (b >= 2) center[pr(a-2,b-2)]++;
			if (b <= (W-1)) center[pr(a-2,b)]++;
		}
		if (a <= (H-1)){
			center[pr(a,b-1)]++;
			if (b >= 2) center[pr(a,b-2)]++;
			if (b <= (W-1)) center[pr(a,b)]++;
		}
	}

	//dump_MAP(center);

	for (auto itr = center.begin();itr != center.end();++itr){
		if (itr->first.first == 0 || itr->first.second == 0 || itr->first.first == (H-1) || itr->first.second == (W-1)) continue;
		ans[itr->second]++;
	}

	long long sumval = (H-2) * (W-2);
	FOR(i,1,10) sumval -= ans[i];
	cout << sumval << endl;
	FOR(i,1,10){
		cout << ans[i] << endl;
	}

	return 0;
}

