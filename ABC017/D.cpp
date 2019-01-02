#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)




int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<ll> f(n + 1), f_c(m + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> f[i];
    }
    
    vector<ll> dp(n + 1);
    dp[0] = 1;
    ll sum = 0, idx = 0;
    
    for(int i = 1; i <= n; i++){
        while(f_c[f[i]] > idx){
            sum -= dp[idx];
            idx++;
        }
        sum += dp[i - 1];
        dp[i] = sum;
        dp[i] %= MOD;
        f_c[f[i]] = i;
        // cout << dp[i] << ' ';
    }
    //REP(i,n+1) cout << dp[i] << endl;
    // cout << endl;
    
    cout << dp[n] << endl;
}