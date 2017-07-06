#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1000010;
const int MAXM=1e6;
const LL INF=1e15;
const LL mod=1e9+7;

int n,m;
double ans;

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        ans=0;
        for(int i=1;i<n;i++){
            double pos=(double)((n+m)*i)/n;
            ans+=abs(pos-floor(pos+0.5));
        }
        ans*=10000;
        ans/=(n+m);
        printf("%.4lf\n",ans);
    }
    return 0;
}
