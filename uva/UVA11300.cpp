#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1000010;
const int MAXM=1e6;
const LL INF=1e15;
const LL mod=1e9+7;

int n;
LL sum,ans,x[MAXN],y[MAXN];

int main(){
    while(scanf("%d",&n)!=EOF){
        sum=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            sum+=x[i];
        }
        sum/=n; y[1]=0;
        for(int i=2;i<=n;i++){
            x[i]-=sum;           
            y[i]=y[i-1]+x[i];
        }
        sort(y+1,y+n+1);
        ans=0;
        for(int i=1;i<=n;i++)
            ans+=abs(-y[n/2]+y[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
