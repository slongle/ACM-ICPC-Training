#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=60;
const int MAXM=3005;
const LL INF=1e15;

int t,n,m,a,b,c,len,edge[MAXN+MAXM][3],num[MAXN],vis[MAXN];
double L,R,M,ans,dis[MAXM];
queue <int> T;

void initialize(){
    memset(edge,0,sizeof(edge));
    len=n;
    L=0; R=0;
}

void link(int a,int b,int c){
    len++;
    edge[len][0]=b; edge[len][1]=c;
    if (edge[a][2]==0) edge[a][2]=len;
    else edge[edge[a][0]][2]=len;
    edge[a][0]=len;
}

int SPFA(int S,double val){
    dis[S]=0; T.push(S); vis[S]=1; num[S]=1;
    while(!T.empty()){
        int v=T.front(); T.pop(); vis[v]=0;
        for(int i=edge[v][2];i!=0;i=edge[i][2]){
            if (dis[edge[i][0]]>dis[v]+(double)edge[i][1]-val){
                dis[edge[i][0]]=dis[v]+(double)edge[i][1]-val;
                if (vis[edge[i][0]]==0){
                    vis[edge[i][0]]=1;
                    num[edge[i][0]]++;
                    if (num[edge[i][0]]>n-1) return 1;
                    T.push(edge[i][0]);
                }
            }
        }
    }
    return 0;
}

int check(double val){
    int a;
    for(int i=1;i<=n;i++) dis[i]=(double)INF,vis[i]=0,num[i]=0;
    for(int i=1;i<=n;i++){
        if (num[i]==0) a=SPFA(i,val);
        if (a==1) return 1;
    }
    return 0;
}

int main(){
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d",&n,&m);
        initialize();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            link(a,b,c);
            R=max(R,(double)c);
        }
        printf("Case #%d: ",cas);
        if (check(R+1)==0) printf("No cycle found.\n");
        else{
            while(R-L>1e-3){
                M=(L+R)/2;
                if (check(M)==1) R=M;
                else L=M;
            }
            printf("%.2f\n",L);
        }
    }
    return 0;
}
