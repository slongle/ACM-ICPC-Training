#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1100;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

int x[MAXN],n;

int main(){
    LL sum=0;
    scanf("%d",&n);
    int mm=1;
    for(int i=1;i<=n;i++) scanf("%d",&x[i]),sum+=x[i],mm=max(mm,x[i]);
    if (sum-mm<mm) printf("%lld\n",sum-mm);
    else printf("%lld\n",sum/2);
    return 0;
}