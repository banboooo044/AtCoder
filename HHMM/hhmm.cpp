#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl
 
constexpr int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
constexpr int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
 
class timer {
    vector<timer> timers;
    int n = 0;
public:
    double limit = 9.9;
    double t = 0;
    timer() {}
    timer(int size) : timers(size) {}
    bool elapses() const {
        return time() - t > limit;
    }
    void measure() {
        t = time() - t;
        ++n;
    }
    void measure(char id) {
        timers[id].measure();
    }
    void print() {
        if (n % 2)
            measure();
        for (int i = 0; i < 128; ++i) {
            if (timers[i].n)
                cerr << (char)i << ' ' << timers[i].t << 's' << endl;
        }
        cerr << "  " << t << 's' << endl;
    }
    static double time() {
    #ifdef LOCAL
        return __rdtsc() / 3.3e9;
    #else
        unsigned long long a, d;
        __asm__ volatile ("rdtsc" : "=a" (a), "=d" (d));
        return (d << 32 | a) / 2.8e9;
#endif
    }
} timer(128);
 
#include <ctime>
class {
    unsigned y = time(0);
    //unsigned y = 2463534242;
public:
    unsigned next() {
        return y ^= (y ^= (y ^= y << 13) >> 17) << 5;
    }
    int next(int b) {
        return next() % b;
    }
    int next(int a, int b) {
        return next(b - a) + a;
    }
    double nextDouble(double b = 1) {
        return b * next() / 4294967296.0;
    }
    double nextDouble(double a, double b) {
        return nextDouble(b - a) + a;
    }
    int operator() (int b) {
        return next(b);
    }
    
} rando;
 
struct P {
    int x, y;
    P() {}
    P(int x, int y) : x(x), y(y) {}
};
 
int V, E, S;
vector<pair<int, int>> edges;
char weight[501][501];
int vs[62][62];
char scores[501];
P ps[500];
P bestPs[500];
 
int eval() {
    int score = 0;
    for (auto& e : edges) {
        auto& a = ps[e.first];
        auto& b = ps[e.second];
        if (max(abs(a.x - b.x), abs(a.y - b.y)) == 1)
            score += weight[e.first][e.second];
    }
    return score;
}
 
void init() {
    vector<int> a;
    for (int i = 0; i < S * S; ++i)
        a.emplace_back(i);
    random_shuffle(a.begin(), a.end(), rando);
    for (int i = 0; i < V; ++i) {
        auto& p = ps[i];
        p.x = a[i] % S + 1;
        p.y = a[i] / S + 1;
        vs[p.y][p.x] = i;
    }
}
 
void solve() {
    init();
    copy_n(ps, V, bestPs);
    int score = eval();
    int bestScore = score;
    for (int i = 0; i < V; ++i) {
        auto& p = ps[i];
        for (int d = 0; d < 8; ++d)
            scores[i] += weight[i][vs[p.y + dy[d]][p.x + dx[d]]];
    }
    double heat = 0;
    for (int iter = -1; ; ) {
        if ((++iter & 0xfff) == 0) {
            //double p = 1 - iter / 100000000.0;
            double p = 1 - (timer.time() - timer.t) / timer.limit;
            if (p < 0) {
                U(iter);
                break;
            }
            constexpr double InitialHeat = 5;
            constexpr double FinalHeat = 1.5;
            heat = 1 / (p * (InitialHeat - FinalHeat) + FinalHeat);
        }
        int i, j, x, y;
        {
            unsigned r = rando.next();
            auto& e = edges[(r >> 4) % edges.size()];
            if (r & 8) {
                i = e.first;
                j = e.second;
            } else {
                j = e.first;
                i = e.second;
            }
            x = ps[j].x + dx[r & 7];
            y = ps[j].y + dy[r & 7];
            j = vs[y][x];
        }
        if (i == j || x == 0 || x == S + 1 || y == 0 || y == S + 1) continue;
        auto& p = ps[i];
        if (j == V) {
            int diff = - scores[i];
            for (int d = 0; d < 8; ++d)
                diff += weight[i][vs[y + dy[d]][x + dx[d]]];
            if (rando.nextDouble() < exp(diff * heat)) {
                score += diff;
                swap(vs[p.y][p.x], vs[y][x]);
                for (int d = 0; d < 8; ++d) {
                    int v = vs[p.y + dy[d]][p.x + dx[d]];
                    scores[v] -= weight[i][v];
                    v = vs[y + dy[d]][x + dx[d]];
                    scores[v] += weight[i][v];
                }
                scores[i] += diff;
                p = { x, y };
                if (bestScore < score) {
                    bestScore = score;
                    copy_n(ps, V, bestPs);
                }
            }
        } else {
            int diff = - scores[i] - scores[j];
            if (max(abs(x - p.x), abs(y - p.y)) == 1)
                diff += weight[i][j];
            vs[p.y][p.x] = vs[y][x] = V;
            for (int d = 0; d < 8; ++d)
                diff += weight[j][vs[p.y + dy[d]][p.x + dx[d]]];
            vs[p.y][p.x] = j;
            for (int d = 0; d < 8; ++d)
                diff += weight[i][vs[y + dy[d]][x + dx[d]]];
            vs[y][x] = i;
            if (rando.nextDouble() < exp(diff * heat)) {
                score += diff;
                for (int d = 0; d < 8; ++d) {
                    int v = vs[p.y + dy[d]][p.x + dx[d]];
                    scores[v] -= weight[i][v] - weight[j][v];
                    v = vs[y + dy[d]][x + dx[d]];
                    scores[v] += weight[i][v] - weight[j][v];
                }
                scores[i] = scores[j] = 0;
                for (int d = 0; d < 8; ++d) {
                    scores[i] += weight[i][vs[y + dy[d]][x + dx[d]]];
                    scores[j] += weight[j][vs[p.y + dy[d]][p.x + dx[d]]];
                }
                swap(p, ps[j]);
                if (bestScore < score) {
                    bestScore = score;
                    copy_n(ps, V, bestPs);
                }
            } else {
                swap(vs[p.y][p.x], vs[y][x]);
            }
        }
    }
    copy_n(bestPs, V, ps);
    timer.print();
}
 
int main() {
    timer.measure();
#ifdef LOCAL
    int type, seed;
    cin >> type >> seed;
#endif
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a;
        --b;
        if (w != 0) {
            edges.emplace_back(a, b);
            weight[a][b] = weight[b][a] = w;
        }
    }
    cin >> S;
    S = (int)sqrt(S);
    {
        int E;
        cin >> E;
        for (int i = 0; i < E; ++i) {
            int a, b;
            cin >> a >> b;
        }
    }
    for (int i = 0; i < S + 2; ++i)
        fill_n(vs[i], S + 2, V);
    solve();
    //cerr << "var d" << type * 6 + seed << " = [" << endl;
    //cerr << "[" << V << ',' << edges.size() << ',' << S << "]," << endl;
    //cerr << "[";
    //for (auto& e : edges)
    //    cerr << e.first << ',' << e.second << ',' << (int)weight[e.first][e.second] << ',';
    //cerr << "]," << endl;
    //cerr << "[";
    //for (int i = 0; i < V; ++i)
    //    cerr << i << ',' << ps[i].x << ',' << ps[i].y << ',';
    //cerr << "]," << endl;
    //cerr << "]" << endl;
#ifdef LOCAL
    int score = 0;
    int esum = 0;
    int wsum = 0;
    for (auto& e : edges) {
        auto& a = ps[e.first];
        auto& b = ps[e.second];
        if (max(abs(a.x - b.x), abs(a.y - b.y)) == 1) {
            score += weight[e.first][e.second];
            ++esum;
        }
        wsum += weight[e.first][e.second];
    }
    cerr << type * 6 + seed << "\t" << score << "\t" << wsum << "\t" << esum << "\t" << edges.size() << "\t" << V << "\t" << S << endl;
#else
    for (int i = 0; i < V; ++i) {
        auto& p = ps[i];
        cout << i + 1 << ' ' << (p.y - 1) * S + p.x << endl;
    }
#endif
    return 0;
}
