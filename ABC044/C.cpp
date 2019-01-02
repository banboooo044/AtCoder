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
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef map<short,short> mp;
int main(void){
	short N,A;
	short minv = shINF;
	mp num;
	cin >> N >> A;
	vector<short> x(N);
	REP(i,N){
		cin >> x[i];
		num[x[i]-A]++;
		if (minv > (x[i]-A)) minv = (x[i] - A);
		x[i] -= A;
	}

	SORT(x);

	if (minv > 0) cout << 0 << endl;
	else if (minv == 0) cout << ((1 << (num[0])) - 1) << endl;
	else {
		VI dp((-minv)+1,(0));
		for (auto itr=num.begin();itr != num.end();++itr) {
			if (itr->first > 0) break;
			dp[itr->first - minv] = (1 << (itr->second)) - 1;
		}
		dump_MAP(num);
		dump1d_arr(dp);

		REP(i,N){
			if (x[i] <= 0) continue;
			RREP(j,(-minv)){
				if (j - x[i] >= 0) {
					if (j == (-minv)) dp[j] = (dp[j - x[i]] * (dp[j]+1));
					else dp[j] += (dp[j - x[i]]);
				}
			}
		}
		dump1d_arr(dp);
		cout << dp[-(minv)] << endl;
		return 0;
	}
	return 0;
}