#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=1e5+10;
const int MAXM=3005;
const LL INF=1e15;

int n,m,a,b;
map <int,vector<int> > A;

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        A.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            if (!A.count(a)) A[a]=vector<int>();
            A[a].push_back(i);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            if (!A.count(b) || A[b].size()<a) printf("0\n");
            else printf("%d\n",A[b][a-1]);
        }
    }
    return 0;
}
