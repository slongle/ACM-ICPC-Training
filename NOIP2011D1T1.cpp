#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1000010;
const int MAXM=1e6;
const LL INF=1e15;
const LL mod=1e9+7;

int n,m,a,b,x[MAXN][4];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&x[i][0],&x[i][1],&x[i][2],&x[i][3]);
    scanf("%d%d",&a,&b);
    int ans=-1;
    for(int i=1;i<=n;i++)
        if ((x[i][0]<=a && a<=x[i][0]+x[i][2]) && (x[i][1]<=b && b<=x[i][1]+x[i][3])) ans=i;
    printf("%d\n",ans);
    return 0;
}
