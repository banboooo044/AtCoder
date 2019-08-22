#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define dump(x)  cerr << #x << " => " << (x) << endl
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
typedef long long LL;
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;

typedef priority_queue<int> pqUp;
typedef priority_queue<int, vector<int>, greater<int> > pqDown;

// LONG_MAX,LLONG_MAX
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class Key,class Value> ostream& operator << (ostream &s, map<Key,Value> M)
{ for ( auto itr = begin(M); itr != end(M); ++itr) { s << itr->first << ":" << itr->second; } return s;}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
    pqUp fi;
    pqDown bc;

    int Q;
    cin >> Q;
    int query;
    int B = 0;
    int L = 0;
    int U = 0;
    REP(i,Q) {
        cin >> query;
        if (query == 1) {
            int a,b;
            cin >> a >> b;
            B += b;
            int m;
            if (fi.empty()) m = __INT_MIN__;
            else m = fi.top();
            int M;
            if (bc.empty()) M = __INT_MAX__;
            else M = bc.top();
            if ( a <= m ) {
                if (fi.size() > bc.size()) {
                    L = L -= 
                    bc.push(fi.top());
                    fi.pop();
                }
                fi.push(a); 
            }
            else {
                if (bc.size() > fi.size()) {
                    fi.push(bc.top());
                    bc.pop();
                }
                fi.push(a);
            }
        }
        else {
            int x;
            if (fi.size() > bc.size()) {
                x = fi.top();
            }
            else if (fi.size() < bc.size()) {
                x = bc.top();
            }
            else {
                x = (fi.top() + bc.top()) / 2;
            }

        }
    }

}

