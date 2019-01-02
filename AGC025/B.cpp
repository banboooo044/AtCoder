#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
using namespace std;
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 998244353;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<pr> VP;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};

template <typename T>
class Integer {
private:
	bool primeflg;
	bool factorialflg;
	vector<T> prime_list;
	vector<T> factorial;
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
	map<T,long>* getFactoringMap(T n) { // 素因数分解 key->因数 val->因数の数
		map<T,long> factoring;
		T copy_n = n;
		T maxiter = sqrt(n);
		for (T i = 2;i < maxiter+1;i ++) {
			if (copy_n == 1) break;
			while (!(copy_n % i)) {
				factoring[i]++;
				copy_n /= i;
			}
		}
		if (copy_n != 1) factoring[copy_n]++;
		return (&factoring);
	}

	vector<long> getFactoringElement(T n) {
		vector<long> factoring;
		map<T,long>* m = getFactoringMap(n);
		for (auto itr = m.begin();itr != m.end();++itr) {
			factoring.push_back(itr->first);
		}
	} 

	// gcd(num ≤ N,K) = p を満たすnumの和
	/*
	T gcdSum(T N,T K,T p) {
		T n = n / p;
		T k = K / p;
		long long ret = (n*(n+1))/2;
		map<T,long> m = getFactoring(k);
		long l = m.size();
		long long maxbit = (1 << l);
		long long mul;
		long long p;
		for (auto itr = m.begin();itr != m.end();++itr) {
			FOR(bit,1,maxbit) {
				mul = 1;
				REP(j,l) if ((bit >> j) & 1) mul *= m[j];
				p = n/mul;
				if (__builtin_parityll(bit)) ret -= ((p*(p+1)/2)*mul);
				else ret += (((p*(p+1)/2))*mul);
			}
		}
		return (p*ret);
	}*/


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

int main(void) {
	Integer<LL> it;
	LL N,A,B,K,xo,yo,x,m,iterm,p,nx,nfact;
	cin >> N >> A >> B >> K;
	LL g = it.gcd(A,B);

	if (K % g != 0) {
		cout << "0" << endl;
		exit(0);
	}

	A /= g;
	B /= g;
	K /= g;

	REP(i,B+1) {
		if (!((K - i*A) % B)) {
			xo = i;
			yo = (K - i*A)/B;
			break;
		}
	}
	LL pat = 0;
	nfact = it.getFactorial(N);
	while (yo >= 0) {
		x = max(xo,yo);
		m = min(xo,yo);

		if (x > N) {
			xo += (g*B);
			yo -= (g*A);
			continue;
		}
		iterm = min(N-x+1,m+1);
		p = (((nfact
			*it.mod_inv(it.getFactorial(N-x)) % mod)
			*it.mod_inv(it.getFactorial(m)) % mod)
			*it.mod_inv(it.getFactorial(x-m)) % mod);
			nx = p;
			//dump(nx)
			FOR(k,1,iterm) {
				nx *= (N-x-(k - 1));
				nx %= mod;
				nx *= (m-(k-1));
				nx %= mod;
				nx *= it.mod_inv(k * (x-m+k));
				nx %= mod;
				//dump(nx)
				p += nx;
			}
		pat += p;
		xo += (g*B);
		yo -= (g*A);
	}
	cout << pat%mod << endl;
}


