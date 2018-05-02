#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=105;
const int MAXM=1005;
const LL INF=1e11;

int n,m,len,edge[MAXN+2*MAXM][5],a,b,c,vis[MAXN],path[MAXN],x[MAXN];
LL ans[MAXM],dis[MAXN],sum[MAXM],L;
queue <int> T;

void initialize(){
    len=n;
    memset(edge,0,sizeof(edge));
    memset(ans,0,sizeof(ans));
}

void link(int a,int b,int c){
    len++;
    edge[len][0]=b; edge[len][1]=c; edge[len][4]=a;
    if (edge[a][0]==0) edge[a][2]=len;
    else edge[edge[a][0]][2]=len;
    edge[a][0]=len;
}

LL SPFA(int st){
    int v;
    for(int i=1;i<=n;i++) dis[i]=INF,vis[i]=0,path[i]=0;
    dis[st]=0; vis[st]=1; T.push(st);
    while(!T.empty()){
        v=T.front(); T.pop(); vis[v]=0;
        for(int i=edge[v][2];i!=0;i=edge[i][2]){
            if (edge[i][3]==1) continue;
            if (dis[edge[i][0]]>dis[v]+(LL)edge[i][1]){
                dis[edge[i][0]]=dis[v]+(LL)edge[i][1];
                path[edge[i][0]]=v;
                if (vis[edge[i][0]]==0) {T.push(edge[i][0]); vis[edge[i][0]]=1;}
            }
        }
    }
    LL tot=0;
    for(int i=1;i<=n;i++)
        if (dis[i]==INF) tot+=L;
        else tot+=dis[i];
    return tot;
}

int main(){
    while(scanf("%d%d%lld",&n,&m,&L)!=EOF){
        initialize();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            link(a,b,c);
            link(b,a,c);
        }
        for(int i=1;i<=n;i++){
            sum[0]=SPFA(i);
            for(int j=1;j<=n;j++) x[j]=path[j];
            for(int j=n+1;j<=len;j+=2){
                int k=(j-n+1)/2;
                edge[j][3]=1; edge[j+1][3]=1;
                if (x[edge[j][0]]!=edge[j][4] && x[edge[j][4]]!=edge[j][0]) sum[k]=sum[0];
                else sum[k]=SPFA(i);
                edge[j][3]=0; edge[j+1][3]=0;
            }
            for(int j=0;j<=m;j++) ans[j]+=sum[j];
        }
        for(int i=2;i<=m;i++) ans[i]=max(ans[i],ans[i-1]);
        printf("%lld %lld\n",ans[0],ans[m]);
    }
    return 0;
}
