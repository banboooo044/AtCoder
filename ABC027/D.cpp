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
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vec) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)

using namespace std;
typedef long long LL;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

int main(void) {
	string S;
	cin >> S;
	long l = S.size();
	VI move;
	VI get_score;
	long move_c = 0;
	long score_c = 0;
	bool flg = true;
	bool flg2 = false;
	REP(i,l) {
		if (S[i] == 'M') {
			if (flg2) get_score.push_back(score_c);
			flg = true;
			flg2 = false;
			move_c++;
			score_c = 0;
		}
		else {
			if (flg) move.push_back(move_c);
			flg = false;
			flg2 = true;
			move_c = 0;
			if (S[i] == '+') score_c++;
			else score_c--;
		}
	}
	if (score_c) get_score.push_back(score_c);
	if (move_c) move.push_back(move_c);
	long N = get_score.size();
	// dp[i][j] := i回移動(ポイント計算),j:ポイント(最大)
	VVI dp(N+1,VI(2*l+1,-loINF));
	dp[0][l] = 0;
	VI ans(2*l+1,-loINF);
	REP(i,N) {
		REP(j,2*l+1) {
			for(long k = (move[i]%2);k < move[i]+1;k += 2){
				if (j-k >= 0 && dp[i][j-k] != (-loINF)) {
					dp[i+1][j] = max(dp[i][j-k] + (j-l)*get_score[i],dp[i+1][j]);
				}
				if (j+k < (2*l+1) && dp[i][j+k] != (-loINF)) {
					dp[i+1][j] = max(dp[i][j+k] + (j-l)*get_score[i],dp[i+1][j]);
				}
			}
		}
	}
	if (move.size() > N) {
		REP(j,2*l+1) {
			for(long k = (move[N]%2);k < move[N]+1;k += 2) {
				if (j-k >= 0 && dp[N][j-k] != (-loINF)) {
					ans[j] = max(dp[N][j-k],ans[j]);
				}
				if (j+k < (2*l+1) && dp[N][j+k] != (-loINF)) {
					ans[j] = max(dp[N][j+k],ans[j]);
				}
			}
		}
		cout << ans[l] << endl;
	}
	else {
		cout << dp[N][l] << endl;
	}

	return 0;
}











