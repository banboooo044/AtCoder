#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)

using namespace std;
const long INF=1e9;

int main(void){
	short N;
	short tmp;
	long ans = INF;

	cin >> N;

	REP(i,N){
		cin >> tmp;
		if (ans > tmp)
			ans = tmp;
	}

	cout << ans << "\n";

	return 0;

}