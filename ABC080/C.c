#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define loINF (long)10000000000
#define shINF (short)10000
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define DEBUG

int main(void){
	short N;
	short F[105][15];
	long P[105][15];
	long i,k;
	short j;
	long count,tmp_ans;
	long long ans;

	scanf("%hd",&N);

	REP(i,N){
		REP(j,10){
			scanf("%hd",&F[i][j]);
		}
	}

	REP(i,N){
		REP(j,11){
			scanf("%ld",&P[i][j]);
		}
	}
	count = 0;
	tmp_ans = 0;
	ans = -10000000000000;

	FOR(i,1,1<<10){
		REP(k,N){
			REP(j,10){
				if ((F[k][j]) & (i >> j))
					count += 1;
			}
			tmp_ans += P[k][count];
			count = 0;
		}

		if (ans < tmp_ans){
			ans = tmp_ans;
		}
		tmp_ans = 0;
	}
	printf("%lld\n",ans);
	return 0;
}