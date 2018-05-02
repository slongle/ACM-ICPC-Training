#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;

int main(){
    int a,b,c;  
    scanf("%d + %d = %d",&a,&b,&c);
    if ((LL)a+b==c) printf("YES\n");
    else printf("NO\n");
    return 0;
}