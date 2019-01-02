#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define loINF (long)10000000000
#define shINF (short)10000

using namespace std;
typedef vector<int> VI;



int main(void){
	short T,N,M;
	cin >> T;
	cin >> N;

	VI A(N,0);
	REP(i,N) cin >> A[i];

	cin >> M;
	VI B(M,0);
	REP(i,M) cin >> B[i];

	short a = 0;
	short b = 0;

	while (1){
		if ((a == N) || (b == M)) break;
		if ((A[a] <= B[b]) && (A[a] + T >= B[b])){
			++a;
			++b;
		}
		else{ 
			if (A[a] > B[b]){
				cout << "no" << endl;
				exit(0);
 			}
 			else {
 				++a;
 			}
 		}
	}
	if (b < M){
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}

	return 0;
}