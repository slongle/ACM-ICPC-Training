#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

int dp[100],x[100],n;
char ch;

int main(){
    n=0;
    while((ch=getchar())!=EOF){
        int a=ch-'a'+1;
        if (a<=0 || a>26) break;
        n++; x[n]=a;
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++)
            if (x[j]<x[i]) dp[i]=max(dp[i],dp[j]+1);
        ans=max(dp[i],ans);
    }
    ans=26-ans;
    printf("%d\n",ans);
    return 0;
}