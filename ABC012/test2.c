#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define INF (short)500
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define DEBUG 

short dis[3] = {INF,INF,INF};
short edge[6] = {1,2,2,3,10,10};
short N = 3;
short M = 2;

void func(short* i,short* j){

	short k;

	REP(k,N){
		printf("i[%d] ==> %d\n",k,i[k]);
		printf("j[%d] ==> %d\n",k,j[k]);
	}
}

int main (void){
	func(dis,edge);
	return 0;
}