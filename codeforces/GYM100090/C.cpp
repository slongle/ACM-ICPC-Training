#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=305;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n;
LL x[MAXN][MAXN],y[MAXN][MAXN];
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&x[i][j]);
    memcpy(y,x,sizeof(x));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                x[i][j]=min(x[i][j],x[i][k]+x[k][j]);    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (x[i][j]!=y[i][j]) {printf("-1\n"); return 0;} 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",x[i][j]);
        printf("\n");
    }
    return 0;
}