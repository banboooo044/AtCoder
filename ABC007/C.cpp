#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define dump1d_arr(array,i) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define loINF (long)10000000000
#define shINF (short)10000

using namespace std;

typedef struct {
	int x;
	int y;
	int dis;
} point;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef queue<point> QUE;

int main(void){
	int R,C;
	int ans;
	cin >> R >> C;

	point start,goal;
	cin >> start.y >> start.x >> goal.y >> goal.x;

	start.y -= 1;
	start.x -= 1;
	goal.y -= 1;
	goal.x -= 1;
	start.dis = 0;
	goal.dis = 0;

	point front;

	VVC arr(R,VC(C,0));
	REP(i,R){
		REP(j,C){
			cin >> arr[i][j];
		}
	}

	arr[start.y][start.x] = '#';

	#ifdef DEBUG
		cout << "INPUT CHECK" << endl;
		REP(i,R)
			REP(j,C)
				dump2d_arr(arr,i,j);

		dump(start.x);
		dump(start.y);
		dump(goal.x);
		dump(goal.y);

	#endif //(DEBUG)

	QUE q1;
	q1.push(start); 

	while (1){
		front = q1.front();
		#ifdef DEBUG
			dump(front.x);
			dump(front.y);
			dump(front.dis);
		#endif

		if (front.x != 0){
			if (arr[front.y][front.x-1] == '.') {
				point next = {(front.x)-1,(front.y),(front.dis)+1};
				if ((next.x == goal.x) && (next.y == goal.y)){
					ans = next.dis;
					break;
				}
				arr[next.y][next.x] = '#';
				q1.push(next);
			}
		}

		if (front.x != C-1){
			if (arr[front.y][front.x+1] == '.') {
				point next = {(front.x)+1,(front.y),(front.dis)+1};
				if ((next.x == goal.x) && (next.y == goal.y)){
					ans = next.dis;
					break;
				}
				arr[next.y][next.x] = '#';
				q1.push(next);
			}
		}

		if (front.y != 0){
			if (arr[front.y-1][front.x] == '.') {
				point next = {(front.x),(front.y)-1,(front.dis)+1};
				if ((next.x == goal.x) && (next.y == goal.y)){
					ans = next.dis;
					break;
				}
				arr[next.y][next.x] = '#';
				q1.push(next);
			}
		}

		if (front.y != R-1){
			if (arr[front.y+1][front.x] == '.') {
				point next = {(front.x),(front.y)+1,(front.dis)+1};
				if ((next.x == goal.x) && (next.y == goal.y)){
					ans = next.dis;
					break;
				}
				arr[next.y][next.x] = '#';
				q1.push(next);
			}
		}
		q1.pop();
	}

	cout << ans << endl;
	
	return 0;
}