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
typedef vector<short> VI;
typedef vector<VI> VVI;
typedef map<short,VI> mp;

int main(void){
	short N,K,H,W,T;
	char input;

	cin >> N >> K >> H >> W >> T;
	mp flg;
	flg[1] = flg[2] = flg[3] = flg[4] = VI(0);
	REP(k,N) {
		REP(i,25){
			REP(j,25){
				cin >> input;
				if (input == '@') flg[1].push_back(k);
			}
			REP(j,25){
				cin >> input;
				if (input == '@') flg[2].push_back(k);
			}
		}

		REP(i,25){
			REP(j,25){
				cin >> input;
				if (input == '@') flg[3].push_back(k);
			}
			REP(j,25){
				cin >> input;
				if (input == '@') flg[4].push_back(k);
			}
		}
	}

	long flg_max = 1;
	long val = flg[1].size();

	//dump1d_arr(flg[1]);
	FOR(i,2,5){
		//dump1d_arr(flg[i]);
		if (val < flg[i].size()){
			flg_max = i;
			val = flg[i].size();
		}
	}

	long l = flg[flg_max].size() - 1;
	REP(i,K) {
		cout << flg[flg_max][l-i] << " ";
	}
	cout << "\n";

	string ans = "";

	if (flg_max == 2){
		REP(k,25){
			REP(i,12) ans += "LDRD";
			ans += "LL";
			REP(i,12) ans += "ULUR";
			ans += "LL";
		}
	}

	if (flg_max == 1){
		REP(k,25){
			REP(i,12) ans += "RDLD";
			ans += "RR";
			REP(i,12) ans += "URUL";
			ans += "RR";
		}
	}

	if (flg_max == 4){
		REP(k,25){
			REP(i,12) ans += "LURU";
			ans += "LL";
			REP(i,12) ans += "DLDR";
			ans += "LL";
		}
	}

	if (flg_max == 3){
		REP(k,25){
			REP(i,12) ans += "RULU";
			ans += "RR";
			REP(i,12) ans += "DRDL";
			ans += "RR";
		}
	}

	cout << ans << endl;

	return 0;

}