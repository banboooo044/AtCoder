#include <bits/stdc++.h>
using namespace std;
     
int main()
{
    int n; cin>>n;
    vector<vector<int>> a(n);
    for(auto& v: a) {
        vector<int> t(n);
        for(int& e: t) cin>>e;
         v=t;
    }
     
    auto b=a;
        for(int k=0; k<n; ++k)
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j) {
                    if (a[i][j]>a[i][k]+a[k][j]) return cout<<"-1\n", 0;
                    if (j!=k && j!=i && a[k][i]==a[k][j]+a[j][i]) b[k][i]=0;
                }
        long res=0;
        for(auto& v: b) for(auto& e: v) res+=e;
        cout<<res/2<<endl;
    }