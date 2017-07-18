#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=110;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1000000007;
 
int n,m,t,a,b,q,x[110],y[110],z[20];
 
int main(){
	scanf("%d",&t);	 z[0]=1; x[0]=0;
	for(int i=1;i<=20;i++)
		z[i]=z[i-1]*2;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		memset(y,0,sizeof(y));
		int ans=0;
		for(int i=1;i<=n;i++){
			int temp=0;
			for(int j=1;j<=20;j++)
				if (x[i]%z[j]==0) temp=j;
			for(int j=0;j<i;j++)
				if (x[j]<x[i]) y[i]=max(y[i],y[j]+temp);
			ans=max(ans,y[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}