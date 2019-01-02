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
#define ALL(x) begin(x), end(x)

using namespace std;

const char cmd[4] = { 'U', 'D', 'R', 'L' };
const short dy[4] = { -1, 1, 0, 0 };
const short dx[4] = { 0, 0, 1, -1 };
constexpr short n = 100;
constexpr short h = 50;
constexpr short w = 50;
constexpr short t = 2500;
constexpr short m = 8; // 一度に選ぶ座標数。
constexpr short beam = 16;

typedef struct state {
	short x,y;
	bitset<h * w> visited;
} state;

typedef struct beam_state {
	state state_t[m];
	long score_t;
	string cmds;
} beam_state;

struct Order {
	bool operator() (beam_state const& a,beam_state const& b){
		return a.score_t > b.score_t;
	}
};

char fs[n][h][w];
pair<short,short> start_all[n];

bool is_trap(short index,short x,short y){
	return (fs[index][x][y] == 'x');
}
//typedef priority_queue<beam_state,vector<beam_state>,Order> pq;

bool is_on_field(short x,short y){
	return (0 <= y and y < h and 0 <= x and x < w);
}

void dump_state(beam_state test){
	REP(i,m){
		state* e = &test.state_t[i];
		dump(e->x);
		dump(e->y);
	}
	dump(test.score_t);
	dump(test.cmds);
	cout << endl;
}

beam_state generate_route(vector<short> selected){
	//初期化
	beam_state init;

	REP(i,m){
		state* e = &init.state_t[i];
		e->x = start_all[selected[i]].first;
		e->y = start_all[selected[i]].second;
		e->visited = bitset<h*w>(0);
	}

	init.score_t = 0;
	init.cmds = "";

	//キューの宣言。
	queue<beam_state> que;
	que.push(init);

	REP(iter,t){ // コマンドの個数
		vector<beam_state> Next;
		long l = que.size();
		REP(i,l){ // キューの中身の数。
			beam_state cur = que.front(); 
			que.pop();
			//dump_state(cur);
			REP(j,4){	// 進み方4通り。
				bool invalid_move = false;
				short new_x[m];
				short new_y[m];

				REP(s,m){
					state* e = &cur.state_t[s];
					new_x[s] = e->x + dx[j];
					new_y[s] = e->y + dy[j];

					if (!(is_on_field(new_x[s],new_y[s]))) {
						new_x[s] -= dx[j]; 
						new_y[s] -= dy[j];
					}

					else if (is_trap(selected[s],new_x[s],new_y[s])) {
						invalid_move = true;
						break;
					}
				}

				if (invalid_move) continue;	// もし、行った先がトラップならその操作は取らない。
				// 次状態へ
				beam_state next_s = cur;
				REP(s,m){
					state* c = &next_s.state_t[s];

					c->x = new_x[s];
					c->y = new_y[s];

					if (fs[s][c->x][c->y] == 'o' && !(c->visited[h*new_x[s]+new_y[s]])){
						next_s.score_t ++;			
					}
					c->visited.set(h*new_x[s]+new_y[s]);
				}
				
				next_s.cmds += cmd[j];
				Next.push_back(next_s);
			}
		}
		sort(Next.begin(),Next.end(),Order());
		REP(i,min((short)Next.size(),bxeam)){
			que.push(Next[i]);
		}
	}
	return que.front();
}

int main(void){
	 chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now(); //timer start
	{ string s; getline(cin, s); }	//捨てる。
	default_random_engine gen;

	REP(i,n) {
		REP(j,h) {
			REP(l,w){
				cin >> fs[i][j][l];
				if (fs[i][j][l] == '@') start_all[i] = pair<short,short> (j,l);
			}
		}
	}

	long high_score = (-1);
	vector<short> high_select; 
	string high_cmd;

	while (1){
		chrono::high_resolution_clock::time_point clock_end = chrono::high_resolution_clock::now();
		if (chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count() >= 3000) break; 
		vector<short> selected;
        while (selected.size() < m) {
            int j = uniform_int_distribution<int>(0, n - 1)(gen); // 0 ~ (n-1)以下でランダム整数、どのマップを探索するか
            if (not count(ALL(selected), j)) { // selectedの中にjの値がない。
                    selected.push_back(j);
            }
        }
        //dump1d_arr(selected);
        beam_state result = generate_route(selected);

        //dump(result.score_t);
        //dump(result.cmds.size());

        if (result.score_t > high_score){
        	high_score = result.score_t;
        	high_cmd = result.cmds;
        	high_select = selected;
        }
	}

	REP(i,m) cout << high_select[i] << " ";
	cout << endl;

	cout << high_cmd << endl;
}

