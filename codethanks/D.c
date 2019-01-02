#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define loINF (long)10000000000
#define shINF (short)10000
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

long gcd(long a,long b){
	long tmp;
	while(b){
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main(void){
	long m;
	long n;
	long ans,maxiter,lcm;
	long i,a,cou;
	scanf("%ld",&n);
	scanf("%ld",&m);

	n = n % m;
	if (n == 0){
		printf("0\n");
		exit(0);
	}
	
	if (n > m){
		lcm = (n * m) / gcd(n,m);
	}
	else{
		lcm = (n * m) / gcd(m,n);
	}

	maxiter = lcm / n;
	ans = 0;
	
	cou = n;

	while (1){
		if (n >= m){
			break;
		}
		ans = MAX(n%m,ans);
		n += cou;
	}
	/*
	REP(i,maxiter){
		a = n % m;
		ans = MAX(a,ans);
		n += cou;
	}
	*/

	printf("%ld\n",ans);

}