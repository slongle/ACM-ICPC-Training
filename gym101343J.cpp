#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1e4+10;
const int MAXM=1e5;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,t,x[20][200],y[20][20],dp[40000][20],vis[20];
 
void check(int a,int b){
	y[a][b]=0;
	for(int i=x[a][0];i+x[b][0]-1>=x[a][0];i--){
		int tag=1;
		for(int j=1;j+i-1<=x[a][0];j++)
			if (x[a][i+j-1]!=x[b][j]) {tag=0; break;}
		if (tag==1) y[a][b]=x[a][0]-i+1;
	}
}
 
int contain(int a,int b){
	if (x[a][0]<x[b][0]) return 0;
	for(int i=1;i+x[b][0]-1<=x[a][0];i++){
		int tag=1;
		for(int j=1;j<=x[b][0];j++)
			if (x[a][i+j-1]!=x[b][j]) {tag=0; break;}
		if (tag==1) return 1;
	}
	return 0;
}
 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i][0]);
		for(int j=1;j<=x[i][0];j++) scanf("%d",&x[i][j]);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if (i==j || vis[i]==1 || vis[j]==1) continue;
			if (contain(i,j)==1) vis[j]=1;
		}
	m=0;
	for(int i=1;i<=n;i++)
		if (vis[i]==0){
			m++;
			for(int k=0;k<=x[i][0];k++)
				x[m][k]=x[i][k];
		}
	n=m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if (i==j) continue;
			check(i,j);
		}
	int ans=INF;
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=n;i++) dp[1<<(i-1)][i]=x[i][0];
	for(int i=1;i<=(1<<n)-1;i++)
		for(int j=1;j<=n;j++){
			if ((i & (1<<(j-1)))==0) continue;
			for(int k=1;k<=n;k++){
				if ((i & (1<<(k-1)))!=0) continue;
				if ((LL)dp[i][j]+x[k][0]-y[j][k]>INF) continue;
				dp[i | (1<<(k-1))][k]=min(dp[i | (1<<(k-1))][k] , dp[i][j]+x[k][0]-y[j][k]);
			}
		}
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[(1<<n)-1][i]);
	printf("%d\n",ans);
	return 0;
}