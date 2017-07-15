#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long LL;
const int MAXN=110;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;

int dp[MAXN][MAXN],n,m;
char x[MAXN],y[MAXN];

int main(){
	while(scanf("%s %s",x+1,y+1)!=EOF){
		getchar();
		n=strlen(x+1); m=strlen(y+1);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if (x[i]==y[j]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		int ans=n+m-dp[n][m];
		printf("%d\n",ans);
	}
	return 0;
}