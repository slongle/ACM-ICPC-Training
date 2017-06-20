#include <bits/stdc++.h>
using namespace std;

const int MAXN=110;
const int INF=0x3f3f3f3f;

int n,m,g[MAXN][MAXN],len,x[2*MAXN][3],ans;
string z[3];

void findrow(){
    int a;
    for(int i=1;i<=n;i++){
        a=INF;
        for(int j=1;j<=m;j++)
            a=min(a,g[i][j]);
        for(int j=1;j<=m;j++)
            g[i][j]-=a;
        if (a!=0){
            len++; ans+=a;
            x[len][0]=i;
            x[len][1]=a;
            x[len][2]=1;
        }
    }
}

void findcol(){
    int a;
    for(int j=1;j<=m;j++){
        a=INF;
        for(int i=1;i<=n;i++)
            a=min(a,g[i][j]);
        for(int i=1;i<=n;i++)
            g[i][j]-=a;
        if (a!=0){
            len++; ans+=a;
            x[len][0]=j;
            x[len][1]=a;
            x[len][2]=2;
        }
    }    
}

int check(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (g[i][j]!=0) return 0;
    return 1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
    len=0; ans=0; z[1]="row "; z[2]="col ";
    if (n<m) {findrow(); findcol();}
    else {findcol(); findrow();}
    if (check()==0) printf("-1\n");
    else{
        printf("%d\n",ans);
        for(int i=1;i<=len;i++)
            for(int j=1;j<=x[i][1];j++)
                cout<<z[x[i][2]]<<x[i][0]<<endl;
    }
    return 0;
}
