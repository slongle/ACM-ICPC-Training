#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e6+10;
const int MAXM=1e6;
const LL INF=1e15;
const LL mod=1e9+7;

int n,m,x[MAXN],y[MAXN];

int main(){
    while(scanf("%d%d",&n,&m),n!=0 || m!=0){
        for(int i=1;i<=n;i++) scanf("%d",&x[i]);
        for(int i=1;i<=m;i++) scanf("%d",&y[i]);
        sort(x+1,x+n+1);
        sort(y+1,y+m+1);
        int a=1,ans=0;
        for(int i=1;i<=n;i++){
            if (a==m+1) {ans=-1; break;}
            for(int j=a;j<=m;j++)
                if (y[j]>=x[i]) {ans+=y[j]; a=j+1; break;}
        }
        if (ans==-1) printf("Loowater is doomed!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
