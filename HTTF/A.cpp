// 9333209492点解法
#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,n) REP(j,n) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define llINF (long long) 9223372036854775807
#define loINF (long) 2147483647
#define shINF (short) 32767
#define SORT(c) sort((c).begin(),(c).end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end());
using namespace std;

typedef struct point {
	long X,Y,H;
}point;

struct Order {
	bool operator() (point const& a,point const& b){
		return a.H > b.H;
	}
};

typedef pair<long,long> pr;
constexpr short n = 100;
long A[n][n];
vector<long> x;
vector<long> y;
vector<point> ans;

void dump_point(point p){
	dump(p.X);
	dump(p.Y);
	dump(p.H);
}

void search_candidate(void){
	x = vector<long>(0);
	y = vector<long>(0);
	bool upx = true,upy = true;
	long prev_x = loINF,prev_y = loINF;
	REP(i,n){
		REP(j,n-1){
			if (A[i][j] < A[i][j+1] && (!upx)) upx =  true;
			else if (A[i][j] == A[i][j+1] && prev_x == loINF && upx) prev_x = j;
			else if (A[i][j] > A[i][j+1] && upx){
				upx = false;
				if (prev_x == loINF) x.push_back(j);
				else {
					FOR(k,prev_x,j+1) x.push_back(k);
				}
				prev_y = loINF;
			}

			if (A[j][i] < A[j+1][i] && (!upy)) upy =  true;
			else if (A[j][i] == A[j+1][i] && prev_y == loINF && upy) prev_y = j;

			else if (A[j][i] > A[j+1][i] && upy){
				upy = false;
				if (prev_y == loINF) y.push_back(j);
				else {
					FOR(k,prev_y,j+1) y.push_back(k);
				}
				prev_y = loINF;
			}
		}
		if (upx) {
			if (prev_x == loINF) x.push_back(n-1);
			else FOR(k,prev_x,n) x.push_back(k);
		}

		if (upy) {
			if (prev_y == loINF) y.push_back(n-1);
			else FOR(k,prev_y,n) y.push_back(k);
		}
	}

	SORT(x);
	UNIQ(x);
	SORT(y);
	UNIQ(y);

	#ifdef DEBUG
		dump1d_arr(x);
		dump1d_arr(y);
	#endif
}
bool get_ans(void){
	deque<point> center;
	REP(i,x.size()){
		REP(j,y.size()){
			if (A[y[j]][x[i]] <= 0) continue;
			center.push_back(point {x[i],y[j],A[y[j]][x[i]]});
		}
	}

	if (center.empty()) return true;

	sort(center.begin(),center.end(),Order());

	while (!center.empty()) {
		point* cur = &center.front();
		long hh = min((cur->H),(long)n);
		ans.push_back(point {cur->X,cur->Y,hh});
		long del = 0;
		REP(i,center.size()){
			point* node = &center[i];
			node->H -= max((hh - abs(cur->X - node->X) - abs(cur->Y - node->Y)),0L);
			if (node->H <= 0) del++;
		}
		if (!center.empty()) sort(center.begin(),center.end(),Order());
		REP(i,del) center.pop_back();
	}

	return false;
}

void next_arr(long iter){
	long score;
	FOR(i,iter,ans.size()){
		score = 0;
		point* cur = &ans[i];
		FOR(h,1,(cur->H)+1){
			REP(x,h+1){
				if (x == 0){
					if (cur->Y - h >= 0) A[cur->Y - h][cur->X] -= ((cur->H)-h);
					if (cur->Y + h <= (n-1)) A[cur->Y + h][cur->X] -= ((cur->H)-h);
					continue;
				}

				if (cur->X - (x) >= 0 ){
					if ((h-x) == 0) A[cur->Y][cur->X - (x)] -= ((cur->H)-h);
					else {
						if (cur->Y - (h-x) >= 0) A[cur->Y - (h-x)][cur->X - (x)] -= ((cur->H)-h);
						if (cur->Y + (h-x) <= (n-1)) A[cur->Y + (h-x)][cur->X - (x)] -= ((cur->H)-h);
					}
				}

				if (cur->X + (x) <= (n-1)){
					if ((h-x) == 0) A[cur->Y][cur->X + (x)] -= ((cur->H)-h);
					else {
						if (cur->Y - (h-x) >= 0) A[cur->Y - (h-x)][cur->X + (x)] -= ((cur->H)-h);
						if (cur->Y + (h-x) <= (n-1)) A[cur->Y + (h-x)][cur->X + (x)] -= ((cur->H)-h);
					}
				}
			}
		}
		A[cur->Y][cur->X] -= cur->H;
	}
	//dump2d_arr(A);
}

