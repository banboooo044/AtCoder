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

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int main(void){
	long r,c;
	cin >> r >> c;
	VVB arr(r,VB(c,false));
	char ch;

	REP(i,r){
		REP(j,c){
			cin >> ch;
			if (ch == '.') arr[i][j] = true;
		}
	}

	VVB arr_save = arr; 

	long count = 0;
	REP(i,r){
		
		REP(j,c){
			if (arr[i][j]) count1++;
		}
	}
	long count2 = 0;
	REP(i,r){
		for (long j = (i+1)%2;j < c;j+=2){
			if (arr[i][j]) count2++;
		}
	}
	cout << max(count1,count2) << endl;
	return 0;
}