#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

//const long long int MOD = 1000000007;
//const int MOD = 1000000007;
const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

int dp[301][90001];
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class Key,class Value> ostream& operator << (ostream &s, map<Key,Value> M)
{ for ( auto itr = begin(M); itr != end(M); ++itr) { s << itr->first << ":" << itr->second; } return s;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	int sum = accumulate(v.begin(), v.end(), 0);
	dp[0][0] = 2;
	dp[0][v[0]] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 90000; j++) {
			dp[i][j] = dp[i - 1][j] * 2;
			dp[i][j] %= MOD;
		}
		for (int j = v[i]; j <= 90000; j++) {
			dp[i][j] += dp[i - 1][j - v[i]];
			dp[i][j] %= MOD;
		}
	}
	long long int ans = 1;
	for (int i = 0; i < N; i++) {
		ans *= 3;
		ans %= MOD;
	}
    cout << ans << endl;
	long long int minus = 0;
    cout << dp[N-1][(sum+1)/2] << endl;
	for (int i = (sum + 1) / 2; i <= 90000; i++) {
		minus+= dp[N - 1][i];
		minus %= MOD;
	}
	ans -= minus * 3;
	ans += MOD;
	ans += MOD;
	ans += MOD;
	ans %= MOD;
	for (int i = 0; i <= 300; i++) {
		for (int j = 0; j <= 90000; j++)dp[i][j] = 0;
	}
	dp[0][0] = 1;
	dp[0][v[0]] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 90000; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		for (int j = v[i]; j <= 90000; j++) {
			dp[i][j] += dp[i - 1][j - v[i]];
			dp[i][j] %= MOD;
		}
	}
	if (sum % 2 == 0) {
		ans += dp[N - 1][sum / 2];
		ans %= MOD;
		ans += dp[N - 1][sum / 2];
		ans %= MOD;
		ans += dp[N - 1][sum / 2];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
