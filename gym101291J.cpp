#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1100;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

struct Node{
    int pos,val;
    bool operator < (const Node &a)   const{
        return pos>a.pos;
    }
}x[MAXN];

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i].pos,&x[i].val);
    sort(x+1,x+1+n);
    LL ans=0;
    for(int i=1;i<=n;i++){
        if (x[i].pos<=0) break;
        if (x[i].val==0) continue;
        if (x[i].val<0){
            if (x[i+1].pos>0) x[i+1].val+=x[i].val;
            continue;
        }
        LL num=x[i].val/m;
        if (num*m==x[i].val) ans+=num*2*x[i].pos;
        if (num*m<x[i].val){
            ans+=(num+1)*2*x[i].pos;
            if (x[i+1].pos>0) x[i+1].val-=((num+1)*m-x[i].val);
        }
    }
    for(int i=n;i>=1;i--){
        if (x[i].pos>=0) break;
        if (x[i].val==0) continue;
        if (x[i].val<0){
            if (x[i-1].pos<0) x[i-1].val+=x[i].val;
            continue;
        }
        x[i].pos*=-1;
        LL num=x[i].val/m;
        if (num*m==x[i].val) ans+=num*2*x[i].pos;
        if (num*m<x[i].val){
            ans+=(num+1)*2*x[i].pos;
            if (x[i-1].pos<0) x[i-1].val-=((num+1)*m-x[i].val);
        }
    }
    cout<<ans<<endl;
    return 0;
}