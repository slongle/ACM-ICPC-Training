#include <bits/stdc++.h>
using namespace std;

const int MAXN=55;

int n,x[MAXN][MAXN];

int main(){
    int tag=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&x[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if (x[i][j]==1) continue;
            tag=0;
            for(int s=1;s<=n;s++){
                for(int t=1;t<=n;t++)
                    if (x[i][s]+x[t][j]==x[i][j]) {tag=1; break;}
                if (tag==1) break;
            }
            if (tag==0) {printf("No\n"); return 0;}
        }
    printf("Yes\n");
    return 0;
}
