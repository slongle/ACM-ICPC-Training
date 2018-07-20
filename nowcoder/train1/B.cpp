#include <bits/stdc++.h>

typedef long long LL;
const int MAXN=1e5+10;
const int MAXM=505;
const int INF=10000000;
//const int mod=1e9+7;

LL f[MAXN],g[MAXN];
int n,mod;

int main(){
    while(scanf("%d%d",&n,&mod)!=EOF){
        f[0]=1; f[1]=0; f[2]=1; f[3]=1;       
        g[0]=0; g[1]=0; g[2]=0; g[3]=1;
        for(int i=4;i<=n;i++){
            g[i]=(g[i-1]*(i-1)%mod+(((LL(i-1)*(i-2)/2)%mod)*f[i-3]%mod))%mod;
            f[i]=(f[i-2]*(i-1)%mod+g[i])%mod;
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}