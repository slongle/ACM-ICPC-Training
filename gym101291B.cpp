#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

int ans[1100000],n,m,x[50],y[50],len,a;
map <int , int> aaa;

void dfs(int a,int b,int pos){
    if (a==b){
        for(int i=1;i<=n;i++)
            if (!aaa.count(a+a+x[i])) aaa[a+a+x[i]]=1,ans[++len]=a+a+x[i];
    }
    if (pos==m+1) return;
    dfs(a+y[pos],b,pos+1);
    dfs(a,b+y[pos],pos+1);
    dfs(a,b,pos+1);
}
    

int main(){
    aaa.clear();
    len=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]);
    dfs(0,0,1);
    sort(ans+1,ans+len+1);
    ans[0]=ans[1]-1;
    for(int i=1;i<=len;i++)
        if (ans[i]!=ans[i-1]) printf("%d\n",ans[i]);
    return 0;
}