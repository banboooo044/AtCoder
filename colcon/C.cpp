//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
typedef long long ll;
vector<ll>divisor;
ll A,B;

ll dfs(short i,ll bitmap){
	ll tmp_ans = 0;
	if (i > B-A) return 1;
	if ((divisor[i] & bitmap) == 0){
		tmp_ans += dfs(i+1,(divisor[i]|bitmap));
	}
	tmp_ans += dfs(i+1,bitmap);
	return tmp_ans;
}[]

int main(void){
	cin >> A >> B;
	ll ans;
	divisor = vector<ll>(B-A+1);
	vector<int>primenum = {2,3,5,7,11,13,17,19,23,29,31};

	FOR(i,A,B+1){
		REP(j,primenum.size()){
			if (primenum[j] > i) break;
			if (i % primenum[j] == 0){
				divisor[i-A] += (1 << j);
			}
		}
	}

	#ifdef DEBUG
		FOR(i,A,B+1) cout << "divisor[" << (i-A) << "] ==> " << divisor[i-A] << "\n";
	#endif

	ans = dfs(0,0);
	cout << ans << "\n";
	return 0;
}