#include <stdio.h>

int main (void)
{
	int N;
	int intans,minVal;

	int h,n,w;

	scanf("%d",&N);

	intans = (int)N/4;

	if (intans < 1) 
		intans = 1;

	minVal = (3 * N) / 4 + 1;

	long quo,mer;

	for(h = intans;h < minVal;h++){
		for (n = h;n < 3500;n ++){
			for (w = n;w < 3500;w ++){

				quo = (h * n + h * w + n * w);
				mer = (h * n * w);

				printf("%d%d%d\n",h,n,w);

				if((quo/mer == 4/N) && (quo % mer == 4 % N)){
					printf("%d %d %d",h,n,w);
				    return 0;
				}
			}
	}

}
}