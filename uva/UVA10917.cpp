#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=1005;
const int MAXM=1e6+5;
const int INF=0x3f3f3f3f;

int n,m,len,edge[MAXN+2*MAXM][3],dis[MAXN],vis[MAXN],x[MAXM][3],f[MAXN],a,b,c;
queue <int> T;

void initialize(){
    memset(edge,0,sizeof(edge));
}

void link(int a,int b,int c){
    len++;
    edge[len][0]=b; edge[len][1]=c;
    if(edge[a][2]==0) edge[a][2]=len;
    else edge[edge[a][0]][2]=len;
    edge[a][0]=len;
}

void SPFA(int st){
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[st]=0; vis[st]=1; T.push(st);
    while(!T.empty()){
        int v=T.front(); T.pop(); vis[v]=0;
        for(int i=edge[v][2];i!=0;i=edge[i][2])
            if (dis[edge[i][0]]>dis[v]+edge[i][1]){
                dis[edge[i][0]]=dis[v]+edge[i][1];
                if (vis[edge[i][0]]==0) {T.push(edge[i][0]); vis[edge[i][0]]=1;}
            }
    }
}

void dfs(int a){
    vis[a]=0;
    for(int i=edge[a][2];i!=0;i=edge[i][2]){
        if (vis[edge[i][0]]==0) dfs(edge[i][0]);
        f[a]+=f[edge[i][0]];
    }
    vis[a]=1;
}

int main(){
    while(scanf("%d",&n),n!=0){
        scanf("%d",&m);
        len=n;
        initialize();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            x[i][0]=a; x[i][1]=b; x[i][2]=c;
            link(a,b,c);
            link(b,a,c);
        }
        SPFA(2);
        initialize();
        for(int i=1;i<=m;i++){
            if (dis[x[i][0]]>dis[x[i][1]]) link(x[i][1],x[i][0],x[i][2]);
            if (dis[x[i][0]]<dis[x[i][1]]) link(x[i][0],x[i][1],x[i][2]);
        }
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        f[1]=1;
        dfs(2);
        printf("%d\n",f[2]);
    }
    return 0;
}
