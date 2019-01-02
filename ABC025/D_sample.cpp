#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MOD = (int)1e9 + 7;

int x[25], pos[25];
vector<int> unused;
int dp[1<<25];

void calc(int s, int t){
	int y = t / 5, x = t % 5;
	if (s & (1<<t)) return;
	if (y > 0 && y < 4 && ((s >> (t-5)) ^ (s >> (t+5))) & 1) return;
	if (x > 0 && x < 4 && ((s >> (t-1)) ^ (s >> (t+1))) & 1) return;
	(dp[s | (1<<t)] += dp[s]) %= MOD;
}

int main()
{
	memset(x, 0, sizeof(x));
	memset(pos, -1, sizeof(pos));
	memset(dp, 0LL, sizeof(dp));

	unused.clear();
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	rep (i, 25){
		cin >> x[i];
		--x[i];
		if (x[i] < 0){
			unused.push_back(i);
		}else{
			pos[x[i]] = i;
		} // end rep
	} // end rep

	dp[0] = 1;
	for (int i = 0; i < 1<<25; ++i){
		if (dp[i] == 0) continue;
		int bit = __builtin_popcount(i);
		if (pos[bit] >= 0){
			calc(i, pos[bit]);
		}else{
			for (int j = 0; j < (int)unused.size(); ++j){
				calc(i, unused[j]);
			} // end for
		} // end if
	} // end for

	int res = dp[(1<<25) - 1];

	cout << res << endl;
	
	return 0;
}