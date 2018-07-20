#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int MAXN=7e6+10;
const int MAXM=2015;
const int INF=10000000;
const int mod=1e9+7;

LL c[MAXM][MAXM];

int main(){
    int n,m;
    for(int i=1;i<=2005;i++){
        c[i][0]=1; c[i][i]=1;
        for(int j=1;j<i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    while(scanf("%d%d",&n,&m)!=EOF){
        printf("%lld\n",((c[n+m][n]*c[n+m+2][n+1]%mod-c[n+m+1][m]*c[n+m+1][n]%mod)%mod+mod)%mod);
    }
    return 0;
}