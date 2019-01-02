#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));

int main(){
	int n,k; cin >> n >> k; int a[5010];
	REP(i,0,n) cin >> a[i];
	
	ll s = 0; sort(a, a+n); reverse(a, a+n);	//大きい順に並べる。
	int ans = n;
	REP(i,0,n){
		if(s + a[i] < k) s += a[i];
		else ans = n - i - 1;
	}
	
	cout << ans << endl;
	return 0;
}


