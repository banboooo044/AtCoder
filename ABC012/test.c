#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define INF (short)1000000
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define DEBUG 

short di[3] = {INF,INF,INF};
short ede[6] = {1,2,2,3,10,10};
short N = 3;
short M = 2;

short bellman_ford (short* dis,short* edge,short start){
	/*startからendへの最短距離を返す*/

	dis[start] = 0;
	char update;
	short i;
	short tmp_start,tmp_end,tmp_t;
	short maxval = 0;
	short j = 0;


	while(j < 50){
		update = 0;
		REP(i,M){
			printf("iの値 ==> %d\n",i);
			tmp_start = dis[edge[i]];
			tmp_end = dis[edge[i+M]];
			tmp_t = edge[i+2*M];

			#ifdef DEBUG
			printf("tmp_t ==> %d\n",tmp_t);
			#endif

			if ((tmp_start != INF) && ( tmp_end > tmp_start + tmp_t )){
				printf("更新 %d ==> %d\n",tmp_end,tmp_start+tmp_t);
				dis[edge[i+M]] = tmp_start + tmp_t;
				update = 1;
			}
		}
		if (update == 0){
				break;
		}

		j++;
	}

	#ifdef DEBUG
		FOR(i,1,N){
			printf("dis[%d] ==> %d\n",i,dis[i]);
		}
	#endif


	FOR(i,1,N){
		if ( maxval < dis[i] ){
			maxval = dis[i];
		} 
	}


	#ifdef DEBUG
		printf("%dを始点として時の最遠値%d\n",start,maxval);
	#endif // DEBUG

	return maxval;
}
int main (void){
	bellman_ford(di,ede,1);
	return 0;
}