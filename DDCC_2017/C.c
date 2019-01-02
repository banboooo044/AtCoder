#include <stdio.h>
#include <stdlib.h>

int main (void)
{

	/*二つの自然数(1~10000)を入力させ、連結されていなければ連結し、連結されていれば連結されていたと表示するプログラム*/
	int N,M;
	int* id;

	scanf("%d %d",&N,&M);

	id = (int*)malloc(sizeof(int)* (N+1)) ;

	int i,p,q,j,returnVal,count;

	for(i = 0; i < N+1; i ++)
	{
		id[i] = i;
	}

	for(i = 0; i <= M ;i ++)
	{
		returnVal = scanf("%d %d",&p,&q);

		if(returnVal == 2)
		{

			/*条件文がtrueなら変化文を実行する。
			配列の値と添え字が異なる場合、配列の値を添え字にして見にいく。*/
			/*連結されているツリーには必ず配列の値と添え字が同じ（自分自身を指す）要素が存在するので、そこまでたどって、その要素が同一のものならpとqは連結されていると考える*/
			for(i = p;i != id[i];i = id[i]);
			for(j = q;j != id[j];j = id[j]);

			if(i == j){
				continue;
			}
			id[i] = j;
		}
	}

	for (i = 0;i <= N ; i++)
	{
		printf("%d:%d\n",i,id[i]);
	}

	int a = 1;
	int point = 0;

	while (1){
		
		if (a > N){
				/*printf("%d",point);
				printf("%d",count);*/
				break;
			}

		for(i = a;i != id[i];i = id[i]);

		printf("%d",count);

		if(count > 5){
			point += 4;
			point += (count-5)*2;
		}
		else if (count > 2){
			point += 1;
			point += (count-3);
		}

		a ++;
		count = 0;
		

	}
}