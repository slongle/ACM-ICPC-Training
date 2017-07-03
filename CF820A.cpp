#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=105;
const int MAXM=1005;
const int INF=0x3f3f3f3f;

int n,a,c,l,v0,v1,last,ans;

int main(){
    scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
    ans=1; c-=v0; last=v0;
    while(c>0){
        last+=a; 
        if (last>v1) last=v1;
        c-=(last-l);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
