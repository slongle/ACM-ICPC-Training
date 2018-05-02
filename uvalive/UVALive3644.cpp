#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=1e5+10;
const int MAXM=3005;
const LL INF=1e15;

int a,b,ans,fa[MAXN];

int getfa(int a){
    if (fa[a]!=a) fa[a]=getfa(fa[a]);
    return fa[a];
}

void initialize(){
    ans=0;
    for(int i=1;i<=1e5;i++) fa[i]=i;
}

int main(){
    initialize();
    while(scanf("%d",&a)!=EOF){
        if (a==-1) {printf("%d\n",ans); initialize(); continue;}
        scanf("%d",&b);
        int c,d;
        c=getfa(a); d=getfa(b);
        if (c==d) ans++;
        else fa[fa[a]]=fa[b];
    }
    return 0;
}
