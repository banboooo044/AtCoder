#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
 
const int inf = 1LL << 55;
const int mod = 1e9 + 7;
 
#define MAX_N 1000
 
int k, n;
double w[MAX_N], p[MAX_N], salt[MAX_N];
 
bool check(double t)
{
  vector<double> c;
  rep(i, n) c.push_back(salt[i] - w[i]*t/100);
  sort(all(c));
  reverse(all(c));
  double sum = 0;
  rep(i, k) sum += c[i];
  return sum >= 0;
}
 
signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
 
  cin >> n >> k;
  rep(i, n) {
    cin >> w[i] >> p[i];
    salt[i] = w[i] * p[i]/100;
  }
  double lb = 0, ub = 100;
  for(int i = 0; i < 100; i++) {
    double mb = (lb + ub) / 2;
    if(check(mb)) lb = mb;
    else ub = mb;
  }
  cout << lb << endl;
 
  return 0;
}