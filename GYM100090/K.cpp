#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=110;
const int MAXM=2e5+10;
const LL INF=1e15+7;
const LL mod=1e9+7;
 
int n;
char x[200005];
 
int main(){
    n=0;
    char ch;
    int sum=0;
    while(1){
        ch=getchar();
        if (ch=='\n') break;
        n++; x[n]=ch;
    }
    for(int i=1;i<=n;i++){
        ch=x[i];
        if (ch=='(') sum++;
        else{
            sum--;
            if (sum==-1) {printf("IMPOSSIBLE\n"); return 0;}
        }
    }
    for(int i=1;i<=n;i++) printf("%c",x[i]);
    for(int i=1;i<=sum;i++) printf(")");
    printf("\n");
    return 0;
}