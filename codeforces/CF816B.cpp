#include <bits/stdc++.h>
using namespace std;

const int MAXN=2*1e5+10;
const int INF=0x3f3f3f3f;

int n,t,m,a,b,x[MAXN],sum[MAXN];

int main(){
    scanf("%d%d%d",&n,&t,&m);
    memset(x,0,sizeof(x));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        x[a]+=1; x[b+1]-=1;
    }
    for(int i=1;i<=200000;i++) x[i]+=x[i-1];
    for(int i=1;i<=200000;i++) if (x[i]>=t) x[i]=1; else x[i]=0;
    sum[0]=0;
    for(int i=1;i<=200000;i++) sum[i]=sum[i-1]+x[i];
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",sum[b]-sum[a-1]);
    }
    return 0;
}
