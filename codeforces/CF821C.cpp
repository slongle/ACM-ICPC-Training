#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=3e5+10;

int n,ans,len,x[MAXN],y[MAXN],tail,a;
string str;

int main(){
    ans=0; len=1; tail=0;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>str;
        if(str=="add"){cin>>a; y[a]=1; x[++tail]=a;}
        else{
            if (tail==0) y[x[tail]]=0;
            else{
                if (x[tail]==len) {y[x[tail]]=0; tail--;}
                else {ans++; tail=0;}
            }
            len++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
