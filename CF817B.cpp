#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;

int n,x[MAXN];
long long ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    ans=1;
    for(int i=4;i<=n;i++)
        if (x[i]==x[3]) ans++;
        else break;
    if (x[1]==x[2] && x[2]==x[3]){
        ans+=2;
        ans=ans*(ans-1)*(ans-2);
        ans/=6;
    }
    if (x[1]!=x[2] && x[2]==x[3]){
        ans++;
        ans=ans*(ans-1);
        ans/=2;
    }
    printf("%lld\n",ans);
    return 0;
}
