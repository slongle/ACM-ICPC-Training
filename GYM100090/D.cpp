#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=1000010;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n,vis[MAXN];
LL f[MAXN];
 
LL dfs(int a){
    if (vis[a]==1) return f[a];
    vis[a]=1;
    for(int i=2;i<=a;i++){
        if (a%i==0) f[a]+=dfs(a/i);
    }
    return f[a];
}
 
int main(){
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    vis[1]=1; f[1]=1;
    LL ans=dfs(n);
    printf("%lld\n",ans);
    return 0;
}