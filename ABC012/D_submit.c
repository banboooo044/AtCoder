#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define INF (short)10000


short* dis;
short* edge;
short* edge_reverse;
short M;
short N;

short bellman_ford (short* dis,short* edge,short* edge_reverse,short start){
	/*startからendへの最短距離を返す*/
	dis[start] = 0;
	char update;
	short i,j;
	short tmp_start,tmp_end,tmp_t;
	short maxval = 0;

	while(1){
		update = 0;
		REP(i,M){
			tmp_start = dis[edge[i]];
			tmp_end = dis[edge[i+M]];
			tmp_t = edge[i+2*M];

			if ((tmp_start != INF) && ( tmp_end > tmp_start + tmp_t )){
				dis[edge[i+M]] = tmp_start + tmp_t;
				update = 1;
			}
		}

		REP(i,M){
			tmp_start = dis[edge_reverse[i]];
			tmp_end = dis[edge_reverse[i+M]];
			tmp_t = edge_reverse[i+2*M];

			if ((tmp_start != INF) && ( tmp_end > tmp_start + tmp_t )){
				dis[edge_reverse[i+M]] = tmp_start + tmp_t;
				update = 1;
			}
		}


		if (update == 0){
				break;
			}
	}

	FOR(i,1,N+1){
		if ( maxval < dis[i] ){
			maxval = dis[i];
		} 

	}

	return maxval;
}

int main (void){
	short i,j;
	short minval = INF;
	short tmp;
	short f;
	
	
	scanf("%hd",&N);
	scanf("%hd",&M);


	dis = (short*)malloc(sizeof(short) * (N+1) );
	edge = (short*)malloc(sizeof(short) * M * 3 );
	edge_reverse = (short*)malloc(sizeof(short) * M * 3 );

	REP(i,N+1){
		dis[i] = INF;
	}

	REP(i,M){
		f = scanf("%hd%hd%hd",&edge[i],&edge[i+M],&edge[i+2*M]);

		edge_reverse[i+M] = edge[i];
		edge_reverse[i] = edge[i+M];
		edge_reverse[i+2*M] = edge[i+2*M];

	}

	for(i = 1;i < (N+1);i++){
		tmp = bellman_ford(dis,edge,edge_reverse,i);

		if (minval > tmp){
			minval = tmp;
		}

		REP(j,(N+1)){
			dis[j] = INF;
		}
	}

	printf("%d\n",minval);

	free(dis);
	free(edge);
	free(edge_reverse);

	return 0;
}