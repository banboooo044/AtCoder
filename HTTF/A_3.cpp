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
constexpr short n = 100;
constexpr short dx[4] = {1,0,-1,0};
constexpr short dy[4] = {0,1,0,-1};
typedef struct point {
	long X,Y,H;
}point;

void dump_point(point* p){
	dump(p->X);
	dump(p->Y);
	dump(p->H);
}

char put_ok(long (&a)[n][n],long pile,point &cent){
	REP(i,n) {
		REP(j,n) {
			if ( a[i][j] < (pile - (abs(cent.X - j) + abs(cent.Y - i)))) return 0;
		}
	}
	return 1;
}

long dump_score(long (&a)[n][n]){
	long score = 0;
	REP(i,n){
		REP(j,n){
			score += abs(a[i][j] - 0);
		}	
	}
	return (200000000 - score);
}

long move_center(long (&a)[n][n],point &cent,short delx,short dely,bool overWrite){
	point after = {cent.X+delx,cent.Y+dely,cent.H};
	if (after.X < 0 || after.X > (n-1) || after.Y < 0 || after.Y > (n-1)) return loINF;
	long p = 0;
	
	REP(y,n){
		REP(x,n){
			if (delx == 0 && dely == 1){
				if ((cent.H - abs(cent.X - x) - abs(cent.Y - y)) > 0 && cent.Y >= y){
					if (overWrite) a[y][x] += 1;
					else p += (abs(a[y][x] + 1) - abs(a[y][x]));
				}
				else if ((cent.H - abs(after.X - x) - abs(after.Y - y)) > 0 && cent.Y < y){
					if (overWrite) a[y][x] -= 1;
					else p += (abs(a[y][x] - 1) - abs(a[y][x]));
				}		
			}
 
			else if (delx == 0 && dely == (-1)){
				if ((cent.H - abs(after.X - x) - abs(after.Y - y)) > 0 && cent.Y > y){
					if (overWrite) a[y][x] -= 1;
					else p += (abs(a[y][x] - 1) - abs(a[y][x]));	
				}
				else if ((cent.H - abs(cent.X - x) - abs(cent.Y - y)) > 0 && cent.Y <= y){
					if (overWrite) a[y][x] += 1;
					else p += (abs(a[y][x] + 1) - abs(a[y][x]));					
				}
			}
 
			else if(delx == 1 && dely == 0){
				if ((cent.H - abs(cent.X - x) - abs(cent.Y - y)) > 0 && cent.X >= x){
					if (overWrite) a[y][x] += 1;
					else p += (abs(a[y][x] + 1) - abs(a[y][x]));				
				}
				else if ((cent.H - abs(after.X - x) - abs(after.Y - y)) > 0 && cent.X < x){
					if (overWrite) a[y][x] -= 1;
					else p += (abs(a[y][x] - 1) - abs(a[y][x]));				
				}
			}
 
			else if (delx == (-1) && dely == 0){
				if ((cent.H - abs(after.X - x) - abs(after.Y - y)) > 0 && cent.X > x){
					if (overWrite) a[y][x] -= 1;
					else p += (abs(a[y][x] - 1) - abs(a[y][x]));	
				}
				else if ((cent.H - abs(cent.X - x) - abs(cent.Y - y)) > 0 && cent.X <= x){
					if (overWrite) a[y][x] += 1;
					else p += (abs(a[y][x] + 1) - abs(a[y][x]));			
				}
			}
		}
	}
	return p;	
}

short change_height(long (&a)[n][n],point &cent) {
	long p = 0;
	long q = 0;
	long h = cent.H;

	if (h > 1) { // 高さを下げる
		REP(i,h+1){
			REP(j,i+1){
				if ((cent.Y + j < n) && ((cent.X + i - j) < n)) p += (abs(a[(cent.Y + j)][(cent.X + i - j)] + 1) - abs(a[(cent.Y + j)][(cent.X + i - j)]));
				if ((j != 0) && (cent.Y - j >= 0) && ((cent.X + i - j) < n)) p += (abs(a[(cent.Y - j)][(cent.X + i - j)] + 1) - abs(a[(cent.Y - j)][(cent.X + i - j)]));
				if ((i - j != 0) && (cent.Y + j < n) && ((cent.X + j - i) >= 0)) p += (abs(a[(cent.Y + j)][(cent.X + j - i)] + 1) - abs(a[(cent.Y + j)][(cent.X + j - i)]));
				if ((j != 0) && (i - j != 0) && (cent.Y - j >= 0) && ((cent.X + j - i) >= 0)) p += (abs(a[(cent.Y - j)][(cent.X + j - i)] + 1) - abs(a[(cent.Y - j)][(cent.X + j - i)]));
			}
		}
	}

	if (h != 100){ // 高さを上げる
		REP(i,h+2){
			REP(j,i+1){
				if (cent.Y + j < n && (cent.X + i - j) < n) q += (abs(a[cent.Y + j][cent.X + i - j] - 1) - abs(a[cent.Y + j][cent.X + i - j]));
				if ((j != 0) && (cent.Y - j >= 0) && ((cent.X + i - j) < n)) q += (abs(a[cent.Y - j][cent.X + i - j] - 1) - abs(a[cent.Y - j][cent.X + i - j]));
				if ((i - j != 0) && (cent.Y + j < n) && ((cent.X + j - i) >= 0)) q += (abs(a[cent.Y + j][cent.X + j - i] - 1) - abs(a[cent.Y + j][cent.X + j - i]));
				if ((j != 0) && (i - j != 0) && (cent.Y - j >= 0) && ((cent.X + j - i) >= 0)) q += (abs(a[(cent.Y - j)][(cent.X + j - i)] - 1) - abs(a[(cent.Y - j)][(cent.X + j - i)]));
			}
		}
	}

	if (p == 0 && q == 0) return 0;
	else if (p > q && q < 0) {	
		REP(i,h+2){
			REP(j,i+1){
				if ((cent.Y + j < n) && ((cent.X + i - j) < n)) a[cent.Y + j][(cent.X + i - j)] -= 1;
				if (j != 0 && (cent.Y - j >= 0) && ((cent.X + i - j) < n)) a[cent.Y - j][(cent.X + i - j)] -= 1;
				if (i - j != 0 && (cent.Y + j < n) && ((cent.X + j - i) >= 0)) a[cent.Y + j][(cent.X + j - i)] -= 1;
				if (j != 0 && i - j != 0 && (cent.Y - j >= 0) && ((cent.X + j - i) >= 0)) a[cent.Y - j][(cent.X + j - i)] -= 1;
			}
		}
		return 1;
	}
	else if (q >= p && p < 0) {
		REP(i,h+1){
			REP(j,i+1){
				if ((cent.Y + j < n) && ((cent.X + i - j) < n)) a[cent.Y + j][cent.X + i - j] += 1;
				if (j != 0 && (cent.Y - j >= 0) && (cent.X + i - j) < n) a[cent.Y - j][cent.X + i - j] += 1;
				if (i - j != 0 && (cent.Y + j < n) && ((cent.X + j - i) >= 0)) a[cent.Y + j][cent.X + j - i] += 1;
				if (j != 0 && i - j != 0 && (cent.Y - j >= 0) && ((cent.X + j - i) >= 0)) a[cent.Y - j][cent.X + j - i] += 1;
			}
		}
		return (-1);
	}
	else return 0;
}

int main(void){
	default_random_engine gen;
	chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now();
	long A[n][n];
	vector<point> ans;
	long cnt = 0;
	//chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now();
	REP(i,n){
		REP(j,n){
			cin >> A[i][j];
		}
	}
	while (cnt++ < 1000) {
		long max_pile = 0;
		point center;
		// 最大積数
		REP(i,n){
			REP(j,n){
				if (max_pile < A[i][j]) {
					max_pile = A[i][j];
					center = point {j,i,0};
				}
			}
		}
		long l = 0;
		long r = max_pile;
		while (l < r) {
			long mid = (l + r) / 2;
			if (! put_ok(A,mid,center)) r = mid - 1;
			else l = mid + 1;
		}
		center.H = min(l,100L);
		REP(i,n) {
			REP(j,n) {
				A[i][j] -= max((center.H - (abs(center.X - j) + abs(center.Y - i))),0L);
			}
		}
		ans.push_back(center);
	}
	long m = ans.size();
	long p,P;
	long total = 0;
	long accept = 0;
	double probability;
	double startTemp = 100.0;
	double endTemp = 10.0; 
	double T = 5900; 
	while (1){
		chrono::high_resolution_clock::time_point clock_end = chrono::high_resolution_clock::now();
		auto t = chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count();
		if (t >= T) break;
		short i = uniform_int_distribution<short>(0, m - 1)(gen); // 0 ~ (n-1)以下でランダム整数、どのマップを探索するか
		P = loINF;
		short index = (-1);
		REP(xy,4){
			p = move_center(A,ans[i],dx[xy],dy[xy],false);
			if (P > p) {
				P = p;
				index = xy;
			}
		}
		
		if (P < 0) {
			move_center(A,ans[i],dx[index],dy[index],true);
			ans[i].X += dx[index];
			ans[i].Y += dy[index];
		}

		else {
			double temp = startTemp + ((endTemp - startTemp) * t / T);
			probability = exp((double)(-P)/temp);
			double pr = uniform_real_distribution<double>( 0.0, 1.0 )(gen);
			if (probability > pr) {
				move_center(A,ans[i],dx[index],dy[index],true);
				ans[i].X += dx[index];
				ans[i].Y += dy[index];
			}
		}
		//dump(dump_score(A));
	}
	/*
	while (1){
		chrono::high_resolution_clock::time_point clock_end = chrono::high_resolution_clock::now();
		if (chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count() >= 5900) break;
		short i = uniform_int_distribution<short>(0, m - 1)(gen); // 0 ~ (n-1)以下でランダム整数、どのマップを探索するか
		//ヒルクライム2
		ans[i].H += change_height(A,ans[i]);
		//dump(dump_score(A));
	}
	*/
	// 出力
	cout << m << endl;
	REP(i,ans.size()){
		cout << ans[i].X << " " << ans[i].Y << " " << ans[i].H << endl;
	}

	return 0;
}