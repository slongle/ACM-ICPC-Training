#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=200010;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n,x[MAXN],z[MAXN];
char y[MAXN];
 
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a*a+b*b;
    int d=a+b;
    printf("%.15f\n",(1.0*c)/(100.0*d));
    return 0;
}