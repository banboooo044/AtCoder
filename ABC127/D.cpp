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
// LONG_MAX,LLONG_MAX
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class Key,class Value> ostream& operator << (ostream &s, map<Key,Value> M)
{ for ( auto itr = begin(M); itr != end(M); ++itr) { s << itr->first << ":" << itr->second; } return s;}




template <typename MonoidType, typename OperatorType>
struct LazySegmentTree {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;

    // node, lazy, update flag (for lazy), identity element
    int n;
    vector<MonoidType> node;
    vector<OperatorType> lazy;
    vector<bool> need_update;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    OOtoO upd_f;
    MMtoM cmb_f;
    MOtoM lzy_f;
    OItoO acc_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        lazy = vector<OperatorType>(2*n-1, E1);
        need_update = vector<bool>(2*n-1, false);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    // initialize
    LazySegmentTree() {}
    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,
                    OOtoO upd_f_, MMtoM cmb_f_, MOtoM lzy_f_, OItoO acc_f_,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), E1(E1_),
        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        build(n_, v);
    }

    void eval(int k, int l, int r) {
        if(!need_update[k]) return;
        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));
        if(r - l > 1) {
            lazy[2*k+1] = lzy_f(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);
            need_update[2*k+1] = need_update[2*k+2] = true;
        }
        lazy[k] = E1;
        need_update[k] = false;
    }

    void update(int a, int b, OperatorType x, int l, int r, int k) {
        eval(k, l, r);
        if(b <= l or  r <= a) return;
        if(a <= l and r <= b) {
            lazy[k] = lzy_f(lazy[k], x);
            need_update[k] = true;
            eval(k, l, r);
        }
        else {
            int mid = (l + r) / 2;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    MonoidType query(int a, int b, int l, int r, int k) {
        if(b <= l or  r <= a) return E0;
        eval(k, l, r);
        if(a <= l and r <= b) return node[k];
        int mid = (l + r) / 2;
        MonoidType vl = query(a, b, l, mid, 2*k+1);
        MonoidType vr = query(a, b, mid, r, 2*k+2);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value, x)
    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    // range query for [a, b)
    MonoidType query(int a, int b) {
        return query(a, b, 0, n, 0);
    }

    void dump() {
        fprintf(stderr, "[lazy]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(lazy[i] == E1) fprintf(stderr, "E ");
            else fprintf(stderr, "%d ", lazy[i]);
        }
        fprintf(stderr, "\n");

        fprintf(stderr, "[node]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(node[i] == E0) fprintf(stderr, "E ");
            else fprintf(stderr, "%d ", node[i]);
        }
        fprintf(stderr, "\n");
    }
};


void DSL_2_D() {
    int N, Q; cin >> N >> Q;
    LazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,
                                  [](int a, int b) { return b;         },  // upd
                                  [](int a, int b) { return min(a, b); },  // cmb
                                  [](int a, int b) { return b;         },  // lzy
                                  [](int a, int x) { return a;         }); // acc
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s; cin >> s;
            s -= indexed;
            cout << seg.query(s, s+1) << endl;
        }
        // seg.dump();
    }
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
    int N,M;
    cin >> N>> M;
    LazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,
                                  [](int a, int b) { return b;         },  // upd
                                  [](int a, int b) { return min(a, b); },  // cmb
                                  [](int a, int b) { return b;         },  // lzy
                                  [](int a, int x) { return a;         }); // acc
    vector<int> A(N);
    REP (i,N) { 
        cin >>  A[i];
        seg.update(i, i, A[i]);
    }
    int B,C;
    REP(i,M) {
        cin >> B >> C;
        for (int i = 0;)
    }

}

