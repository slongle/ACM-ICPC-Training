#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
const int INF=1e9+10;

int T,P,n,x[MAXN],dp[MAXN][2],ans,lpos,rpos;

int main(){
	scanf("%d",&T); P=0;
	while(T--){	
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		dp[0][0]=-INF;
		for(int i=1;i<=n;i++)
			if (dp[i-1][0]+x[i]>=x[i]) {dp[i][0]=dp[i-1][0]+x[i]; dp[i][1]=dp[i-1][1];}
			else {dp[i][0]=x[i]; dp[i][1]=i;}
		ans=-INF; lpos=0; rpos=0;
		for(int i=1;i<=n;i++)
			if (dp[i][0]>ans) {ans=dp[i][0]; lpos=dp[i][1]; rpos=i;}
		printf("Case %d:\n",++P);
		printf("%d %d %d\n",ans,lpos,rpos);
		if (T!=0) printf("\n");
	}
	return 0;
}