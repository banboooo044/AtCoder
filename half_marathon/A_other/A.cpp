#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define REP_R(i, n) for (int i = int(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = int(n) - 1; (i) >= int(m); -- (i))
#define ALL(x) begin(x), end(x)
#define dump(x) cerr << #x " = " << x << endl
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T> inline void chmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void chmin(T & a, T const & b) { a = min(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }
template <typename T> ostream & operator << (ostream & out, vector<T> const & xs) { REP (i, int(xs.size()) - 1) out << xs[i] << ' '; if (not xs.empty()) out << xs.back(); return out; }

const char cmd[] = { 'U', 'D', 'R', 'L' };
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

constexpr int n = 100;
constexpr int k = 8;
constexpr int h = 50;
constexpr int w = 50;
constexpr int t = 2500;
bool is_on_field(int y, int x) { return 0 <= y and y < h and 0 <= x and x < w; }

struct state_t {
    bitset<h * w> visited;
    size_t hash_visited;
    int y, x;
    int score;
    int index;
};

inline bool is_trapped(state_t const & a, array<array<char, w>, h> const & f) {
    return f[a.y][a.x] == 'x';
}

bool is_trapped_if_move(int dir, state_t const & a, array<array<char, w>, h> const & f) {
    int ny = a.y + dy[dir];
    int nx = a.x + dx[dir];
    return f[ny][nx] == 'x';
}

void exec_move(int dir, state_t & a, array<array<char, w>, h> const & f) {
    if (is_trapped(a, f)) return;
    int ny = a.y + dy[dir];
    int nx = a.x + dx[dir];
    if (f[ny][nx] != '#') {
        a.y = ny;
        a.x = nx;
        if (f[ny][nx] == 'o' and not a.visited[ny * w + nx]) {
            a.visited[ny * w + nx] = true;
            a.hash_visited = hash<bitset<h * w> >()(a.visited);
            a.score += 1;
        }
    }
}

template <typename T>
struct single_list {
    T value;
    shared_ptr<single_list<T> > next;
};
template <int m>
struct beam_state {
    shared_ptr<array<state_t, m> > state;
    size_t hash_state;
    int score;
    double variance;
    shared_ptr<single_list<int> > cmds;
};

template <int m, class RandomGenerator>
vector<int> generate_tour(array<array<array<char, w>, h>, m> const & f, array<int, m> initial_y, array<int, m> initial_x, RandomGenerator & gen) {
    vector<beam_state<m> > cur, prv; {
        beam_state<m> init = {};
        init.state = make_shared<array<state_t, m> >();
        init.score = 0;
        init.variance = 0.0;
        init.hash_state = -1;
        REP (i, m) {
            (*init.state)[i].visited.reset();
            (*init.state)[i].hash_visited = hash<bitset<h * w> >()((*init.state)[i].visited);
            (*init.state)[i].y = initial_y[i];
            (*init.state)[i].x = initial_x[i];
            (*init.state)[i].score = 0;
        }
        init.cmds = nullptr;
        cur.push_back(init);
    }
    REP (iteration, t) {
        cur.swap(prv);
        cur.clear();
        for (auto a : prv) {
            REP (dir, 4) {
                bool is_trapped = false;
                REP (i, m) {
                    if (is_trapped_if_move(dir, (*a.state)[i], f[i])) {
                        is_trapped = true;
                        break;
                    }
                }s
                if (is_trapped) continue;
                beam_state<m> b = {};
                b.state = make_shared<array<state_t, m> >(*a.state);
                REP (i, m) {
                    exec_move(dir, (*b.state)[i], f[i]);
                    b.score += (*b.state)[i].score;
                    b.hash_state ^= hash<size_t>()((*b.state)[i].hash_visited ^ ((*b.state)[i].y << 16) ^ (*b.state)[i].x);
                }
                b.variance = 0.0;
                REP (i, m) {
                    b.variance += pow((*b.state)[i].score - b.score / (double)m, 2);
                }
                b.variance = sqrt(b.variance) / 100;
                b.cmds = make_shared<single_list<int> >((single_list<int>) { dir, a.cmds });
                cur.emplace_back(b);
            }
        }
        int size = min<int>(100, cur.size());
        partial_sort(cur.begin(), cur.begin() + size, cur.end(), [&](beam_state<m> const & a, beam_state<m> const & b) {
            return a.score - a.variance > b.score - b.variance;
        });
        cur.resize(size);
        sort(ALL(cur), [&](beam_state<m> const & a, beam_state<m> const & b) {
            return a.hash_state < b.hash_state;
        });
        cur.erase(unique(ALL(cur), [&](beam_state<m> const & a, beam_state<m> const & b) {
            return a.hash_state == b.hash_state;
        }), cur.end());
    }
    auto it =c max_element(ALL(cur), [&](beam_state<m> const & a, beam_state<m> const & b) {
        return a.score > b.score;
    })->cmds;
    vector<int> cmds;
    while (it) {
        cmds.push_back(it->value);
        it = it->next;
    }
    reverse(ALL(cmds));
    return cmds;
}

int main() {
    chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now(); //timer start

    // input
    { string s; getline(cin, s); }
    vector<array<array<char, w>, h> > f(n);
    vector<int> start_y(n);
    vector<int> start_x(n);
    REP (i, n) {
        REP (y, h) REP (x, w) {
            cin >> f[i][y][x];
            if (f[i][y][x] == '@') {
                start_y[i] = y;
                start_x[i] = x;
            }
        }
    }

    // solve
    int highscore = -1;
    array<int, k> result_maps;
    string result_commands;
    default_random_engine gen;
    for (int iteration = 0; ; ++ iteration) {
        chrono::high_resolution_clock::time_point clock_end = chrono::high_resolution_clock::now();
        if (chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count() >= 3000) break; 
        // 3秒以上経過してたら終了

        vector<int> dirs; {
            constexpr int m = 8;    // 8つ選ぶ。
            vector<int> selected;
            while (selected.size() < m) {
                int j = uniform_int_distribution<int>(0, n - 1)(gen); // 0 ~ (n-1)以下でランダム整数、どのマップを探索するか
                if (not count(ALL(selected), j)) { // selectedの中にjの値がない。
                    selected.push_back(j);
                }
            }
            array<array<array<char, w>, h>, m> fs;
            array<int, m> start_ys;
            array<int, m> start_xs;
            REP (i, m) {
                fs[i] = f[selected[i]];           
                start_ys[i] = start_y[selected[i]];
                start_xs[i] = start_x[selected[i]];
            }
            dirs = generate_tour<m>(fs, start_ys, start_xs, gen); 
                // fs:map , start_ys,start_xs:与えられた初期位置 , gen:擬似乱数生成エンジン
        }

        vector<state_t> state(n);
        REP (i, n) {
            state[i].visited.reset();
            state[i].index = i;
            state[i].y = start_y[i];
            state[i].x = start_x[i];
            state[i].score = 0;
        }
        string commands;
        for (int dir : dirs) {
            commands += cmd[dir];
            REP (i, n) {
                exec_move(dir, state[i], f[i]);
            }
        }
        sort(ALL(state), [&](state_t const & a, state_t const & b) {
            return a.score > b.score;
        });  1
        int score = 0;
        REP (i, k) {
            score += state[i].score;
        }
        if (highscore < score) {
            highscore = score;
            REP (i, k) {
                result_maps[i] = state[i].index;
            }
            result_commands = commands;
        }
    }

    // output
    REP (i, k) {
        if (i) cout << ' ';
        cout << result_maps[i];
    }
    cout << endl;
    cout << result_commands << endl;
    return 0;
}
