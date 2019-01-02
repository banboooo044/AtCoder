#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (i=0;i<(n);i++)
#define FOR(i,a,b) for (i=(a);i<(b);i++)
#define loINF (long)10000000000
#define shINF (short)10000
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))


long ans1[100];
long ans2[100];
long minas[100];

void quick_sort(long x[],int left,int right)
{
	int i,j;
	long pivot;


	i = left;
	j = right;

	if ((left+right)%2 == 1)
		pivot = x[(left+right+1)/2];

	else
		pivot = x[(left+right)/2]; /*基準値を配列の中心に設定*/

	printf("pivot:%d\t",pivot);
	
	while(1){

		while(x[i] <  pivot) {/*pivotより大きい値が出るまで左端から調べる*/

			i++;
		}

		while(pivot < x[j])	 {/*pivotより小さい値がでるまで右端から調べる*/ /*デバッグ用*/
			j--;
		}

		if (i >= j)			/*pivotまで調べたらループ抜け。pivotを変えて次の段階へ*/
			break;

		plus(x,i,j);		
		i++;				/*同様の操作を繰り返す*/
		j--;


	}

	/*この時点でiとjはpivotの添え字の値になっている*/

	if(left < (i -1))
		quick_sort(x,left,i-1);   /*pivotの左に2以上の要素があれば左の配列をソートする*/
	if((j + 1 )< right)
		quick_sort(x,j+1,right);	  /*pivotの右に2以上の要素があれば右の配列をソートする*/

}
void plus(long* a,int i,int j)

int main(void){
	short N;
	short i;
	long a[55];
	scnaf("%hd",&N);

	REP(i,N){
		scanf("%ld",&a[i]);
	}

	quick_sort(a,0,N-1);

	printf(ans)

}