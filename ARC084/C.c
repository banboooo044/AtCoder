#include <stdio.h>
#include <stdlib.h>

int comp( const void *c1, const void *c2 )
{
  int tmp1 = *(int *)c1;
  int tmp2 = *(int *)c2;

  if( tmp1 < tmp2 )  return -1;
  if( tmp1 == tmp2 ) return  0;
  if( tmp1 > tmp2 )  return  1;

}


int main (void){

	int N;
	int A[10000],B[10000],C[10000];
	int i;

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}

	qsort(A,N, sizeof(int), comp);

	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}

	qsort(B,N, sizeof(int), comp);

	for(i=0;i<N;i++){
		scanf("%d",&C[i]);
	}

	qsort(C,N, sizeof(int), comp);


	int ans = 0;
	int tmp_ans = 0;
 	int tmp = 0;
 	int j,k;

 	for (i=0;i <N ;i++){
 		if (0 < i){
 			if ( A[i-1] == A[i]){
 				ans += tmp_ans;
 				continue;
 			}
 		}
 		for (j=0;j<N;j++){
 			tmp_ans = ans;
 			if (0 < j){
 			if ( B[j-1] == B[j]){
 				ans += tmp;
 				tmp_ans += tmp;
 				continue;
 			}
 			}

 			if ( B[j] > A[i]){

 			for(k=0;k<N;k++){
 				if(C[k] > B[j]){
 					tmp = (N-k);
 					ans += (N-k);
 					break;
 				}
 			}

 			}
 			tmp_ans = ans - tmp_ans;
 		}
 	}
 	printf("%d\n",ans);
 	return 0;

}
