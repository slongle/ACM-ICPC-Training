#include <bits/stdc++.h>
using namespace std;

const int MAXN=5010;
const int INF=0x3f3f3f3f;

int n,m,size[MAXN],a,edge[2*MAXN][2],len,ans,c[MAXN],d[MAXN],sum;
long long dp[MAXN][MAXN][2];

void insert_edge(int a,int b){
    edge[++len][0]=b;
    if (edge[a][1]==0) edge[a][1]=len;
    else edge[edge[a][0]][1]=len;    
    edge[a][0]=len;
}

void Tree_DP(int pos){
    size[pos]=1;
    dp[pos][0][0]=0;
    dp[pos][1][0]=c[pos];
    dp[pos][1][1]=c[pos]-d[pos];
    for(int i=edge[pos][1];i!=0;i=edge[i][1]){
        Tree_DP(edge[i][0]);
        for(int j=size[pos];j>=0;j--)
            for(int k=0;k<=size[edge[i][0]];k++){
                dp[pos][j+k][0]=min(dp[pos][j+k][0],dp[pos][j][0]+dp[edge[i][0]][k][0]);
                dp[pos][j+k][1]=min(dp[pos][j+k][1],dp[pos][j][1]+min(dp[edge[i][0]][k][0],dp[edge[i][0]][k][1]));
            }
        size[pos]+=size[edge[i][0]];
    }
}

int main(){
    memset(edge,0,sizeof(edge)); 
    scanf("%d%d",&n,&m); len=n;
    scanf("%d%d",&c[1],&d[1]);
    for(int i=2;i<=n;i++){
        scanf("%d%d%d",&c[i],&d[i],&a);
        insert_edge(a,i);
    }
    memset(dp,INF,sizeof(dp));
    sum=0;
    Tree_DP(1);
    ans=0;
    for(int i=0;i<=size[1];i++)
        if (dp[1][i][0]<=m || dp[1][i][1]<=m) ans=i;
    cout<<ans<<endl;
    return 0;
}
