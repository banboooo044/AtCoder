#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define loINF (long)10000000000
#define shINF (short)10000
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main (void){
	long W;
	short N,K;
	short A[120],B[120];
	short i,j,k;

	short dp[10005][55];

	scanf("%ld",&W);
	scanf("%hd",&N);
	scanf("%hd",&K);

	REP(i,N){
		scnaf("%hd",&A[i]);
		scanf("%hd",&B[i]);
	}

}

