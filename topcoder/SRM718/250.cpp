#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=2510;
const int MAXM=2e5+10;
const LL INF=1e15+7;
const LL mod=1e9+7;

int n,m,dp[MAXN][MAXN],sumx[MAXN],sumy[MAXN];

class InterleavingParenthesis{
    public:
    int countWays(string x,string y){
        n=x.length(); m=y.length();
        sumx[0]=0; sumy[0]=0;
        for(int i=1;i<=n;i++) if (x[i-1]=='(') sumx[i]=sumx[i-1]+1; else sumx[i]=sumx[i-1]-1;
        for(int i=1;i<=m;i++) if (y[i-1]=='(') sumy[i]=sumy[i-1]+1; else sumy[i]=sumy[i-1]-1;
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++){
                if (i==0 && j==0) continue;  
                dp[i][j]=0;
                if (i) dp[i][j]=dp[i-1][j];
                if (j) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                if (sumx[i]+sumy[j]<0) dp[i][j]=0;
            }
        if (sumx[n]+sumy[m]!=0) return 0;
        else return dp[n][m];
    }
};


int main(){
    string x,y;
    cin>>x; cin>>y;
    InterleavingParenthesis test;
    cout<<test.countWays(x,y)<<endl;
    return 0;
}