#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1010;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;

char ch,x[1000000];
int ans[100000][2],len,a,b,c,d;

void calc(int t){
    int a=0,b=0;
    for(int i=1;i<=len;i++){
        char ch=x[i];
        if (ch!='W' && ch!='L') continue;
        if (ch=='W') a++;
        else b++;
        if (max(a,b)>=t && abs(a-b)>=2) {printf("%d:%d\n",a,b); a=0; b=0;}
    }
    printf("%d:%d\n",a,b);
}
        
int main(){
    a=0; b=0; c=0; d=0; len=0;
    while(x[++len]=getchar(),x[len]!='E');
    calc(11);
    cout<<endl;
    calc(21);
    return 0;
}
