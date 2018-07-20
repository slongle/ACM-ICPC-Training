#include<bits/stdc++.h>

typedef long long LL;
const int mod=1e9+7;
const int MAXN=1e6+10;

LL y[MAXN],w[MAXN],fac[MAXN],inv[MAXN];

LL power(LL a,LL b){
    LL c=1;
    while(b){
        if (b & 1) c=(c*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return c;
}

void update(LL &a,LL b){
    a=(a+b)%mod;
    if (a<0) a+=mod;
}

int main(){
    int n,m;
    std::cin>>n>>m;
    y[0]=0;
    fac[0]=1;    
    for(int i=1;i<=m+1;i++){
        y[i]=(y[i-1]+power(i,m))%mod;
        fac[i]=(fac[i-1]*i)%mod;
    }
    if (n<=m+1){
        printf("%lld\n",y[n]);
        return 0;
    }
    inv[m+1]=power(fac[m+1],mod-2);
    for(int i=m;i>=0;i--){
        inv[i]=(inv[i+1]*(i+1))%mod;
    }

    for(int i=0;i<=m+1;i++){
        w[i]=y[i];
        w[i]=(w[i]*inv[i])%mod;
        w[i]=(w[i]*inv[m+1-i])%mod;
        LL sig = (m+1-i)%2? -1LL:1LL;
        w[i]=(w[i]*sig+mod)%mod;
    }    

    LL ans=0;
    LL l=1LL;    
    LL sum=0;
    for(int i=0;i<=m+1;i++){
        l=(l*(n-i))%mod;
        sum=(sum+w[i]*power(n-i,mod-2)%mod)%mod;
    }
    ans=(sum*l%mod+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}