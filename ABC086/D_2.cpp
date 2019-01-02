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
#define DEBUG

using namespace std;
typedef long long ll;
typedef vector<long> VI;
typedef vector<VI> VVI;
VVI num;
VVI siz;
ll cal(ll i,ll j,ll w,ll h){//数を返す                                             
        return siz[i+w][j+h]-siz[i+w][j]-siz[i][j+h]+siz[i][j];
}                
int main(){      
        ll n,k; cin>>n>>k;
        //同じ形がずっと続くので一つに重ねておく
        num = VVI(k+10,VI(k+10,0));
        siz = VVI(k+10,VI(k+10,0));
        for(ll i=0;i<n;i++){
                int x,y; char c;
                cin>>x>>y>>c;
                y%=2*k;//yの位置を変更する
                if(c=='W'){//もしも白なら
                        x+=k;//k追加して黒のところにしておく
                }
                if(y>=k){//yがkより大きいなら
                        //位置を横に変える
                        y-=k;
                        x+=k;
                }
                x%=2*k;
                //重ねた位置を追加する
                num[x][y]++;
        }        
        //数え上げる
        siz[1][1]=num[0][0];
        //累積和を取る
        for(ll i=1;i<2*k;i++){
                siz[i+1][1]=siz[i][1]+num[i][0];
        }        
        for(ll i=1;i<k;i++){
                siz[1][i+1]=siz[1][i]+num[0][i];
        }        
        for(ll i=1;i<2*k;i++){
                for(ll j=1;j<k;j++){
                        siz[i+1][j+1]=num[i][j]+siz[i][j+1]+siz[i+1][j]-siz[i][j];
                }
        }        

        dump2d_arr(siz);
                 
        ll ans=0;
        //数え上げる
        for(ll i=0;i<k;i++){
                for(ll j=0;j<k;j++){
                        ll tmp=cal(i,j,k,k-j);
                        tmp+=cal(0,0,i,j);
                        tmp+=cal(i+k,0,k-i,j);
                        if(tmp<(n/2)){
                                tmp=n-tmp;
                        }
                        else{
                                tmp=tmp;
                        }
                        //tmp= tmp<n/2 ? n-tmp :tmp ;
                        ans=max(ans,tmp);
                }
        }        
        cout<<ans<<endl;
}   