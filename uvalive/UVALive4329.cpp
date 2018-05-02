#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=20010;
const int MAXM=100010;
const LL INF=1e15;
const int mod=998244353;

struct abcd{
    int Ldown,Lup,Rdown,Rup;
}v[MAXN];

int T,n,x[MAXN],y[MAXM];
LL ans;

int lowbit(int a){
    return (a & (-a));
}

int query(int pos){
    int sum=0;
    for(int i=pos;i>0;i-=lowbit(i))
        sum+=y[i];
    return sum;
}

void update(int pos,int val){
    for(int i=pos;i<=1e5;i+=lowbit(i))
        y[i]+=val;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&x[i]);
        memset(y,0,sizeof(y));
        for(int i=1;i<=n;i++){
             v[i].Ldown=query(x[i]-1);
             v[i].Lup=i-1-v[i].Ldown;
             update(x[i],1);
        }
        memset(y,0,sizeof(y));
        for(int i=n;i>=1;i--){
             v[i].Rdown=query(x[i]-1);
             v[i].Rup=n-i-v[i].Rdown;
             update(x[i],1);
        }
        ans=0;
        for(int i=1;i<=n;i++){
            ans+=v[i].Ldown*v[i].Rup;
            ans+=v[i].Lup*v[i].Rdown;
            //printf("%d %d %d %d\n",v[i].Ldown,v[i].Lup,v[i].Rdown,v[i].Rup);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
