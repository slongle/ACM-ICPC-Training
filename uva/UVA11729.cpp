#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1010;
const int MAXM=1e6;
const LL INF=1e15;
const LL mod=1e9+7;

struct abcd{
    int a,b;
    bool operator < (const abcd& x) const{
        return b>x.b;
    } 
}x[MAXN];

int n,m,ans;

int main(){
    m=0;
    while(scanf("%d",&n),n!=0){
        printf("Case %d: ",++m);
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i].a,&x[i].b);
        sort(x+1,x+n+1);
        ans=0;
        int t=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,t+x[i].a+x[i].b);
            t+=x[i].a;
        }
        printf("%d\n",ans);
    }
    return 0;
}
