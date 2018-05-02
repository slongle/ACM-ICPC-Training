
 #include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

int dp[100][2],x[100],n;

int main(){
    int a,b,c,d,e,f;
    scanf("%d%d",&a,&b);
    if (a>b) swap(a,b);
    scanf("%d%d",&c,&d);
    if (c>d) swap(c,d);
    scanf("%d%d",&e,&f);
    if (e>f) swap(e,f);
    int sum=a*b+c*d+e*f;
    int g=sqrt(sum);
    if (g*g!=sum) {printf("NO\n"); return 0;}
    if (max(max(b,d),f)!=g) {printf("NO\n"); return 0;}
    if ((a==c && c==e && a==g) || (b==d && d==f && b==g)) {printf("YES\n"); return 0;}
    if (a+c==e || a+c==f) {printf("YES\n"); return 0;}
    if (a+d==e || a+d==f) {printf("YES\n"); return 0;}
    if (b+c==e || b+c==f) {printf("YES\n"); return 0;}
    if (b+d==e || b+d==f) {printf("YES\n"); return 0;}
    
    if (a+e==c || a+f==d) {printf("YES\n"); return 0;}
    if (a+f==c || a+e==d) {printf("YES\n"); return 0;}
    if (b+e==c || b+e==d) {printf("YES\n"); return 0;}
    if (b+f==c || b+f==d) {printf("YES\n"); return 0;}
    
    if (c+e==a || c+f==b) {printf("YES\n"); return 0;}
    if (c+f==a || c+e==b) {printf("YES\n"); return 0;}
    if (d+e==a || d+e==b) {printf("YES\n"); return 0;}
    if (d+f==a || d+f==b) {printf("YES\n"); return 0;}
    printf("NO\n");
    return 0;
}