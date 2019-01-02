#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define loINF (long)10000000000
#define shINF (short)10000
#define DEBUG

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

int main (void){
	char flag;
	long N;
	short A,B;
	LL sum = 0;
	long num;
	short rownum;


	cin >> N >> A >>  B;


	while (A <= B){

	if (A < 10) num = A;
	if (A >= 10 && A < 19) num = (A - 9)*10 + 9;
	if (A >= 19 && A < 28) num = (A - 18)*100 + 99;
	if (A >= 28) num = (A-27)*1000 + 999;

	#ifdef DEBUG
		dump(num);
	#endif

	rownum = num;
	
	while (num <= N){
		if (num > 100){
			num = rownum-1 + 100;
		}
		sum += num;
		num += 9;
	}

	A += 1;

	#ifdef DEBUG
		dump(num);
		dump(sum);
	#endif
	}

	cout << sum << endl;

	return 0;
}