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
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef map<long long,long long> MBIT;


long N;
VVI e;
MBIT memo;

long long dfs(bitset<16> BIT) {
    if (BIT.all()) return 1LL;
    long long num = BIT.to_ullong();
    if (IN(num,memo)) return memo[num];
    long long pattern = 0;
    REP(i,N) {
        if (!BIT[i]){
            bool flg = true;
            REP(j,e[i].size()){
                if (!BIT[e[i][j]]) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                bitset<16> cpBIT = BIT;
                pattern += dfs(cpBIT.set(i));
            }
        }
    }

    return memo[num] = pattern;
}

int main(void){
    long M;
    long x,y;
    cin >> N >> M;
    e = VVI(N,VI(0));
    REP(i,M){
        cin >> x >> y;
        e[x-1].push_back(y-1);
    }
    bitset<16> bit((1<<17)-(1<<(N)));
    cout << dfs(bit) << endl;
}