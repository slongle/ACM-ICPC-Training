#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=200010;
const int MAXM=55;
const LL INF=1e15;
const LL mod=10007;

int a,b,k,n,m;

int power(int a,int b){ //a^b
    int c=1,d=a;
    while(b>0){
        if (b%2==1) c=(c*d)%mod;
        d=(d*d)%mod;
        b/=2;
    }
    return c;
}

int frac(int a){
    if (a==1) return 1;
    int b;
    b=(-(mod/a)*frac(mod%a))%mod;
    b=(b+mod)%mod;
    return b;
}

int c(int n,int m){ //c_{n}^{m}
    int a=1;
    for(int i=1;i<=m;i++){
        a*=(n-i+1);
        a%=mod;
        a*=frac(i);
        a%=mod;
    }
    return a;
}

int main(){
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    a%=mod; b%=mod;
    int ans;
    ans=(power(a,n)*power(b,m))%mod;
    ans*=c(k,min(n,m));
    ans%=mod;
    printf("%d\n",ans);
    return 0;
}
