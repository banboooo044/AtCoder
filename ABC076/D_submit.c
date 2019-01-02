#include <stdio.h>
#include <stdlib.h>

int main (void){
	int	N;
	int	i,j;
	int	t[250],v[150];	/*tの値とvの値を格納*/
	double	gragh[1000000];	
	int	sumt;
	double	tmp;

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

	/*graghの最初の状態をつくる*/
	for (i=1;i < sumt*2+1;i++){ 

		if (i < sumt+1){
 			gragh[i] = (double)i/2;
 		}

		else{
 			gragh[i] = gragh[i-1] - 0.5;
 		}

	}

	for(j=0;j<N;j++){
	for(i=1;i<sumt*2+1;i++){
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