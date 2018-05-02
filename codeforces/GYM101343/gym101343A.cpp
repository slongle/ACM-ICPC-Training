#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1e4+10;
const int MAXM=1e5;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,k,q,p;

int gcd(int a,int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}

int frac(int a){
    if (a==1) return 1;
    LL b=(-(LL)(mod/a)*frac(mod%a))%mod;
    b=(b+mod)%mod;
    return (int)b;
}

int main(){
    scanf("%d%d%d%d.%d",&m,&n,&k,&q,&p);
    if (n>m || k>n) {printf("0\n"); return 0;}
    LL a=1;
    for(int i=1;i<=k-1;i++)
        a=(((a*(n-i))%mod)*frac(i))%mod;
    if (q==1) p=1000;
    int b=p,c=1000-b,d=1000;
    LL bb=1,cc=1,dd=1;
    for(int i=1;i<=n;i++){
        if (i<=k) bb=(bb*b)%mod;
        if (i<=n-k) cc=(cc*c)%mod;
        dd=(dd*d)%mod;
    }
    dd=(LL)frac((int)dd);
    LL ans=dd;
    ans=(ans*a)%mod;
    ans=(ans*bb)%mod;
    ans=(ans*cc)%mod;
    ans%=mod;
    printf("%lld\n",ans);
	return 0;
}