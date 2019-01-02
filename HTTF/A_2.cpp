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
long A[n][n];

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef struct point {
	long X,Y,H;
}point;

vector<point> ans;

long test(long (*arr)[n]){
	long score = 0;
	REP(i,n){
		REP(j,n){
			score += abs(A[i][j] - arr[i][j]);
		}
	}

	return score;
}

void dump_point(point* p){
	dump(p->X);
	dump(p->Y);
	dump(p->H);
}

void get_score (point* cur,long (*arr)[n]){
	vector<short> x_,y_;
	vector<long> h_;
	//dump_point(cur);
	bool flg = false;

	FOR(h,1,(cur->H)+1){
		if (flg) break;
		REP(x,h+1){
			if (x == 0){
				if (cur->Y - h >= 0) {
					if (A[cur->Y - h][cur->X] - (arr[cur->Y - h][cur->X] + ((cur->H)-h)) >= 0) {
						x_.push_back(cur->X);
						y_.push_back(cur->Y - h);
						h_.push_back((cur->H)-h);
					}
					else {
						flg = true;
						break;
					}
				}

				if (cur->Y + h <= (n-1)) {
					if (A[cur->Y + h][cur->X] - (arr[cur->Y + h][cur->X] += ((cur->H)-h)) >= 0){
						x_.push_back(cur->X);
						y_.push_back(cur->Y + h);
						h_.push_back((cur->H)-h);
					}
					else {
						flg = true;
						break;
					}
				}
			}

			else {
				if (cur->X - (x) >= 0 ){
					if ((h-x) == 0) {
						if (A[cur->Y][cur->X - (x)] - (arr[cur->Y][cur->X - (x)] + ((cur->H)-h)) >= 0){
							x_.push_back(cur->X - (x));
							y_.push_back(cur->Y);
							h_.push_back((cur->H)-h);
						}
						else {
							flg = true;
							break;
						}
					}
				}

				else {
					if (cur->Y - (h-x) >= 0) {
						if (A[cur->Y - (h-x)][cur->X - (x)] - (arr[cur->Y - (h-x)][cur->X - (x)] + ((cur->H)-h)) >= 0){
							x_.push_back(cur->X - (x));
							y_.push_back(cur->Y-(h-x));
							h_.push_back((cur->H)-h);
						}
						else {
							flg = true;
							break;
						}
					}


					if (cur->Y + (h-x) <= (n-1)) {
						if (A[cur->Y + (h-x)][cur->X - (x)] - (arr[cur->Y + (h-x)][cur->X - (x)] + ((cur->H)-h)) >= 0){
							x_.push_back(cur->X - (x));
							y_.push_back(cur->Y+(h-x));
							h_.push_back((cur->H)-h);
						}
						else{
							flg = true;
							break;
						}
					}
				}

				if (cur->X + (x) <= (n-1)){
					if ((h-x) == 0) {
						if (A[cur->Y][cur->X + (x)] - (arr[cur->Y][cur->X + (x)] + ((cur->H)-h)) >= 0){
							x_.push_back(cur->X + (x));
							y_.push_back(cur->Y);
							h_.push_back((cur->H)-h);
						}
						else {
							flg = true;
							break;
						}
					}

					else {
						if (cur->Y - (h-x) >= 0) {
							if (A[cur->Y - (h-x)][cur->X + (x)] - (arr[cur->Y - (h-x)][cur->X + (x)] + ((cur->H)-h)) >= 0){
								x_.push_back(cur->X + (x));
								y_.push_back(cur->Y - (h-x));
								h_.push_back((cur->H)-h);
							}
							else {
								flg = true;
								break;
							}
						}

						if (cur->Y + (h-x) <= (n-1)) {
							if (A[cur->Y + (h-x)][cur->X + (x)] - (arr[cur->Y + (h-x)][cur->X + (x)] += ((cur->H)-h)) >= 0){
								x_.push_back(cur->X + (x));
								y_.push_back(cur->Y + (h-x));
								h_.push_back((cur->H)-h);
							}
							else {
								flg = true;
								break;
							}
						}
					}
				}
			}
		}
	}

	if (flg) return;

	x_.push_back(cur->X);
	y_.push_back(cur->Y);
	h_.push_back(cur->H);

	REP(i,x_.size()) arr[y_[i]][x_[i]] += h_[i];
	ans.push_back(point{cur->X,cur->Y,cur->H});

	return;
}


int main(void){
	long a[n][n];
	Fill(a,0);

	default_random_engine gen;
	chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now();
	REP(i,n){
		REP(j,n){
			cin >> A[i][j];
		}
	}
	
	long iter = 0;

	while (1){
		long cx = uniform_int_distribution<int>(0, n - 1)(gen);
		long cy = uniform_int_distribution<int>(0, n - 1)(gen);
		chrono::high_resolution_clock::time_point clock_end = chrono::high_resolution_clock::now();
		if (chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count() >= 5000) break; 
		long ch = min(A[cy][cx] - a[cy][cx],L);
		if (ch <= 0) continue;
		point cur = {cx,cy,ch};
		get_score(&cur,a);
	}
	long l = min((long)ans.size(),1000L);

	cout << l << endl;

	REP(i,l){
		cout << ans[i].X << " " << ans[i].Y << " " << ans[i].H << endl;
	}

	return 0;
}