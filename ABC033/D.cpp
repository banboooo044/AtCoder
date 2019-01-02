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
#define ALL(c) (c).begin(),(c).end()
#define MIN(vec) *min_element(vec.begin(), vec.end());
#define MAX(vec) *max_element(vec.begin(), vec.end());
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vec) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)

using namespace std;
constexpr double EPS = 1e-9;
constexpr double PI = acos(-1);
typedef vector<long> VI;
typedef vector<VI> VVI;

int main(void) {
  dump(PI)
  long long N;
  long long right = 0,obtuse = 0;
  cin >> N;
  VI x(N),y(N);
  vector<double> rad(2*(N-1));
  REP(i,N) cin >> x[i] >> y[i];
  REP(i,N) {
    short iter = 0;
    REP(j,N) {
      if (i != j) {
        rad[iter++] = atan2(y[j] - y[i],x[j] - x[i]);
        if (rad[iter-1] < 0) rad[iter-1] += 2*(PI);
      }
    }
    sort(rad.begin(),rad.begin()+(N-1));
    REP(j,N-1) rad[j+(N-1)] = rad[j] + (2 * PI);
    REP(j,N-1) {
      auto x = FINDU(rad,(rad[j] + (PI/2.0) - EPS));
      auto y = FINDU(rad,(rad[j] + (PI/2.0) + EPS));
      auto z = FINDU(rad,(rad[j] + PI - EPS));
      right += (y - x);
      obtuse += (z - y);
    }
  }
  long long total = ((N) * (N-1) * (N-2)) / 6LL;
  cout << (total - right - obtuse) << " " << right << " " << obtuse << endl;
  return 0;
}