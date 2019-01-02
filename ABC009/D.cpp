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
constexpr long mod = 1000000007;
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
class Matrix {
public:
	typedef long long LL;
	LL H,W;
	vector<vector<T>> mat;
	Matrix(LL h,LL w) : mat(h,vector<T>(w)),W(w),H(h) {}
	Matrix(LL h,LL w,LL val) : mat(h,vector<T>(w,0)),W(w),H(h){ // 単位行列
		for (LL i = 0;i < min(h,w);++i) mat[i][i] = val;
	}

	Matrix(vector<vector<T>> x) : mat(x),W(x[0].size()),H(x.size()){}

	bool operator == (Matrix &m){
		if (m.H != H || m.W != W) return false;
		else {
			for (LL i = 0;i < H;i++) for (LL j = 0;j < W;j++)
				if (mat[i][j] != m.mat[i][j]) return false;
		}
		return true;
	}

	bool operator != (Matrix &m){return (! (this == m));}
	Matrix operator = (Matrix &m){ mat = m.mat; return this;}
	vector<T> & operator [](LL n) {
		if( n < 0 || n > H) abort();
		return mat[n];
	}

	vector<vector<T>> toVec(void) {
		return this->mat;
	}

	Matrix operator + (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] + m.mat[i][j]);
		return tmp;
	}

	void operator += (const Matrix &m){
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j)
				mat[i][j] += m.mat[i][j];
	}

	Matrix operator - (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] - m.mat[i][j]);
		return tmp;
	}

	void operator -= (const Matrix &m){
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j)
				mat[i][j] -= m.mat[i][j];
	}

	Matrix operator * (const Matrix &m){
		LL W2 = m.mat[0].size();
		Matrix ret(vector<vector<T>>(H,vector<T>(W2,0)));
		for(LL i = 0;i < H;++i) for (LL k = 0;k < H;++k) for (LL j = 0;j < W2;++j)
			ret.mat[i][j] += (mat[i][k] * m.mat[k][j]);
		return ret;
	}

	void operator *= (const Matrix &m){
		LL W2 = m.mat[0].size();
		vector<vector<T>> ret(H,vector<T>(W2,0));
		for(LL i = 0;i < H;++i) for (LL k = 0;k < H;++k) for (LL j = 0;j < W2;++j)
			ret[i][j] += (mat[i][k] * m.mat[k][j]);
		mat = ret;
	}

	Matrix operator / (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] / m.mat[i][j]);
		return tmp;
	}

	void operator /= (const Matrix &m) {
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j)
				mat[i][j] /= m.mat[i][j];
	}

	Matrix operator % (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] % m.mat[i][j]);
		return tmp;
	}

	void operator %= (const Matrix &m) {
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j)
				mat[i][j] %= m.mat[i][j];
	}

	Matrix operator | (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] | m.mat[i][j]);
		return tmp;
	}

	void operator |= (const Matrix &m) {
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j)
				mat[i][j] |= m.mat[i][j];
	}

	Matrix operator ^ (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] ^ m.mat[i][j]);
		return tmp;
	}

	void operator ^= (const Matrix &m) {
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j)
				mat[i][j] ^= m.mat[i][j];
	}

	Matrix operator & (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] & m.mat[i][j]);
		return tmp;
	}

	void operator &= (const Matrix &m) {
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j)
				mat[i][j] &= m.mat[i][j];
	}

	Matrix hadamard (Matrix &m){
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] * m.mat[i][j]);
		return tmp;
	}

	Matrix intpow (const LL &n){
		Matrix<T> m(mat),ret(H,W,1);
		for (LL i = 0;(1 << i) <= n;++i) {
			if ((n >> i) & 1) ret *= m;
			m *= m;
		}
		return ret;
	}

	Matrix bitpow (const LL &n){
		Matrix<T> m(mat),ret(H,W,~0);
		for (LL i = 0;(1 << i) <= n;++i) {
			if ((n >> i) & 1) ret.bitProductEqual(m);
			m.bitProductEqual(m);
		}
		return ret;
	}

	Matrix bitProduct (const Matrix &m){
		LL W2 = m.mat[0].size();
		Matrix ret(vector<vector<T>>(H,vector<T>(W2,0)));
		for(LL i = 0;i < H;++i) for (LL k = 0;k < H;++k) for (LL j = 0;j < W2;++j)
			ret.mat[i][j] ^= (mat[i][k] & m.mat[k][j]);
		return ret;
	}

	void bitProductEqual (const Matrix &m){
		LL W2 = m.mat[0].size();
		vector<vector<T>> ret(H,vector<T>(W2,0));
		for(LL i = 0;i < H;++i) for (LL k = 0;k < H;++k) for (LL j = 0;j < W2;++j)
			ret[i][j] ^= (mat[i][k] & m.mat[k][j]);
		mat = ret;
	}
};

typedef Matrix<LL> MT;
int main(void) {
	LL K,M;
	cin >> K >> M;
	VVI C(K,VI(K,0));
	VVI A(K,VI(1));
	REP(i,K) cin >> A[K-i-1][0];
	REP(i,K) cin >> C[0][i];
	REP(i,K-1) C[i+1][i] = ~0;
	MT m(C),a(A);
	if (M - K > 0) {
		MT ret = m.bitpow(M-K);
		MT ans = (ret.bitProduct(a));
		cout << ans[0][0] << endl;
	}
	else {
		cout << A[K-M][0] << endl;
	}
}



