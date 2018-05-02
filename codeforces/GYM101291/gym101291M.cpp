
 #include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

int dp[100][2],x[100],n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    int ans=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=1; dp[i][1]=1;
        for(int j=1;j<i;j++){
            if (x[j]>x[i]) dp[i][0]=max(dp[i][0],dp[j][1]+1);
            if (x[j]<x[i]) dp[i][1]=max(dp[i][1],dp[j][0]+1);
        }
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
    }
    printf("%d\n",ans);
    return 0;
}