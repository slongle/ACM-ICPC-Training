#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=60;
const int MAXM=1005;
const LL INF=1e15;

int n,m,t,path[MAXN],vis[MAXN],c,d,S,E,ans[MAXN];
LL edge[MAXN][MAXN],dis[MAXN];
char a,b;
queue <int> T;

void initialize(){
    memset(edge,0,sizeof(edge));
    for(int i=1;i<=MAXN;i++) dis[i]=INF;
}

int num(char ch){
    if (1<=ch-'a'+1 && ch-'a'+1<=26) return (ch-'a'+27);
    else return (ch-'A'+1);
}

char cha(int a){
    if (a>26) return ('a'+a-27);
    else return ('A'+a-1);
}

LL cost(int b,LL a){
    if (b>26) return a+1;
    return (LL)ceil((double)(a*20)/(double)19);
}

void SPFA(int S){
    memset(path,0,sizeof(path));
    memset(vis,0,sizeof(vis));
    vis[S]=1; T.push(S);
    while(!T.empty()){
        int v=T.front(); T.pop(); vis[v]=0;
        for(int i=1;i<=52;i++){
            if (edge[v][i]==0) continue;
            if (dis[i]>cost(v,dis[v])){
                dis[i]=cost(v,dis[v]);
                path[i]=v;
                if (vis[i]==0) {vis[i]=1; T.push(i);}
            }
        }
    }
}

int main(){
    t=0;
    while(scanf("\n%d",&m),t++,m!=-1){
        initialize();
        for(int i=1;i<=m;i++){
            scanf("\n%c %c",&a,&b);
            edge[num(a)][num(b)]=1;
            edge[num(b)][num(a)]=1;
        }
        scanf("\n%d %c %c",&c,&a,&b);
        S=num(a); E=num(b); dis[E]=c;
        SPFA(E);
        ans[0]=0;
        printf("Case %d:\n",t);
        if (a==b) {printf("%d\n%c\n",c,a);continue;}
        printf("%lld\n",dis[S]);
        printf("%c-",a);
        for(int i=path[S];path[i]!=0;i=path[i])
            printf("%c-",cha(i));
        printf("%c\n",b);
    }
    return 0;
}
