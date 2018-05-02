#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=100010;
const int MAXM=200010;
const LL INF=1e15;
const int mod=998244353;

struct passage{
    int val,count,l,r;
}y[MAXN];

int n,m,len,a,b,st[MAXN][20],x[MAXN],ans;

int query(int a,int b){
    if (a>b) return 0;
    int c=(int)floor(log(b-a+1)/log(2));
    int d=1<<c;
    return max(st[a][c],st[b-d+1][c]);
}

void initialize(){
    for(int i=1;i<=len;i++) st[i][0]=y[i].count;
    for(int i=1;i<=20;i++)
        for(int j=1;j+(1<<i)<=len;j++)
            st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}

int main(){
    while(scanf("%d",&n),n!=0){
        scanf("%d",&m);
        a=-1; len=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&b);
            b+=1e5;
            if (b==a) y[len].count++;
            else{
                y[len].r=i-1;
                len++;
                y[len].val=x[i];
                y[len].count=1;
                y[len].l=i;
            }
            a=b;
            x[i]=len;
        }
        memset(st,0,sizeof(st));
        initialize();
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            if (x[a]==x[b]) ans=b-a+1;
            else{
                ans=max(y[x[a]].r-a+1,b-y[x[b]].l+1);
                ans=max(ans,query(x[a]+1,x[b]-1));
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
