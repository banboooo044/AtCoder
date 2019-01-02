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
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
#define IN(n,m)  (!(m.find(n) == m.end()))
#define TO_INT(vec,s) REP(i,s.length()){vec.push_back(s[i] - ‘0’);}
#define ENUM_v(vec) for (auto e : vec)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())

using namespace std;
typedef vector<long long> VI;
typedef vector<VI> VVI;
typedef map<long,long> mp;

int main(void){
	short Q;
	long a,b,minv,maxv,l,r,mid,prev,m;
	long long ans;
	long long mul;
	bool flg;
	cin >> Q;
	VI A(Q);
	REP(i,Q){
		cin >> a >> b;
		mul = a * b;
		minv = min(a,b);
		maxv = max(a,b);
		ans = 0;
		flg = true;
		m = (-1);
		l = 0;
		r = (maxv-1);
		while (l < r) {
			mid = (l+r)/2;
			if ((mul/mid) > minv) l = mid + 1;
			else r = mid - 1;
		}
		prev = mul / (r+1);
		RFOR(j,r,0){
			long div = mul / j;
			if (div * j == mul) div --;
			if (div > minv && (j == 1 || (mul/(j-1))-div > 1)) {
				if (flg) {
					flg = false;
					m = j;
				}
				if (div == prev) ans += (j-1);
				else ans += j;
				break;
			}
			else if (div > minv && prev != div) {
				if (flg) {
					flg = false;
					m = j;
				}
				ans++;
				prev = div;
			}		
		}
		if (m == (-1)) m = maxv;
		l = 0;
		r = (maxv-1);
		while (l < r){
			mid = (l+r)/2;
			if ((mul/mid) > m) l = mid + 1;
			else r = mid - 1;
		}
		prev = mul / (r+1);
		RFOR(j,r,0) {
			if (j == minv) continue;
			long div = mul / j;
			if (div * j == mul) div --;
			if (div > m && (j == 1 || (mul/(j-1))-div > 2)) {
				if (div == prev) ans += (j-1);
				else ans += j;
				if (m < maxv && div < maxv) ans--;
				break;
			}
			else if (div > m && div != maxv && prev != div) {
				ans++;
				prev = div;
			}
		}
		A[i] = ans;
	}
	REP(i,Q) cout << A[i] << endl;
	return 0;
}