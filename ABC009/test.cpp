#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
using namespace std;

template <typename T>
class Matrix {
public:
	typedef long long LL;
	LL H,W;
	bool lu_fi = false;
	vector<vector<T>> mat;
	vector<vector<double>> L,U;
	Matrix(LL h,LL w) : mat(h,vector<T>(w,0)),W(w),H(h) {} //0ベクトル
	Matrix(LL h,LL w,T val) : mat(h,vector<T>(w,0)),W(w),H(h){ // 値valの対角行列
		for (LL i = 0;i < min(h,w);++i) mat[i][i] = val;
	}
	Matrix(vector<T> x) : mat(1,x),W(x.size()),H(1){} //1次元ベクトルを行列へ
	Matrix(vector<vector<T>> x) : mat(x),W(x[0].size()),H(x.size()){} //2次元ベクトルを行列へ

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

	vector<vector<T>> toVec(void) {return this->mat;} //行列をvectorで返す

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

	Matrix hadamard (Matrix &m){ //アマダール積
		Matrix tmp(H,W);
		for(LL i = 0;i < H;++i) for (LL j = 0;j < W;++j) 
				tmp.mat[i][j] = (this->mat[i][j] * m.mat[i][j]);
		return tmp;
	}

	Matrix intpow (const LL &n){ //行列n乗
		Matrix<T> m(mat),ret(H,W,1);
		for (LL i = 0;(1 << i) <= n;++i) {
			if ((n >> i) & 1) ret *= m;
			m *= m;
		}
		return ret;
	}

	Matrix bitpow (const LL &n){ //bool環の行列n乗
		Matrix<T> m(mat),ret(H,W,~0);
		for (LL i = 0;(1 << i) <= n;++i) {
			if ((n >> i) & 1) ret.bitProductEqual(m);
			m.bitProductEqual(m);
		}
		return ret;
	}

	Matrix bitProduct (const Matrix &m){ //bool環の行列積
		LL W2 = m.mat[0].size();
		Matrix ret(vector<vector<T>>(H,vector<T>(W2,0)));
		for(LL i = 0;i < H;++i) for (LL k = 0;k < H;++k) for (LL j = 0;j < W2;++j)
			ret.mat[i][j] ^= (mat[i][k] & m.mat[k][j]);
		return ret;
	}

	void bitProductEqual (const Matrix &m){ //bool環の行列積equal
		LL W2 = m.mat[0].size();
		vector<vector<T>> ret(H,vector<T>(W2,0));
		for(LL i = 0;i < H;++i) for (LL k = 0;k < H;++k) for (LL j = 0;j < W2;++j)
			ret[i][j] ^= (mat[i][k] & m.mat[k][j]);
		mat = ret;
	}

	Matrix t(void) { //転置
		Matrix ret(W,H);
		for (LL i = 0;i < H;i++) for(LL j = 0;j < W;j++)
			ret[j][i] = mat[i][j];
		return ret;
	}

	double det(void){ // 行列式
		if (!lu_fi) this->LU();
		double ret = 1.0;
		for (LL i = 0;i < H;++i) ret *= (L[i][i]*U[i][i]);
		return ret;
	}

	pair<Matrix<double>,Matrix<double>> LU(void) { //LU分解
		if (H != W) abort();
		lu_fi = true;
		vector<vector<double>> sp(H,vector<double>(H));
		L = vector<vector<double>>(H,vector<double>(H));
		U = vector<vector<double>>(H,vector<double>(H));
		for(LL i = 0;i < H;++i) for(LL j = 0;j < H;++j) sp[i][j] = (double)mat[i][j];
		for(LL k = 0;k < H;++k) {
			for(LL i = k;i < H; ++i) L[i][k] = sp[i][k];
			double div = sp[k][k];
			for(LL i = k;i < W; ++i) U[k][i] = (sp[k][i]/div);
			for(LL i = (k+1);i < H;++i) for(LL j = (k+1); j < W;++j) sp[i][j] -= (L[i][k]*U[k][j]);
		}
		return pair<Matrix<double>,Matrix<double>>(L,U);
	}

	Matrix<double> inv(void) { // 逆行列
		if (H != W) abort();
		Matrix e(H,H,1);
		Matrix<double> x(H,H);
		vector<vector<double>> sp(H,vector<double>(H)),y(H,vector<double>(H));
		if (!lu_fi) this->LU();
		for(LL w = 0;w < H;++w) {
			for(LL h = 0;h < H;++h) {
				y[h][w] = e[h][w];
				for(LL k = 0;k < h;++k) {
					y[h][w] -= (y[k][w]*L[h][k]);
				}
				y[h][w] /= L[h][h];
			}
		}
		for(LL w = 0;w < H;++w) {
			for(LL h = (H-1);h >= 0;h--) {
				x[h][w] = y[h][w];
				for(LL k = (h+1);k < H;++k) x[h][w] -= (x[k][w]*U[h][k]);		
			}
		}
		return x;
	}
};

#define dump(x)  cerr << #x << " => " << (x) << endl;
#define dumpMatrix(matrix,h,w) REP(i,h) REP(j,w) cout << #matrix << "[" << (i) << "]" << "[" << (j) << "] ==> " << (matrix[i][j]) << endl;

int main(void) { //使い方
	Matrix<int> zero(3,3); //3*3の0行列
	Matrix<int> e(3,3,1);     //3*3の単位行列

	dump(e[0][0]) 			  //要素参照
	cout << "\n";

	vector<vector<int>> vec = {{1,1,-1},{-2,0,1},{0,2,1}};
	Matrix<int> y(vec);       // vecを行列へ

	Matrix<int> z = e + y;        // 足し算
	dumpMatrix(z,3,3)
	cout << "\n";

	zero -= e;                    // 代入引き算
	dumpMatrix(zero,3,3)
	cout << "\n";

	Matrix<int> yz = (y * z);     // 掛け算
	dumpMatrix(yz,3,3)
	cout << "\n";

	Matrix<int> zn = z.intpow(4); // zの4乗
	dumpMatrix(zn,3,3)
	cout << "\n";

	Matrix<int> b = zero & e;     // bit演算(and)
	dumpMatrix(b,3,3)
	cout << "\n";

	Matrix<int> ring = z.bitProduct(y); // 足し算->xor,掛け算->and にした場合の行列積
	dumpMatrix(ring,3,3)
	cout << "\n";

	Matrix<int> tem = z.t();      //転置
	dumpMatrix(tem,3,3)
	cout << "\n";

	double d = y.det();           //行列式
	dump(d)
	cout << "\n";

	Matrix<double> inverse = y.inv(); //逆行列
	dumpMatrix(inverse,3,3)
	cout << "\n";
}

