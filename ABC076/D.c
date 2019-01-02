#include <stdio.h>
#include <stdlib.h>

int main (void){

int N;
int i,j;
int t[110],v[110];		/*tの値とvの値を格納*/
double gragh[500];	
int sumt;
double tmp;

/*Nの入力*/
scanf("%d",&N);

t[0] = 0;

/*tの入力*/
for(i=0;i<N;i++)
    scanf("%d",&t[i+1]);

/*tの配列を累積時間にする*/
for (i = 2;i < N+1;i++)
 	t[i] += t[i-1];

/*累積最終時間が終了時間*/
sumt = t[N];

/*vの入力*/
for(i=0;i<N;i++){
 	scanf("%d",&v[i]);
}

/*配列tと配列vの要素をチェックする*/
#ifdef DEBUG
printf("\n-----t------\n");
for (j=0;j<N+1;j++){
	printf("%d,",t[j]);
}
/*ここでsegmentation fault 11*/
printf("\n-----v------\n");
for (j=0;j<N;j++){
	printf("%d,",v[j]);
}
#endif

/*graghの最初の状態をつくる*/
for (i=1;i < sumt*2+1;i++){ 

	if (i < sumt+1){
 		gragh[i] = (double)i/2;
 	}

	else{
 		gragh[i] = gragh[i-1] - 0.5;
 	}

}



#ifdef DEBUG

for (i = 0;i < sumt*2+1;i++){
 	printf("%lf,",gragh[i]);
 }


printf("\n-----t------\n");

for (j=0;j<N+1;j++)
	printf("%d,",t[j]);

printf("\n-----v------\n");

for (j=0;j<N;j++)
	printf("%d,",v[j]);

#endif 

/*デバッグここまで*/

/*グラフを作成する*/
printf("-----a");
for(j=0;j<N;j++){
	for(i=1;i<sumt*2+1;i++){
		printf("%d\n",i);
		if (t[j]*2 > i){
			tmp = ((double)t[j]+(double)v[j]-(double)i/2);
			if (gragh[i] > tmp){
				gragh[i] = tmp;
			}
		}
		else{if ((t[j]*2 <= i) && (i <= (t[j+1]*2))){
			if (gragh[i] > (double)v[j]){
				gragh[i] = (double)v[j];
			}
		}
		else {
			tmp = ((double)v[j]+0.5*(double)(i-t[j+1]*2));
			if (gragh[i] > tmp){
				gragh[i] = tmp;
			}
		}
	}
	}
}


/*デバッグここから*/
#ifdef DEBUG
for (i = 0;i < sumt*2+1;i++){
 	printf("%lf,",gragh[i]);
 }
#endif
/*デバッグここまで*/


/*面積の計算*/
double val = 0.0;
for(i=0;i<sumt*2;i++){
	if (gragh[i] != gragh[i+1]){
		val += ((gragh[i]+gragh[i+1]) * 0.25);
	}
	else{
		val += ((gragh[i]) * 0.5);
	}
}

/*答えの出力*/
printf("%lf\n",val);
return 0;
}


