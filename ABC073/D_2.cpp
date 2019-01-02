#include "bits/stdc++.h"
using namespace std;

long long int inf=1e9+7;

int main(){
	int n,m,R;
	cin>>n>>m>>R;
	vector<int> r(R);
	for(int i=0;i<R;i++)cin>>r[i];
	vector<vector<int> > g(n+1,vector<int>(n+1,inf));
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a;
		b;
		g[a][b]=c;
		g[b][a]=c;
	}
	for(int i=0;i<n+1;i++)g[i][i]=0;
	
	for(int k=1;k<n+1;k++){
		for(int i=1;i<n+1;i++){
			for(int j=1;j<n+1;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	
	int ans=1e9;
	int tmp;
	
	sort(r.begin(),r.end(),greater<int>());
	
	do{
		tmp=0;
		for(int i=0;i<r.size()-1;i++){
			tmp+=g[r[i]][r[i+1]];
		}
		ans=min(ans,tmp);
	}while(prev_permutation(r.begin(),r.end()));
	
	cout<<ans<<endl;
}