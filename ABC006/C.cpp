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

int main (void){
	long N,M;
	long adult,old;
	cin >> N >> M;

	if (M % 2){
		adult = (M - 3) / 2;
		old = 1;
	}

	else {
		adult = (M) / 2;
		old = 0;
	}

	#ifdef DEBUG
	dump(adult);
	dump(old);
	#endif

	if (N > (adult + old)){
		cout << "-1 -1 -1" << endl;
		exit(0);
	}

	long adult_tmp;
	long child_tmp;
	long old_tmp;

	/* 2 * adultをどう減らすか。*/
	REP(i,(adult / 3) + 1){
		if (((adult - i - (adult - i*3)/2) + old) > N)
			continue;

		REP(j,((adult - i*3)/2)+1){
			#ifdef DEBUG
				dump(i);
				dump(j);
			#endif

			if ((adult - i - j + old) == N){
				cout << (adult - (i*3 + j*2)) << " " << (old + (i * 2)) << " " << j << endl;
				exit(0);
			}
		}
	}

	cout << "-1 -1 -1" << endl;
	return 0;
}