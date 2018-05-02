#include <bits/stdc++.h>
#define LL long long
using namespace std;

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
    for(int j=0;j<=b;j++){
            int i=(b-j)*a;
            if (check(i,j)==0) break;
            ans=max(ans,sum((LL)i,(LL)j));
        }
    cout<<ans<<endl;
    return 0;
}
