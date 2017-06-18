#include "bits/stdc++.h"
using namespace std;

const int MAXN=1e5+10;
const int INF=1e9+10;

int T,P,n,x[MAXN],sum[MAXN],y[MAXN][2],lpos,rpos,ans,temp_ans,temp_pos;

int lowbit(int a){
    return a & (-a);
}

void update(int pos,int a){
    y[pos][0]=a; y[pos][1]=pos;
    for(int i=pos-1;i>=pos-lowbit(pos)+1;i-=lowbit(i))
        if (y[i][0]<=y[pos][0]) {y[pos][0]=y[i][0]; y[pos][1]=y[i][1];}
}

void query(int l,int r,int *ans,int *pos){
    *ans=INF; 
    for(int i=r;i>=l;i-lowbit(i)+1>=l?i-=lowbit(i):i--)
        if (y[i][0]<*ans) {*ans=y[i][0]; *pos=y[i][1];}
        else if (y[i][0]==*ans && y[i][1]<*pos) *pos=y[i][1];
}

int main(){
    scanf("%d",&T); P=0;
    while(T--){
        P++; printf("Case %d:\n",P);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&x[i]);
        sum[0]=0;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+x[i];
        for(int i=1;i<=n;i++) 
            update(i,sum[i]);
        ans=-INF; lpos=0; rpos=0;
        for(int i=1;i<=n;i++){
            if (sum[i]>ans) {ans=sum[i]; lpos=1; rpos=i;}
            else if (sum[i]==ans && 1<lpos) {lpos=1; rpos=i;}
            query(1,i-1,&temp_ans,&temp_pos);
            if (sum[i]-temp_ans>ans) {ans=sum[i]-temp_ans; rpos=i; lpos=temp_pos+1;}
            else if (sum[i]-temp_ans==ans && temp_pos+1<lpos) {lpos=temp_pos+1; rpos=i;}
        }
        printf("%d %d %d\n",ans,lpos,rpos);
        if (T!=0) printf("\n");
    }
    return 0;
}