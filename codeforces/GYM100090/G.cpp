#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=200010;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n,x[MAXN],z[MAXN];
char y[MAXN];
 
int main(){
    n=0;
    while(1){
        n++; y[n]=getchar(); 
        if (y[n]=='\n') {n--; break;}
    }
    if (n>26) {printf("IMPOSSIBLE\n"); return 0;}
    memset(x,0,sizeof(x));
    memset(z,0,sizeof(z));
    for(int i=1;i<=n;i++){
        int temp=y[i]-'a'+1;
        if (x[temp]==0) x[temp]=1;
        else z[i]=1;
    }
    int len=0;
    for(int i=1;i<=n;i++){
        if (z[i]==0) continue;
        for(int j=len+1;j<=26;j++)
            if (x[j]==0){
                len=j;                
                y[i]='a'+j-1;
                break;
            }
    }
    for(int i=1;i<=n;i++) printf("%c",y[i]);
    printf("\n");
    return 0;
}