
//------------------------------------------ 
//  D.c
//
//------------------------------------------ 
#include <stdio.h>
#include <stdlib.h>

// Macro for Debugging
#define DEBUG
#define TMP

int main (void){

	int	N;
	int	i,j;
	int	t[110],v[110];	/*tの値とvの値を格納*/
	double	gragh[500];	
	int	sumt;
	double	tmp;

	printf("Program D.c Start! \n\n");

	printf("INPUT N: ==> ");
	scanf("%d",&N); /*Nの入力*/
	printf("N = %d\n\n", N);
	
	t[0] = 0;
	
	/* tの入力*/
	for(i = 0; i < N; i++){
		printf("INPUT t[%d]: ==> ", i+1);
		scanf("%d",&t[i+1]);
		printf("t[%d] == %d\n\n", i+1, t[i+1]);
	}

	/* tの配列を累積時間にする*/
	for (i = 2; i < N+1; i++){
 		t[i] += t[i-1];
	}

	/*累積最終時間が終了時間*/
	sumt = t[N];

	/*vの入力*/
	for(i = 0 ; i < N; i++){
		printf("INPUT v[%d]: ==> ", i);
 		scanf("%d",&v[i]);
		printf("v[%d] == %d\n\n", i, v[i]);
	}

#ifdef DEBUG
	/* 配列tと配列vの要素をチェックする */
	printf("\n-----t------\n");
	for (j = 0; j < N + 1; j++){
		printf("t[%d] = %d\n", j, t[j]);
	}

	/*  ここでsegmentation fault */
	printf("\n-----v------\n");

	for (j = 0; j < N; j++){
		printf("v[%d] = %d\n", j, v[j]);
	}
#endif

	{	int p = 0;
		printf("get p ==>");
		scanf("%d", &p);
		printf("\n");
	}
	printf("i: %d, sumt: %d, N: %d\n", i, sumt, N);

	/* graghの最初の状態をつくる */
	for (i = 1;i < sumt * 2 + 1; i++){ 
		if (i < sumt+1){
 			gragh[i] = (double)i/2;

 		}else{
 			gragh[i] = gragh[i-1] - 0.5;

 		}
	}

#ifdef DEBUG		/*デバッグここから*/

	for (i = 0;i < sumt * 2 + 1; i++){
 		printf("graph[%d] = %lf\n", i, gragh[i]);
 	}

	printf("\n-----t------\n");

	for (j = 0; j < N + 1; j++){
		printf("t[%d] = %d\n", j, t[j]);
	}

	printf("\n-----v------\n");

	for (j = 0; j < N; j++){
		printf("v[%d] = %d\n", j, v[j]);
	}

	printf("\n");

#endif 			/*デバッグここまで*/


	/* グラフを作成する */
	printf("-----a---\n");

	for(j = 0; j < N; j++){
		for(i = 1; i< sumt * 2 + 1; i++){
			printf("i = %d\n",i);
	
			if (t[j]*2 > i){
				tmp = ((double) t[j]+(double) v[j] - (double)i / 2);

				if (gragh[i] > tmp){
					gragh[i] = tmp;
				}
			} else{
				if ((t[j] * 2 <= i) && (i <= (t[j + 1] * 2))){
					if (gragh[i] > (double)v[j]){
						gragh[i] = (double)v[j];
					}

				} else {
					tmp = ((double)v[j] + 0.5*(double)(i - t[j+1] * 2));
					if (gragh[i] > tmp){
						gragh[i] = tmp;
					}

				}
			}
		}
	}



#ifdef DEBUG		/*デバッグここから*/

	for (i = 0; i < sumt *2 + 1; i++){
 		printf("graph[%d] = %lf\n", i, gragh[i]);

 	}

#endif			/*デバッグここまで*/


	/*面積の計算*/
	double val = 0.0;

	for(i = 0; i < sumt * 2; i++){
		if (gragh[i] != gragh[i+1]){
			val += ((gragh[i] + gragh[i+1]) * 0.25);
		} else{
			val += ((gragh[i]) * 0.5);
		}
}

	/* 答えの出力 */
	printf("val = %lf\n", val);

	printf("program terminated.\n\n");

	return 0;
}

//-----------------------------------------------------
// copyright (C) 2017 Koshizuka, All Rights Reserved.
//-----------------------------------------------------
