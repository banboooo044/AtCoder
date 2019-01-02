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
using namespace std;
typedef pair<long,long> pr;
typedef vector<short> VI;
typedef vector<pr> VP;
typedef vector<VI> VVI;
typedef vector<bool> VB;

bool pairCompare(const pr& firstElof, const pr& secondElof)
{
    return firstElof.first > secondElof.first;
}


int main(void){
	short H,W,D,K;
	cin >> H >> W >> D >> K;
	VP dif(16000);

	VP arr_each(D);
	VVI arr(H,VI(W,(-1)));

	short r,c;
	short prev_r,prev_c;
	cin >> prev_r >> prev_c;
	arr[prev_r][prev_r] = 0;
	arr_each[0] = pr(prev_r,prev_c);
	REP(i,D-1){
		cin >> r >> c;
		dif[i] = pr(abs(prev_r-r) + abs(prev_c-c),i);
		arr[r][c] = i+1;
		arr_each[i+1] = pr(r,c);
		prev_r = r;
		prev_c = c;
	}

	sort(dif.begin(),dif.end(),pairCompare);

	#ifdef DEBUG
		REP(i,dif.size()){
			dump(dif[i].first);
			dump(dif[i].second);
		}
	#endif

	REP(i,K){
		short x = arr_each[dif[i].second].first;
		short y = arr_each[dif[i].second].second;
		
		if (x == (H-1)) x -= 1;
		else if (x == 0) x += 1;
		else if (y == (W-1)) y -= 1;
		else if (y == 0) y += 1;
		else x++,y++;

		cout << arr_each[dif[i].second+1].first << " " << arr_each[dif[i].second+1].second << " " << x << " " << y << endl;

		if (arr[x][y] != (-1)){
			arr_each[arr[x][y]] = arr_each[dif[i].second+1];
			arr[arr_each[arr[x][y]].first][arr_each[arr[x][y]].second] = dif[i].second+1;
			arr_each[dif[i].second+1] = pr(x,y);
			arr[x][y] = dif[i].second+1;
		}
		else {
			arr_each[dif[i].second+1] = pr(x,y);
			arr[x][y] = dif[i].second+1;
		}
	}
	return 0;
}