#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=2510;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,sumx[MAXN][MAXN],sumy[MAXN][MAXN];
char x[MAXN][MAXN];
 
int main(){
    //int aaa;
    //scanf("%d")
    scanf("%d%d",&n,&m); getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            x[i][j]=getchar();
        getchar();
    }
    for(int i=1;i<=n;i++){
        sumx[i][0]=0;
        for(int j=1;j<=m;j++)
            if (x[i][j]=='#') sumx[i][j]=sumx[i][j-1]+1;
            else sumx[i][j]=sumx[i][j-1];
    }
    for(int i=1;i<=m;i++){
        sumy[i][0]=0;
        for(int j=1;j<=n;j++)
            if (x[j][i]=='#') sumy[i][j]=sumy[i][j-1]+1;
            else sumy[i][j]=sumy[i][j-1];
    }
    int q; scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);       
        if (a==c && b==d) {printf("YES\n"); continue;}
        if (a==c){
            if (b>d) swap(b,d);
            if (sumx[a][d]-sumx[a][b-1]==0) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        if (b==d){
            if (a>c) swap(a,c);
            if (sumy[b][c]-sumy[b][a-1]==0) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        if (a>c) {swap(a,c); swap(b,d);}
        int tag=0;
        if (b<d){
            if (sumx[a][d]-sumx[a][b-1]==0 && sumy[d][c]-sumy[d][a-1]==0) tag=1;
            if (sumx[c][d]-sumx[c][b-1]==0 && sumy[b][c]-sumy[b][a-1]==0) tag=1;
            if (tag==1) printf("YES\n");
            else printf("NO\n");
        }
        else{
            if (sumx[a][b]-sumx[a][d-1]==0 && sumy[d][c]-sumy[d][a-1]==0) tag=1;
            if (sumx[c][b]-sumx[c][d-1]==0 && sumy[b][c]-sumy[b][a-1]==0) tag=1;
            if (tag==1) printf("YES\n");
            else printf("NO\n");
        }
    }
	return 0;
}