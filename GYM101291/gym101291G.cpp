#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;

char a,x[60][60];
int n,m;

int main(){
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++)
            x[i][j]=getchar();
        getchar();
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (x[j][i]!='o') continue;
            int pos=j;
            for(int k=j-1;k>=1;k--)
                if (x[k][i]!='.') break;
                else pos=k;
            swap(x[j][i],x[pos][i]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++)
			cout<<x[i][j];
        printf("\n");
    }
}