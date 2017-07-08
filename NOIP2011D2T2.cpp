#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=200010;
const int MAXM=55;
const LL INF=1e17;
const LL mod=10007;

int n,m,x[MAXN][2],y[MAXN][2];
LL sum[MAXN][2],S;

LL check(int w){
    sum[0][0]=0; sum[0][1]=0;
    for(int i=1;i<=n;i++)
        if (x[i][0]>=w) {sum[i][0]=sum[i-1][0]+1; sum[i][1]=sum[i-1][1]+x[i][1];}
        else {sum[i][0]=sum[i-1][0]; sum[i][1]=sum[i-1][1];}
    LL SUM=0;
    for(int i=1;i<=m;i++){
        int l=y[i][0],r=y[i][1];
        SUM+=(sum[r][0]-sum[l-1][0])*(sum[r][1]-sum[l-1][1]);
    }
    return SUM;
}

int main(){
    scanf("%d%d%lld",&n,&m,&S);
    int R=0,L=0,M;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i][0],&x[i][1]);
        R=max(R,x[i][1]+1);
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d",&y[i][0],&y[i][1]);
    LL ans=abs(check(0)-S);
    while(L<=R){
        M=(L+R)/2;
        LL temp=check(M);
        ans=min(ans,abs(temp-S));        
        if (temp<=S) R=M-1;
        else L=M+1;
    }
    printf("%lld\n",ans);
    return 0;
}
