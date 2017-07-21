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

int n,m,t,D[MAXN],T[MAXN],A[MAXN],B[MAXN],up[MAXN],down[MAXN],arrive[MAXN],last[MAXN],sum[MAXN];

int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<n;i++) scanf("%d",&D[i]); 
    D[0]=0;
    memset(last,0,sizeof(last));
    memset(up,0,sizeof(up));
    memset(down,0,sizeof(down));
    memset(arrive,0,sizeof(arrive));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&T[i],&A[i],&B[i]);
        last[A[i]]=max(last[A[i]],T[i]);
        up[A[i]]++; down[B[i]]++;
    }
    LL ans=0;
    for(int i=1;i<=n;i++) arrive[i]=max(arrive[i-1],last[i-1])+D[i-1];
    memset(sum,0,sizeof(sum));
    for(int i=n-1;i>=1;i--) 
        if (arrive[i+1]>last[i+1]) sum[i]=sum[i+1]+down[i+1];
        else sum[i]=down[i+1];
    for(int i=1;i<=m;i++) ans+=arrive[B[i]]-T[i];
    while(t>0){
        int pos=0;
        for(int i=1;i<=n;i++) if (sum[i]>sum[pos] && D[i]>0) pos=i;
        if (pos==0) break;
        t--; ans-=sum[pos]; D[pos]--;
        for(int i=1;i<=n;i++) arrive[i]=max(arrive[i-1],last[i-1])+D[i-1];
        memset(sum,0,sizeof(sum));
        for(int i=n-1;i>=1;i--) 
            if (arrive[i+1]>last[i+1]) sum[i]=sum[i+1]+down[i+1];
            else sum[i]=down[i+1];
    }
    printf("%lld\n",ans);
    return 0;
}