#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define dumpArray(array,i,j) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(void){
	/*input*/
	string s;
	short x,y;
	cin >> s;
	cin >> x >> y;

	#ifdef DEBUG
		cout << "DEBUG INPUT PRINT\n";
		dump(s);
		dump(x);
		dump(y);
	#endif //DEBUG

	/*input end*/

	/*makeData*/
	VI x_move(1,0),y_move(1,0);
	char mode = 0;
	long sum_x = 0;
	long sum_y = 0;
	long count = 0;

	REP(i,s.size()){
		if (s[i] == 'F') ++count;
		else { 
			if ((s[i] == 'T') && (mode == 0)) {
				x_move.push_back(count);
				sum_x += count;
				count = 0;
				mode = 1;
			}

			else { if ((s[i] == 'T') && (mode == 1)) {
				y_move.push_back(count);
				sum_y += count;
				count = 0;
				mode = 0;
			}}

		}
	}

	if (count != 0){
		if (mode == 0){
			x_move.push_back(count);
			sum_x += count;
		}
		else {
			y_move.push_back(count);
			sum_y += count;
		}
	}

	#ifdef DEBUG
		cout << "DEBUG MOVEARRAY PRINT\n";
		REP(i,x_move.size()) dump(x_move[i]);
		REP(i,y_move.size()) dump(y_move[i]);
	#endif//DEBUG

	/*makeData end*/
	short SX = x_move.size();
	short SY = y_move.size();

	#ifdef DEBUG
	dump(SX);
	dump(SY);
	#endif

	VVI dp_x(SX+1,VI(2*sum_x+1,0));
	VVI dp_y(SY+1,VI(2*sum_y+1,0));

	dp_x[0][sum_x] = 1;
	dp_y[0][sum_y] = 1;

	if (x_move[1] != 0){
		dp_x[2][sum_x + x_move[1]] = 1; 

		FOR(i,2,SX){
			REP(j,2*sum_x+1){
				if (((j + x_move[i]) < (sum_x*2+1)) && ((j - x_move[i]) >= 0))
					dp_x[i+1][j] = ((dp_x[i][j + x_move[i]]) | (dp_x[i][j - x_move[i]]));
				else {
					if ((j + x_move[i]) < (sum_x*2+1))
						dp_x[i+1][j] = (dp_x[i][j + x_move[i]]);

					if ((j - x_move[i]) >= 0)
						dp_x[i+1][j] = (dp_x[i][j - x_move[i]]);
				}
			}
		}
	}

	else {
		REP(i,SX){
			REP(j,2*sum_x+1){
				if (((j + x_move[i]) < (sum_x*2+1)) && ((j - x_move[i]) >= 0))
					dp_x[i+1][j] = ((dp_x[i][j + x_move[i]]) | (dp_x[i][j - x_move[i]]));
				else {
					if ((j + x_move[i]) < (sum_x*2+1))
						dp_x[i+1][j] = (dp_x[i][j + x_move[i]]);

					if ((j - x_move[i]) >= 0)
						dp_x[i+1][j] = (dp_x[i][j - x_move[i]]);
				}
			}
		}
	}

	REP(i,SY){
		REP(j,2*sum_y+1){
			if (((j + y_move[i]) < (sum_y*2+1)) && ((j - y_move[i]) >= 0))
				dp_y[i+1][j] = ((dp_y[i][j + y_move[i]]) | (dp_y[i][j - y_move[i]]));
			else {
				if ((j + y_move[i]) < (sum_y*2+1))
				 	dp_y[i+1][j] = (dp_y[i][j + y_move[i]]);

				if ((j - y_move[i]) >= 0)
					dp_y[i+1][j] = (dp_y[i][j - y_move[i]]);
			}
		}
	}

	#ifdef DEBUG
	REP(i,2*sum_x+1)
		dumpArray(dp_x,SX,i);

	REP(i,2*sum_y+1)
		dumpArray(dp_y,SY,i);
	#endif

	if ((abs(x) > sum_x) || (abs(y) > sum_y))
		cout << "No\n";

	else { if ((dp_x[SX][sum_x + x]) && (dp_y[SY][sum_y + y])) cout << "Yes\n";
		   else { cout << "No\n"; }
	}

	return 0;
}