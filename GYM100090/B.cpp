#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=200015;                

struct Point{
    LL x,y;
    Point(LL x=0,LL y=0):x(x),y(y) {}
}A[MAXN];

typedef Point Vector;

Vector operator - (Point a,Point b) {return Vector(a.x-b.x,a.y-b.y);}
LL Cross (Vector a,Vector b) {return (a.x*b.y-a.y*b.x);}
    
int n;
LL s[MAXN];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&A[i].x,&A[i].y);
    
    s[1]=0;
    for(int i=2;i<=n;i++) s[i]=s[i-1]+Cross(A[i-1],A[i]);
    LL sum=abs(s[n]+Cross(A[n],A[1]));
    
    int ansl,ansr,r=3;
    LL ans=sum,sum1;
    for(int i=1;i<n-1;i++){
        for(int j=r;j<=n;j++){
            sum1=abs(-s[i]+s[j]+Cross(A[j],A[i]));
            if (abs(2*sum1-sum)<ans){
                ansl=i; ansr=j; ans=abs(2*sum1-sum);
            }           
            r=j+1;
            if (2*sum1>sum) {r--; break;}
        }
    }
    printf("%d %d\n",ansl,ansr);
    return 0;
}