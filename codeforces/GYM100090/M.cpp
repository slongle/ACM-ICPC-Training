#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=200010;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n,dp[MAXN],pos[MAXN],x[MAXN],y[MAXN];
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    memset(y,0,sizeof(y));
    memset(pos,0,sizeof(pos));
    for(int i=n;i>=1;i--){
        pos[i]=y[x[i]];
        y[x[i]]=i;
    }
    for(int i=1;i<=n;i++) dp[i]=INF;
    dp[1]=0;
    for(int i=1;i<=n-1;i++){
        dp[i+1]=min(dp[i]+1,dp[i+1]);
        dp[pos[i]]=min(dp[i]+1,dp[pos[i]]);
    }
    printf("%d\n",dp[n]);
    return 0;
}