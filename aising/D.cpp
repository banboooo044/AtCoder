// 二分探索解法
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h,w,x,y) (0 <= y && y < h && 0 <= x && x < w)
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
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
typedef vector<bool> VB;
typedef vector<pr> VP;
typedef priority_queue<pr,vector<pr>,greater<pr>> pq;
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }



int aokiGetNum(int mid,int x,vector<LL> &A){
    int idx = FINDU(A,2*x-A[mid]);
    if (A[idx-1] == 2*x-A[mid]) return mid - idx + 1;
    else return (mid - idx);
 }

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    vector<LL> A(N);
    REP(i,N) cin >> A[i];
    vector<LL> X(Q);
    REP(i,Q) cin >> X[i];

    vector<LL> accAll(N);
    vector<LL> accOdd = {A[0]};
    vector<LL> accEven = {A[1]};
    accAll[0] = A[0];

    int tk_num = N % 2 == 0 ? N / 2 : N / 2 + 1;
    REP(i,N-1) {
        accAll[i+1] += accAll[i] + A[i+1];
        if (i % 2 == 1 && i < (N-2))
            accEven.push_back(accEven[i/2] + A[i+2]);
        if (i % 2 == 0 && i < (N-2))
            accOdd.push_back(accOdd[i/2] + A[i+2]);
    }
    /*
    cout << accAll << endl;
    cout << accOdd << endl;
    cout << accEven << endl;
    */

    REP(i,Q){
        int ub = N-1;
        int lb = 0;
        while(abs(ub - lb) > 1) {
            int mid = (ub+lb)/2;
            if (aokiGetNum(mid,X[i],A) < (N-mid-1)) 
                lb = mid;
            else ub = mid;
        }

        if ( N - ub >= tk_num ) {
            cout << accAll[N-1] - accAll[N-1-tk_num] << endl;
        }
        else {
            int board = (N-1) - (N - ub)*2; 
            if (board % 2 == 0) {
                cout << (accAll[N-1] - accAll[ub-1] + accOdd[board/2]) << endl;
            }
            else {
                cout << (accAll[N-1] - accAll[ub-1] + accEven[board/2]) << endl;
            }
            
        }
    }
}




