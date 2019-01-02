#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <array>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define dump1d_arr(array) REP(i,array.size()) std::cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump(x)  std::cerr << #x << " => " << (x) << std::endl;
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;
typedef std::pair<int, int> P;

int N, x[2123], y[2123];
double PI = acos(-1);
double EPS = 1e-9;
int cho, don, ei;

int main()
{
	in >> N;
	rep(i, N) { in >> x[i] >> y[i]; }

	rep(i, N)
	{
		static double rad[4123];
		int seek = 0;
		rep(j, N)
		{
			if (i == j) { continue; }
			int ry = y[j] - y[i], rx = x[j] - x[i];
			double temp = atan2(ry, rx);
			temp = (temp < 0 ? temp + PI * 2 : temp);
			rad[seek++] = temp;
		}
		dump1d_arr(rad);
		std::sort(rad, rad + seek);
		rep(j, N - 1)
		{
			rad[seek++] = rad[j] + 2 * PI;
		}
		rep(j, N - 1)
		{
			auto x = std::upper_bound(rad, rad + seek, rad[j] + PI / 2 - EPS);
			auto y = std::upper_bound(x, rad + seek, rad[j] + PI / 2 + EPS);
			auto z = std::upper_bound(y, rad + seek, rad[j] + PI - EPS);
			dump(rad[j] + PI / 2)
			dump(x - rad)
			dump(y - rad)
			dump(z - rad)
			cho += (y - x);
			don += (z - y);
			exit(0);
		}
	}
	ei = ((LL)N*(N - 1)*(N - 2) / 6) - (cho + don);

	out << ei << " " << cho << " " << don << std::endl;
	return 0;
} 