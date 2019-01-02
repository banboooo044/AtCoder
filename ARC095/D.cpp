#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define llINF (long long) 9223372036854775807
#define loINF (long) 2147483647
#define shINF (short) 32767
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;

template <typename T>
class Integer {
private:
	const long mod = 1000000007;
	bool primeflg;
	bool factorialflg;
	vector<T> prime_list;
	vector<T> factorial;
	map<T,long> factoring;
	vector<long> prime_num;
	vector<bool> prime_table;

	void factorialModInit(T maxval) {
		factorialflg = true;
		factorial = vector<T>(maxval+1); 
		factorial[0] = factorial[1] = 1;
		for (T i = 2;i < (maxval+1);i++) {
			factorial[i] = (factorial[i-1]*i)%mod;
		}
	}

public:
	Integer()  : primeflg(false),factorialflg(false) {}

	//素数関連
	void Eratosthenes(T n) { // n以下の数でエラトステネスのふるいを作る。 
		primeflg = true;
		prime_table = vector<bool>(n+1,true);
		prime_num = vector<long>(n+1,0);
		T maxiter = sqrt(n);
		for(T i = 2;i < maxiter+1;i++){
			if (prime_table[i]) {
				for (T j = (i + i);j <= n;j += i){
					prime_table[j] = false;
				}
			}
		}
		T prnum = 0;
		for(T i = 2;i < n+1;i++){
			if (prime_table[i]) {
				prnum++;
				prime_list.push_back(i);
			}
			prime_num[i] = prnum;
		}
	}

	bool isPrimeNum(T n) { //素数かどうか判定
		if (!primeflg) Eratosthenes(max(n,(T)100)); 
		return prime_table[n];
	}

	vector<T>* getPrimeList(T n = 100){ //n以下の素数リスト
		if (!primeflg) Eratosthenes(n); 
		return (&prime_list);
	}

	long getPrimeNumUnder_N(T n) { //n以下の素数の個数。
		if (!primeflg) Eratosthenes(max(n,(T)100));
		return prime_num[n];
	}

	long getPrimeNum_NM(T k,T m){  //k以上m以下の素数の個数。(kはN以下ならok)
		if (!primeflg) Eratosthenes(max(m,(T)100)); 
		return prime_num[m] - prime_num[k];
	}

	//約数倍数関連
	map<T,long>* getFactoring(T n) { // 素因数分解 key->因数 val->因数の数
		T copy_n = n;
		T maxiter = sqrt(n);
		for (T i = 2;i < maxiter+1;i ++) {
			if (copy_n == 1) break;
			while (!(copy_n % i)) {
				if (IN(i,factoring)) factoring[i]++;
				else factoring[i] = 1;
				copy_n /= i;
			}
		}
		return (&factoring);
	}

	T gcd(T a,T b) {
 		 return b != 0 ? gcd(b, a % b) : a;
	}

	T lcm(T a,T b) {
  		return (a / gcd(a, b))*b;
	}

	long getFactorial(T n) { // nの階乗の値を求める。
		if (!factorialflg) factorialModInit(n);
		return factorial[n];
	}

	long long square_pow(long long a,long x){ // (a^x) % mod (繰り返し二乗)
		T p = a;
		T q = 1LL;
		while (x != 0){
			if (x & 1) q = (q * p) % mod;
			p = (p * p) % mod;
			x >>= 1;
		}	
		return q;
	}

	long long mod_inv(long long a) { // aの逆元 % mod
		return square_pow(a,mod-2);
	}

	long long nCr(T n,T r) {
		if (r > n / 2) r = n - r;
		long long retval = 1;
		for (long i = 1;i < r+1;i ++){
			retval *= n - r + i;
			retval /= i;
		}

		return retval;
	}

	long long nCrMod(T n,T r) { // nCr 使用前に初期化必要
		if (!factorialflg) factorialModInit(n);
		return (((factorial[n]%mod * mod_inv(factorial[r]))%mod) * mod_inv(factorial[n-r]))%mod;
	}

	long long nPrMod(T n,T r) {
		if (!factorialflg) factorialModInit(n);
		return ((factorial[n]%mod) * mod_inv(factorial[n-r]))%mod;
	}
};


int main(void){
	long n;
	cin >> n;
	VI a(n),cand;
	REP(i,n) cin >> a[i];
	SORT(a);
	long l = a[n-1];
	Integer<long long> it;
	long long val = -1;
	long mid = l/2;
	long ans,p;
	long v = loINF;
	if (!l%2){
		REP(i,n){
			if (a[i] != l && abs(a[i]-mid) < v) {
				v = abs(a[i]-mid);
				ans = a[i];
			}
		}
	}
	else {
		REP(i,n){
			if (a[i] != l){
				p = min(abs(a[i]-mid),abs(a[i]-(mid+1)));
				if (p < v) {
					v = p;
					ans = a[i];
				}
			}
		}
	}
	cout << l << " " << ans << endl;
	return 0;
}
