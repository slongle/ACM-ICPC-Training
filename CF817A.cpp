#include <bits/stdc++.h>
using namespace std;

const int MAXN=2*1e5+10;
const int INF=0x3f3f3f3f;

int xx,yy,xxx,yyy,a,b,detx,dety;

int main(){
    scanf("%d%d%d%d",&xx,&yy,&xxx,&yyy);
    scanf("%d%d",&a,&b);
    detx=abs(xx-xxx);
    dety=abs(yy-yyy);
    if(detx%(2*a)==0 && dety%(2*b)==0) {cout<<"YES"<<endl; return 0;}
    if((detx-a)%(2*a)==0 && (dety-b)%(2*b)==0) {cout<<"YES"<<endl; return 0;}
    cout<<"NO"<<endl;
    return 0;
}
