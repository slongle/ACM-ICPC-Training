#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};


char a;
int n,m,x[60][60],vis[60][60];

void dfs(int a,int b){
    vis[a][b]=1;
    for(int i=0;i<4;i++){
        int xx=a+dx[i],yy=b+dy[i];
        if (xx<1 || xx>n || yy<1 || yy>m) continue;
        if (vis[xx][yy]==1) continue;
        if (x[xx][yy]==3) continue;
        dfs(xx,yy);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a=getchar();
            if (a=='L') x[i][j]=1;
            if (a=='C') x[i][j]=2;
            if (a=='W') x[i][j]=3;
        }
        getchar();
    }
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (x[i][j]==1 && vis[i][j]==0) {ans++; dfs(i,j);}
    printf("%d\n",ans);
}