/*a以下の3のつく非負整数の総数を求める*/

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


using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

int main (void){
	long N;
	short A,B;
	cin >> N >> A >> B;
	
	long num;

	LL sumval = 0;

	FOR(i,1,N+1){
		short sum = 0;
		long num = i;
		 while(num){
    		sum += num % 10;
    		num /= 10;
  		}
  		#ifdef DEBUG
  			dump(sum);
  		#endif

  		if ((A <= sum) && (sum <= B)) sumval += i;
	}

	cout << sumval << endl;
	return 0;
}