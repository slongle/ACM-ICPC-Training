#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=505;
const int MAXM=1005;
const int INF=1e5+10;

int n,m,k,E,S,a,b,c,len,edge[MAXN+4*MAXM][3],path[MAXN],vis[MAXN],dis[MAXN][2],ans,l,r,value,num;
queue <int> T;

void initialize(){
    memset(edge,0,sizeof(edge));
    dis[0][0]=0; dis[0][1]=0;
}

void link(int a,int b,int c){
    len++;
    edge[len][0]=b; edge[len][1]=c;
    if (edge[a][0]==0) edge[a][2]=len;
    else edge[edge[a][0]][2]=len;
    edge[a][0]=len;
}

void SPFA(int st,int kind){
    int v;
    for(int i=1;i<=n;i++) dis[i][kind]=INF;
    memset(vis,0,sizeof(0));
    dis[st][kind]=0; T.push(st); vis[st]=1; path[st]=0;
    while(!T.empty()){
        v=T.front(); T.pop(); vis[v]=0;
        for(int i=edge[v][2];i!=0;i=edge[i][2])
            if (dis[edge[i][0]][kind]>dis[v][kind]+edge[i][1]) {
                dis[edge[i][0]][kind]=dis[v][kind]+edge[i][1];
                path[edge[i][0]]=v;
                if (vis[edge[i][0]]==0) {T.push(edge[i][0]); vis[edge[i][0]]=1;}
            }
    }
}

int main(){
    num=0;
    while(scanf("%d%d%d",&n,&S,&E)!=EOF){
        if (num!=0) printf("\n");
        num++;
        initialize();
        len=n;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            link(a,b,c);
            link(b,a,c);
        }
        SPFA(S,0);
        SPFA(E,1);
        ans=dis[E][0]; l=-1;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(dis[a][0]+dis[b][1]+c<ans) {ans=dis[a][0]+dis[b][1]+c; l=a; r=b; value=c;}
            if(dis[b][0]+dis[a][1]+c<ans) {ans=dis[b][0]+dis[a][1]+c; l=b; r=a; value=c;}
        }
        if(l!=-1) {link(l,r,value); link(r,l,value);}
        SPFA(E,0);
        printf("%d",S);
        for(int i=path[S];i!=0;i=path[i])
            printf(" %d",i);
        printf("\n");
        if (l==-1) printf("Ticket Not Used\n");
        else printf("%d\n",l);
        printf("%d\n",ans);
    }
    return 0;
}
