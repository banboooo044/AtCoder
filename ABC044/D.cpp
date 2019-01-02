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


long long func(long b,long long n){
	if (b > n) return n;
	else return func(b,floor((double)n/(double)b)) + (n % b);
}
int main(void){
	long long n;
	long long s;
	cin >> n;
	cin >> s;

	if (n == s) {
		cout << (n+1) << endl;
		exit(0);
	}
	long iter_m = sqrt(n);
	FOR(b,2,iter_m+1){
		if (func(b,n) == s) {
			cout << b << endl;
			exit(0);
		}
	}

	//dump(iter_m);
	long ns = n-s;
	if (ns <= 0) cout << (-1) << endl;
	else {
		long m = sqrt(ns);
		long long ans = llINF;
		FOR(i,1,m+1){
			if (ns % i == 0){
				if ((ns/i) >= iter_m && (s-i) >= 0 && ((s-i) < (ns/i)+1)) ans = min(ans,(long long)(ns/i) + 1);
			}
		}
		if (ans == llINF) cout << (-1) << endl;
		else {
			cout << ans << endl;
			/*
			long long p = ns/(ans-1);
			long long q = s - p;
			dump(p);
			dump(q);*/
		}
	}

	return 0;
}