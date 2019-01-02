#include <stdio.h>
#include <math.h>

short tmpval = 0;

void count(int i){
	tmpval = 0;
	while (i > 0){
		tmpval += i % 10;
		i /= 10;
	}
}

int main (void){
	long K;
	short dig = 0;
	short t = 1;
	long T;
	short i;
	short ans;
	long maxval;

	scanf("%ld",&K);
	T = K;

	/*Kの桁数を求め、digに格納*/
	while(t <= K){ 
		t *= 10;
		dig += 1;
	}

	/*探索の上限は10^(dig+1)*/
	maxval = pow(10,dig+1);

	i = 2;
	count(K);
	ans = tmpval;
	while(T <= maxval){
		T = K * i;
		count(T);
		if (tmpval < ans){
			ans = tmpval;
		}
		if (ans == 1){
			break;
		}
		i += 1;
	}
	printf("%d\n",ans);
}