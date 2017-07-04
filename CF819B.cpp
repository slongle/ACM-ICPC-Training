#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e6+10;
const int MAXM=1e6;
const LL INF=1e15;
const LL mod=1e9+7;

int n,x[MAXN],y[MAXN],z[2*MAXN][2],len;
LL v[MAXN];

void link(int a,int b){
    len++; z[len][0]=b; 
    if (z[a][0]==0) z[a][1]=len;
    else z[z[a][0]][1]=len;
    z[a][0]=len;
}

int main(){
    scanf("%d",&n);
    memset(z,0,sizeof(z));
    v[0]=0; len=n+1;
    int temp=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        if (x[i]<=i) {y[i]=1; link(x[i]-i+n,i);}
        else {y[i]=-1; link(x[i]-i,i);}
        v[0]+=abs(x[i]-i);
        temp+=y[i];
    }
    int tail=n;
    for(int i=1;i<=n-1;i++){
        temp=temp-y[tail];
        v[i]=v[i-1]+temp-abs(x[tail]-n)+abs(x[tail]-1);
        
        if (x[tail]<1) y[tail]=1;
        else y[tail]=-1;
        temp+=y[tail];
        
        for(int j=z[i][1];j!=0;j=z[j][1]){
            y[z[j][0]]*=-1;
            temp+=2*y[z[j][0]];
        }
        tail--;
    }
    
    int pos=0;
    for(int i=1;i<=n-1;i++)
        if (v[i]<v[pos]) pos=i;
    printf("%I64d %d\n",v[pos],pos);
    return 0;
}
