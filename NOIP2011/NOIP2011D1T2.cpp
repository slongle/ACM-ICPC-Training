#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=200010;
const int MAXM=55;
const LL INF=1e15;
const LL mod=1e9+7;

int n,m,p,a,b,sum[MAXN][MAXM],x[MAXN][2],pos[MAXN];

int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<m;i++) sum[0][i]=0;
    for(int i=1;i<=n+1;i++){
        if (i!=n+1) scanf("%d%d",&x[i][0],&x[i][1]);
        else x[i][0]=-1;
        for(int j=0;j<m;j++)
            if (x[i][0]==j) sum[i][j]=sum[i-1][j]+1;
            else sum[i][j]=sum[i-1][j];
    }
    int temp=n+1;
    for(int i=n;i>=1;i--){
        if (x[i][1]<=p) temp=i;
        pos[i]=temp;
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        if (pos[i]==n+1) continue;
        ans+=sum[n][x[i][0]]-sum[max(pos[i]-1,i)][x[i][0]];
    }
    printf("%lld\n",ans);
    return 0;
}
