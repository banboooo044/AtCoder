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
typedef struct _PT {
  double x, y;
  long ind;
  _PT() {}
  _PT(double x, double y,long index) : x(x), y(y) ,ind(index) {} 
  _PT operator + (_PT p){
	   return _PT(x + p.x, y + p.y,-1);
  }
  _PT operator - (_PT p){
	   return _PT(x - p.x, y - p.y,-1);
  }
  _PT operator * (double d){
	   return _PT(d*x, d*y,-1);
  }

  double norm(void){
  	return sqrt(x*x + y*y);
  }

  double twice_norm(void){
  	return x*x + y*y;
  }

  double dot(_PT p){ //pとの内積
	   return x * p.x + y * p.y;
  }
  double det(_PT p){ // (x,p)の行列式
	   return x * p.y - p.x * y;
  }
  double dist(_PT p){ //pとの距離の2乗
	   return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
  }
  bool operator <(const struct _PT &e) const{
     return x == e.x? (y < e.y) : x < e.x;
  }
  bool operator >(const struct _PT &e) const{
     return x == e.x? (y > e.y) : x > e.x;
  }
} pt;


bool cmp_x(const pt &p1,const pt &p2){
	if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
}


class Polygon{
  private:
    vector<pt> pts;
    size_t n;
  public:
    Polygon() : n(0) {}
    Polygon(vector<pt> v) : n(v.size()) {
      pts = v;
    }

    void addPoint(pt P){
      pts.push_back(P);
    }

    vector<pt> convexHull(void){
      vector<pt> qs(n * 2);
      sort(pts.begin(),pts.end(),cmp_x);
      long k = 0;

      REP(i,n){ //下側凸包の作成
        while(k > 1 && (qs[k-1] - qs[k-2]).det(pts[i] - qs[k-1]) <= 0) k--;
        qs[k++] = pts[i];
      }

      for(long i = n - 2, t = k; i >= 0; i--){ //上側凸包の作成
        while(k > t && (qs[k-1] - qs[k-2]).det(pts[i] - qs[k-1]) <= 0) k--;
        qs[k++] = pts[i];
      }

      qs.resize(k-1);
      n = k-1;
      pts = qs;
      return qs;
    }

  //点が図形を構成する順番に並んでないと駄目。並んでなければconvexHullで矯正してから
    double getArea(void){
      double s = 0;
      REP(i,n-1) s += pts[i].det(pts[i+1]);
      s += pts[n-1].det(pts[0]);
      return fabs(s) * 0.5;
    }
};

int main(void){
	short N;
	double x,y;
	cin >> N;

	vector<pt> point,convex;
	REP(i,N) {
		cin >> x >> y;
		point.push_back(pt(x,y,i));
	}

	if (N == 2) {
		cout << 0.5 << "\n" << 0.5 << endl;
		exit(0);
	}

	Polygon P(point);
	convex = P.convexHull();
	vector<double> ans(N,0.0);

	long m = convex.size();
	double alpha;
	REP(i,m-2){
		pt v1 = convex[i]-convex[i+1],v2 = convex[i+2]-convex[i+1];
		alpha = acos((v1).dot(v2) / sqrt(v1.twice_norm() * v2.twice_norm()));
		ans[convex[i+1].ind] = (M_PI - alpha)/ (2 * M_PI);
	}
	pt v1 = convex[m-2] - convex[m-1],v2 = convex[0] - convex[m-1];
	alpha = acos((v1).dot(v2) / sqrt(v1.twice_norm() * v2.twice_norm()));
	ans[convex[m-1].ind] = (M_PI - alpha)/ (2 * M_PI); 
	v1 = convex[m-1] - convex[0],v2 = convex[1] - convex[0];
	alpha = acos((v1).dot(v2) / sqrt(v1.twice_norm() * v2.twice_norm()));
	ans[convex[0].ind] = (M_PI - alpha)/ (2 * M_PI);

	REP(i,N){
		cout << ans[i] << endl;
	}

	return 0;
}