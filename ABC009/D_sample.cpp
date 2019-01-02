#include <algorithm>
#include <iostream>
#include <vector>
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define int unsigned
using namespace std;

using vec = vector<int>;
using mat = vector<vec>;

mat mul(mat &a, mat &b) {
  mat c(a.size(), vec(b[0].size()));
  rep(i, a.size()) rep(k, b.size()) rep(j, b[0].size()) c[i][j] ^= a[i][k] & b[k][j];
  return c;
}

mat pow(mat a, int n) {
  mat b(a.size(), vec(a.size()));
  rep(i, a.size()) b[i][i] = ~0;
  while (n) {
    if (n & 1) b = mul(b, a);
    a = mul(a, a);
    n >>= 1;
  }
  return b;
}

signed main() {
  int k, m;
  cin >> k >> m;
  vec a(k), c(k);
  rep(i, k) cin >> a[i];
  rep(i, k) cin >> c[i];
  if (m <= k) {
    cout << a[m - 1] << endl;
    return 0;
  }
  mat v(k, vec(k));
  rep(i, k) v[0][i] = c[i];
  rep(i, k - 1) v[i + 1][i] = ~0;
  mat w = pow(v, m - k);
  unsigned s = 0;
  rep(i, k) s ^= w[0][i] & a[a.size() - 1 - i];
  cout << s << endl;
}
