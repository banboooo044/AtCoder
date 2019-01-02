// 三分探索 & 二分探索解法
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
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
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef boost::multiprecision::cpp_dec_float_100 dd;
typedef boost::multiprecision::cpp_int ii;

int main(void) {
	short Q;
	LL A,B,tmp,x;
	dd l3,r3,q1,q2,range;
	ii mul,l2,r2,X;
	cin >> Q;
	VI ans(Q);
	REP(i,Q){
		cin >> A >> B;
		if (A > B) {
			tmp = A;
			A = B;
			B = tmp;
		}
		mul = A*B;
		l2 = (A + 1);
		r2 = mul;
		while (l2 <= r2){
			X = (l2+r2)/2;
			l3 =  (dd)(A+1);
			r3 = (dd)X;
			while ((r3 - l3) > 0.01) {
				q1 = ((l3*2 + r3)/3);
				q2 = ((r3*2 + l3)/3);
				if ((q1 / ((dd)X - q2 + 1.0)) >= (q2 / ((dd)X - q1 + 1.0))) r3 = q2;
				else l3 = q1;
			}
			x = (LL) l3;
			if (((ii)(X - x + 1)*(ii)x) >= mul) r2 = X-1;
			else {
				ans[i] = (LL)X - 1LL;
				l2 = X+1;
			}
		}
	}

	REP(i,Q) cout << ans[i] << endl;
	return 0;
}