#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=110;
const int MAXM=2e5+10;
const LL INF=1e15+7;
const LL mod=1e9+7;
 
int n;
LL x[200005];
 
int main(){
    scanf("%d",&n);    
    LL b=0,a;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        printf("%lld ",a-b);
        b=a;
    }
    printf("\n");
    return 0;
}