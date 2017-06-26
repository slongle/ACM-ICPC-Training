#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=55;

int a,b;
LL ans;

int check(int x,int y){
    if (-x+a*b<a*y) return 0;
    else return 1;
}

LL sum(LL x,LL y){
    return ((x+1)*(x+y)*(y+1))/2;
}

int main(){
    ans=0;
    scanf("%d%d",&a,&b);
    for(int i=0;i<=a*b;i++){
            if (i%a!=0) continue;
            int j=(-i)/a+b;
            if (check(i,j)==0) break;
            ans=max(ans,sum((LL)i,(LL)j));
        }
    cout<<ans<<endl;
    return 0;
}
