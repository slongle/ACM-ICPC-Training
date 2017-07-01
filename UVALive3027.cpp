#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=2e4+10;
const int MAXM=3005;
const LL INF=1e15;

int T,n,fa[MAXN],sum[MAXN],a,b;
char str[20];

void initialize(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sum[i]=0;
    }
}

void getsum(int a){
    if (fa[a]!=a){
        getsum(fa[a]);
        sum[a]+=sum[fa[a]];
        fa[a]=fa[fa[a]];
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d\n",&n);
        initialize();
        while(scanf("%s",str),str[0]!='O'){
            if (str[0]=='E') {
                scanf("%d",&a);
                getsum(a);
                printf("%d\n",sum[a]);
            }
            else{
                scanf("%d%d",&a,&b);
                fa[a]=b;
                sum[a]=abs(a-b)%1000;
            }
        }
    }
    return 0;
}
