#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=200010;
const int MAXM=1e6;
const LL INF=1e15;
const LL mod=1e9+7;

int n,x[MAXN],fact[MAXN];

LL frac(LL a){
    if (a==1) return 1;
    LL b,c,d;
    c=frac(mod%a);
    d=(mod/a)*c;
    b=(-d+((d/mod)+1)*mod)%mod;
    return b;
}

LL c(int n,int m){
    if (n-m<m) m=n-m;
    LL a=fact[n];
    a=(a*frac(fact[m]))%mod;
    a=(a*frac(fact[n-m]))%mod;
    return a;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    while (n!=1 && n%4!=0){
        int k=1;
        for(int i=1;i<n;i++){
            x[i]=((LL)x[i]+k*x[i+1]+mod)%mod;
            k*=-1;
        }
        n--;
    }
    if (n==1) {printf("%d\n",x[1]); return 0;}
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=((LL)fact[i-1]*i)%mod;
    n/=2;
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+(LL)x[i*2-1]*c(n-1,i-1))%mod;
        ans=(ans-(LL)x[i*2]*c(n-1,i-1))%mod;
        ans=(ans+((ans/mod)+1)*mod)%mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
