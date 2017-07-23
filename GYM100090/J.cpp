#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=200010;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n,x[2*MAXN][3],pos,q,len;
 
int main(){
    scanf("%d%d",&n,&pos);
    len=0;
    int a; scanf("%d",&a);
    len++; x[len][0]=a; x[len][1]=-INF; x[len][2]=INF;
    for(int i=2;i<=n;i++){
        scanf("%d",&a);
        len++; x[len][0]=a; 
        x[len][1]=len-1; x[len][2]=INF;
        x[len-1][2]=len;
    }
    scanf("%d",&q);
    char b[15];
    while(q--){
        scanf("%s",&b);
        if (b[0]=='p') {printf("%d\n",x[pos][0]); continue;}
        if (b[4]=='L' && x[pos][1]!=-INF) {pos=x[pos][1]; continue;}
        if (b[4]=='R' && x[pos][2]!=INF) {pos=x[pos][2]; continue;}
        if (b[6]=='L'){
            scanf("%d",&a);
            len++; x[len][0]=a; x[len][1]=x[pos][1]; x[len][2]=pos;
            if (x[pos][1]!=-INF) x[x[pos][1]][2]=len;
            x[pos][1]=len; 
            continue;
        }
        if (b[6]=='R'){
            scanf("%d",&a);
            len++; x[len][0]=a; x[len][1]=pos; x[len][2]=x[pos][2];
            if (x[pos][2]!=INF) x[x[pos][2]][1]=len; 
            x[pos][2]=len;
            continue;
        }
    }
    return 0;
}